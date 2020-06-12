#include "DataAccumulator.h"

namespace FormatTransformation
{
    DataAccumulator::DataAccumulator() 
    : m_accumulatedData()
    { }

    DataAccumulator::~DataAccumulator() 
    { }

    bool DataAccumulator::integrate(const std::string& line) 
    {
        m_accumulatedData.push_back(line);
        return true;
    }

    std::vector<std::string> DataAccumulator::takeLogicalPackets()
    {
        auto copy = m_accumulatedData;
        m_accumulatedData.clear();
        return copy;
    }
}