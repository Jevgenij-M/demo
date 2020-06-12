#pragma once 

#include <vector>
#include <string>

#include "../DataFormat.h"

namespace FormatTransformation
{
    class IDataIntegrator
    {
    public:
        IDataIntegrator() {}
        virtual ~IDataIntegrator() {}

        virtual bool integrate(const std::string& line) = 0;
        virtual std::vector<std::string> takeLogicalPackets() = 0;
    };
}