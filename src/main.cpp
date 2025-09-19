#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#define FASTIO                   \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr);           \
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

int main(int argc, char *argv[])
{
    FASTIO;
    assert(argc == 2);

    char *FILENAME = argv[1];

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    char *line = NULL;
    size_t len = 0;
    float min = std::numeric_limits<float>::max();
    float max = std::numeric_limits<float>::min();
    float mean = 0.0;
    int row_count = 0;

    while ((getline(&line, &len, fp)) != -1)
    {
        auto v = split(std::string(line), ';');
        assert(v.size() == 2);
        std::string place = v[0];
        float deg = std::stof(v[1]);
        if (deg > max)
        {
            max = deg;
        }
        if (deg < min)
        {
            min = deg;
        }
        mean += deg;
        row_count++;
    }

    fclose(fp);
    if (line)
        free(line);

    std::cout << min << "/" << mean / row_count << "/" << max << std::endl;
    return 0;
}
