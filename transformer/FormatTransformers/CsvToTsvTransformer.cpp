#include <sstream>
#include <iostream>

#include "../utils.h"
#include "CsvToTsvTransformer.h"

namespace FormatTransformation
{
    CsvToTsvTransformer::CsvToTsvTransformer() 
    { }
    
    CsvToTsvTransformer::~CsvToTsvTransformer() 
    { }

    std::vector<std::string> CsvToTsvTransformer::transform
        (const std::vector<std::string>& logicalPackets)
    {
        std::vector<std::string> result;
        for(const auto & packet : logicalPackets)
        {
            std::vector<std::string> parts = Utils::split(packet, ",");
            std::stringstream joinedPartsStream;
            for(int i=0; i<parts.size(); i++)
            {
                joinedPartsStream << parts[i] << ((i+1) != parts.size() ? "\t" : "");
            }
            result.push_back(joinedPartsStream.str());
        }
        return result;
    }
}