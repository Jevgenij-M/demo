#include "DataIntegrators.h"
#include "DataAccumulator.h"

namespace FormatTransformation
{
    std::shared_ptr<IDataIntegrator> DataIntegrator(const DataFormat dataFormat)
    {
        switch (dataFormat)
        {
            case DataFormat::CSV:
            case DataFormat::TSV:
            case DataFormat::Unknown:
                return std::make_shared<DataAccumulator>();
        }
    }
}