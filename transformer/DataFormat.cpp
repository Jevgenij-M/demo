#include "DataFormat.h"

#include <algorithm>

namespace FormatTransformation
{
    // bimap would be better to use
    const std::map<DataFormat, std::string> DataFormatExtensions {
        {DataFormat::Unknown, ""    },
        {DataFormat::CSV    , "CSV" },
        {DataFormat::TSV    , "TSV" }
    };

    DataFormat getFormatFromExtension(const std::string & extension)
    {
        std::string extUpperCase = extension;
        std::transform(extension.begin(), extension.end(),extUpperCase.begin(), ::toupper);

        for(const auto & pair : DataFormatExtensions)
        {
            if(pair.second == extUpperCase)
                return pair.first;
        }

        return DataFormat::Unknown;
    }

    std::string getExtensionFromFormat(const DataFormat dataFormat)
    {
        const auto extension = DataFormatExtensions.find(dataFormat);
        if(extension != DataFormatExtensions.end())
            return extension->second;
        
        return "";
    }
}