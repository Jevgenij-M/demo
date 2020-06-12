#pragma once

#include <vector>
#include <map>
#include <string>
#include <memory>

#include "IFormatDetector.h"

namespace FormatTransformation
{
    class FormatDetector : public IFormatDetector
    {
    public:
        FormatDetector();

        virtual DataFormat detect(const std::string& dataChunk) override;
        virtual DataFormat getFormat() const override;
        virtual bool detected() override;
        virtual std::vector<std::string> getCache() override;
        virtual void reset() override;

    private:
        DataFormat m_detectedFormat;
        std::map<DataFormat, std::unique_ptr<IFormatDetector>> m_formatDetectors;
    };
}