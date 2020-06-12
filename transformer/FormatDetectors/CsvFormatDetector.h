#pragma once

#include <vector>

#include "IFormatDetector.h"

namespace FormatTransformation
{
    class CsvFormatDetector : public IFormatDetector
    {
    public:
        CsvFormatDetector();
        virtual ~CsvFormatDetector();

        virtual DataFormat detect(const std::string& dataChunk) override;

        virtual DataFormat getFormat() const override;

        virtual bool detected() override;
        virtual std::vector<std::string> getCache() override;
        virtual void reset() override;

    private:
        DataFormat m_detectedFormat;
        std::vector<std::string> m_dataChunkCache;
    };
}