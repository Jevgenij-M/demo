#include <algorithm>

#include "CsvFormatDetector.h"

#include "../utils.h"

namespace FormatTransformation
{
    CsvFormatDetector::CsvFormatDetector()
    : m_detectedFormat(DataFormat::Unknown)
    , m_dataChunkCache()
    { }

    CsvFormatDetector::~CsvFormatDetector()
    { }

    DataFormat CsvFormatDetector::detect(const std::string& dataChunk) 
    {
        // Detection is oversimplified as for now
        auto parts = Utils::split(dataChunk, ",");

        if(parts.size() < 2)
            return DataFormat::Unknown;

        bool isCsv = std::all_of(
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

        if(isCsv)
        {
            return m_detectedFormat = DataFormat::CSV;
        }

        return DataFormat::Unknown;
    }

    DataFormat CsvFormatDetector::getFormat() const 
    {
        return m_detectedFormat;
    }

    bool CsvFormatDetector::detected() 
    {
        return m_detectedFormat != DataFormat::Unknown;
    }
    std::vector<std::string> CsvFormatDetector::getCache() 
    {
        return m_dataChunkCache;
    }
    void CsvFormatDetector::reset() 
    {
        m_dataChunkCache.clear();
        m_detectedFormat = DataFormat::Unknown;
    }
}