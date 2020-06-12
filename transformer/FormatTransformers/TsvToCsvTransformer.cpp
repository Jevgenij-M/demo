#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "../utils.h"
#include "TsvToCsvTransformer.h"

namespace FormatTransformation
{
    TsvToCsvTransformer::TsvToCsvTransformer() 
    { }
    
    TsvToCsvTransformer::~TsvToCsvTransformer() 
    { }

    std::vector<std::string> TsvToCsvTransformer::transform(const std::vector<std::string>& logicalPackets)
    {
        std::vector<std::string> result;

        for(const auto & packet : logicalPackets)
        {
            std::vector<std::string> parts = Utils::split(packet, "\t");
            std::stringstream joinedPartsStream;

            for(int i=0; i<parts.size(); i++)
            {
                joinedPartsStream << parts[i] << ((i+1) != parts.size() ? "," : "");
            }

            result.push_back(joinedPartsStream.str());
        }

        return result;
    }
}