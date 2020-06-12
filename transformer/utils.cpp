#include "utils.h"

#include <vector>
#include <string>
#include <iostream>

namespace Utils
{
    std::vector<std::string> split(const std::string & str, const std::string & delimiters)
    {
        std::vector<std::string> parts;
        int from = 0;

        for (int i = 0; i < str.size(); i++)
        {
            if(delimiters.find(str[i]) != std::string::npos)
            {
                if (from < i)
                    parts.push_back(str.substr(from, i-from));

                from = i+1;
            }
            else if(i == str.size()-1 && from <= i)
            {
                parts.push_back(str.substr(from, 1+i-from));
            }
        }

        return parts;
    }

    std::string getFileNameExtension(const std::string& fileName)
    {
        const auto parts = split(fileName, ".");

        if(parts.size() > 1)
            return parts.back();

        return "";
    }

    void coutVector(const std::vector<std::string>& vec)
    {
        std::cout << "coutVector: ";

        for (const auto & e : vec)
            std::cout << e << "    ";
        
        std::cout << std::endl;
    }
}