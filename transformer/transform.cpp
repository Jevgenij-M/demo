#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "FormatDetectors/FormatDetector.h"
#include "DataIntegrators/DataIntegrators.h"
#include "DataIntegrators/DataAccumulator.h"
#include "FormatTransformers/FormatTransformers.h"

void read(std::istream& inputStream, std::ostream& outputStream, const std::string& outputFileName)
{
    using namespace FormatTransformation; 

    std::string line;
    FormatDetector detector;
    DataAccumulator accumulator;

    // Should be initialized on data type detection
    std::shared_ptr<IDataIntegrator> integrator(nullptr);
    std::shared_ptr<IFormatTransformer> transformer(nullptr);
    
    bool imediatelyAfterDetection = false;
    DataFormat inputFormat = DataFormat::Unknown;
    DataFormat outputFormat = DataFormat::Unknown;

    while(std::getline(inputStream, line))
    {
        // Format Detection 
        if(!detector.detected())
        {
            detector.detect(line);
            accumulator.integrate(line);
            imediatelyAfterDetection = detector.detected();
            continue;
        } 
        

        // Logical packet integrator
        //     returns vector of packets or empty vector if packet not yet integrated
        if(imediatelyAfterDetection)
        {
            imediatelyAfterDetection = false;
            inputFormat = detector.getFormat();
            outputFormat = getFormatFromExtension(Utils::getFileNameExtension(outputFileName));

            std::cout << "detected " << getExtensionFromFormat(inputFormat) << "    "
                                     << getExtensionFromFormat(outputFormat) << std::endl;

            integrator = DataIntegrator(inputFormat); 
            transformer = FormatTransformer(inputFormat, outputFormat); 

            if(!integrator) 
            {
                std::cout << "ERROR: no DataIntegrator found for " << getExtensionFromFormat(inputFormat) << std::endl;
            }
            if(!transformer)
            {
                std::cout   << "ERROR: no FormatTransformer found for " 
                            << getExtensionFromFormat(inputFormat) << ", " 
                            << getExtensionFromFormat(outputFormat) << std::endl;
            }

            auto accumulatedData = accumulator.takeLogicalPackets();
            for(const auto & line : accumulatedData)
                integrator->integrate(line);
        }

        std::vector<std::string> logicalPackets {};
        if(integrator->integrate(line))
        {
            logicalPackets = integrator->takeLogicalPackets();
        }
        else 
        {
            continue;
        }
        
  
        // Transforms Logical packets 
        std::vector<std::string> transformedPackets {}; 
        if (!logicalPackets.empty())
            transformedPackets = transformer->transform(logicalPackets);


        // Writes Transformed Packet to output stream
        for(const auto & packet : transformedPackets)
            outputStream << packet << std::endl; 
    }
}

int main(int argc, char *argv[])
{
    //input_file_name output_file_name.ext  
    if (argc < 3)
    {
        std::cout << "transfom input_file_name output_file_name.ext" << std::endl;
        return 0;
    }

    std::string inputFileName  = argv[1];
    std::string outputFileName = argv[2];

    std::ifstream ifs;
    ifs.open(inputFileName);
    if(!ifs.is_open())
        std::cout << "unable to open input file: " << inputFileName << std::endl;

    std::ofstream ofs;
    ofs.open(outputFileName);
    if(!ofs.is_open())
        std::cout << "unable to open output file: " << outputFileName << std::endl;

    read(ifs, ofs, outputFileName);

    ifs.close();
    ofs.close();

    return 0;
}