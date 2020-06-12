#pragma once 

#include <vector>
#include <memory>

#include "IDataIntegrator.h"

namespace FormatTransformation
{
    std::shared_ptr<IDataIntegrator> DataIntegrator(const DataFormat dataFormat);
}