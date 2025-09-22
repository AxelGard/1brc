#include <cassert>
#include <cstddef>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>


int main(int argc, char *argv[])
{
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
        int i = strlen(line) - 2;
        
        std::string token = "";
        while(i > 0)
        {
            if (line[i] == ';') 
            {
                break;
            }
            token = line[i] + token;
            i--; 
        }
        float deg = std::stof(token);
        if (deg > max)
        {
            max = deg;
        }
        else if (deg < min)
        {
            min = deg;
        }
        mean += deg;
        row_count++;
    }
    row_count--;

    fclose(fp);
    if (line)
        free(line);

    std::cout << min << "/" << mean / row_count << "/" << max << std::endl;
    return 0;
}
