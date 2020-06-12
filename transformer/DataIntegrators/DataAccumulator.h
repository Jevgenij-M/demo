#pragma once 

#include <vector>
#include <string>

#include "IDataIntegrator.h"

namespace FormatTransformation
{
    class DataAccumulator : public IDataIntegrator
    {
    public:
        DataAccumulator();
        virtual ~DataAccumulator();

        virtual bool integrate(const std::string& line) override;
        virtual std::vector<std::string> takeLogicalPackets() override;

    private:
        std::vector<std::string> m_accumulatedData;
    };
}