#pragma once

#include <vector>
#include <string>

#include "IFormatTransformer.h"

namespace FormatTransformation
{
    class CsvToTsvTransformer : public IFormatTransformer
    {
    public:
        CsvToTsvTransformer();
        virtual ~CsvToTsvTransformer();

        virtual std::vector<std::string> transform(const std::vector<std::string>& logicalPackets) override;
    };
}