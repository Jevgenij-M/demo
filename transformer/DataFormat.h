#pragma once 

#include <map>

namespace FormatTransformation
{
    enum class DataFormat
    {
        Unknown,
        CSV,
        TSV
    };

    DataFormat getFormatFromExtension(const std::string & extension);

    std::string getExtensionFromFormat(const DataFormat dataFormat);
}