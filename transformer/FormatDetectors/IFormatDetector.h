#pragma once

#include <vector>
#include <string>

#include "../DataFormat.h"

namespace FormatTransformation
{
    class IFormatDetector
    {
    public:
        IFormatDetector() {}
        virtual ~IFormatDetector() {}

        virtual DataFormat detect(const std::string& dataChunk) = 0;
        virtual DataFormat getFormat() const = 0;
        virtual bool detected() = 0;
        virtual void reset() = 0;

        virtual std::vector<std::string> getCache() = 0;
    };
}