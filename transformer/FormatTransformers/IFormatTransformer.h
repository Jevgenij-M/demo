#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "../utils.h"

namespace FormatTransformation
{
    class IFormatTransformer
    {
    public:
        IFormatTransformer() {}
        virtual ~IFormatTransformer() {}

        virtual std::vector<std::string> transform(const std::vector<std::string>& logicalPackets) = 0;
    };
}