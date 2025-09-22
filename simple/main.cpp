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
#include <vector>

#define FASTIO              \
    std::cin.tie(nullptr);  \
    std::cout.tie(nullptr); \
    std::cout.precision(11)

std::vector<std::string> split(std::string s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token = "";
    for (char c : s)
    {
        if (c == delimiter)
        {
            tokens.push_back(token);
            token = "";
        }
        else
        {
            token += c;
        }
    }
    tokens.push_back(token);

    return tokens;
}

struct Result {
    float min = std::numeric_limits<float>::max();
    float max = std::numeric_limits<float>::min();
    float sum = 0.0;
    int count = 0;
};

int main(int argc, char *argv[])
{
    FASTIO;
    assert(argc == 2);

    char *FILENAME = argv[1];

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    std::map<std::string, Result*> results = {};

    char *line = NULL;
    size_t len = 0;

    while ((getline(&line, &len, fp)) != -1)
    {
        auto v = split(std::string(line), ';');
        assert(v.size() == 2);
        std::string place = v[0];
        if (results.find(place) == results.end())
        {
            results[place] = new Result();
        }
        Result* r = results[place];

        float deg = std::stof(v[1]);
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
