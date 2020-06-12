#include <algorithm>

#include "TsvFormatDetector.h"

#include "../utils.h"

namespace FormatTransformation
{
    TsvFormatDetector::TsvFormatDetector()
    : m_detectedFormat(DataFormat::Unknown)
    , m_dataChunkCache()
    { }

    TsvFormatDetector::~TsvFormatDetector() 
    { }

    DataFormat TsvFormatDetector::detect(const std::string& dataChunk) 
    {
        auto parts = Utils::split(dataChunk, "\t");

        if(parts.size() < 2)
            return DataFormat::Unknown;

        bool isTsv = std::all_of(
            parts.begin(), 
            parts.end(),
            [](std::string & part)
            {
                return std::all_of(part.begin(), part.end(), [&](char c)
                {
                    return std::isalnum(c) || 
                           c == ' ' ||
                           c == '.' ||
                           c == '_';
                });
            });

        if(isTsv)
        {
            return m_detectedFormat = DataFormat::TSV;
        }

        return DataFormat::Unknown;
    }

    DataFormat TsvFormatDetector::getFormat() const 
    {
        return m_detectedFormat;
    }

    bool TsvFormatDetector::detected() 
    {
        return m_detectedFormat != DataFormat::Unknown;
    }
    std::vector<std::string> TsvFormatDetector::getCache() 
    {
        return m_dataChunkCache;
    }
    void TsvFormatDetector::reset() 
    {
        m_dataChunkCache.clear();
        m_detectedFormat = DataFormat::Unknown;
    }
}