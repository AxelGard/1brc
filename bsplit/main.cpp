#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#define FASTIO              \
    std::cin.tie(nullptr);  \
    std::cout.tie(nullptr); \
    std::cout.precision(11)

struct Result {
    float min = std::numeric_limits<float>::max();
    float max = std::numeric_limits<float>::min();
    float sum = 0.0;
    int count = 0;
};

std::pair<std::string, float> split(std::string s, char delimiter)
{
    std::pair<std::string, float> tokens = {};
    std::string token = "";
    for (char c : s)
    {
        if (c == delimiter)
        {
            tokens.first = token;
            token = "";
        }
        else
        {
            token += c;
        }
    }
    tokens.second = std::stof(token);
    return tokens;
}


int main(int argc, char *argv[])
{
    FASTIO;
    assert(argc == 2);

    char *FILENAME = argv[1];

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    std::unordered_map<std::string, Result*> results = {};

    char *line = NULL;
    size_t len = 0;

    while ((getline(&line, &len, fp)) != -1)
    {
        auto v = split(std::string(line), ';');
        std::string place = v.first;
        if (results.find(place) == results.end())
        {
            results[place] = new Result();
        }
        Result* r = results[place];

        float deg = v.second; 
        if (deg > r->max)
        {
            r->max = deg;
        }
        if (deg < r->min)
        {
            r->min = deg;
        }
        r->sum += deg;
        r->count++;
    }

    fclose(fp);
    if (line)
        free(line);


    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout<< "{" << std::endl;
    for (const auto&[place, r] : results)
    {
        std::cout << place << " = "<< r->min << "/" << r->sum / r->count << "/" << r->max << "," << std::endl;
        delete r; 
    }
    std::cout<< "}" << std::endl;
    return 0;
}
