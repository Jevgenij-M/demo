#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "../utils.h"
#include "IFormatTransformer.h"

namespace FormatTransformation
{
    class TsvToCsvTransformer : public IFormatTransformer
    {
    public:
        TsvToCsvTransformer();
        virtual ~TsvToCsvTransformer();

        virtual std::vector<std::string> transform(const std::vector<std::string>& logicalPackets) override;
    };
}