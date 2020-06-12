#include <vector>
#include <string>
#include <memory>

#include "FormatTransformers.h"
#include "CsvToTsvTransformer.h"
#include "TsvToCsvTransformer.h"

namespace FormatTransformation
{
    std::shared_ptr<IFormatTransformer> FormatTransformer(const DataFormat from, const DataFormat to) 
    {
        if (from == DataFormat::CSV && to == DataFormat::TSV)
            return std::make_shared<CsvToTsvTransformer>();
        else if (from == DataFormat::TSV && to == DataFormat::CSV)
            return std::make_shared<TsvToCsvTransformer>();
        else 
            return nullptr;
    }
}