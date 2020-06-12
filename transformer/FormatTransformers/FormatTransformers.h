#pragma once

#include <vector>
#include <string>
#include <memory>

#include "IFormatTransformer.h"
#include "../DataFormat.h"

namespace FormatTransformation
{
    std::shared_ptr<IFormatTransformer> FormatTransformer(const DataFormat from, const DataFormat to);
}