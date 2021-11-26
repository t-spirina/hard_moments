#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
class vowelsCount
{
public:
    vowelsCount(const char* name):
        file(name, std::ios::in){}
    void readToVec();
    int32_t forFor();
    int32_t counIfFind();
    int32_t countIfFor();
    int32_t countIfForfor();
    int32_t forFind();

    ~vowelsCount(){file.close();}
private:
    std::ifstream file;
    std::vector<std::string> book;
};


