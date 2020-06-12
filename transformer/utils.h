#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>

namespace Utils
{
    std::vector<std::string> split(const std::string & str, const std::string & delimiters);

    std::string getFileNameExtension(const std::string& fileName);

    void coutVector(const std::vector<std::string>& vec);
}