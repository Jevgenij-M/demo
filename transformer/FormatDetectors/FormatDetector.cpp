#include "FormatDetector.h"
#include "CsvFormatDetector.h"
#include "TsvFormatDetector.h"

#include <memory>

namespace FormatTransformation
{
    FormatDetector::FormatDetector()
    : m_detectedFormat (DataFormat::Unknown) 
    , m_formatDetectors()
    {
        m_formatDetectors[DataFormat::CSV] = std::unique_ptr<IFormatDetector> (new CsvFormatDetector());
        m_formatDetectors[DataFormat::TSV] = std::unique_ptr<IFormatDetector> (new TsvFormatDetector());
    }

    DataFormat FormatDetector::getFormat() const
    {
        return m_detectedFormat;
    }

    DataFormat FormatDetector::detect(const std::string& dataChunk)
    {
        for(auto & fd : m_formatDetectors)
        {
            const auto format = fd.second->detect(dataChunk);
            if(format != DataFormat::Unknown)
            {
                m_detectedFormat = format;
                break;
            }
        }

        return m_detectedFormat;
    }

    bool FormatDetector::detected()
    {
        return m_detectedFormat != DataFormat::Unknown;
    }
    
    void FormatDetector::reset()
    {
        for(auto & fd : m_formatDetectors)
        {
            fd.second.reset();
        }

        m_detectedFormat = DataFormat::Unknown;
    }

    std::vector<std::string> FormatDetector::getCache()
    {
        return m_formatDetectors[m_detectedFormat]->getCache();
    }
}