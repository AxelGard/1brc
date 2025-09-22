# 1brc
The One Billion Row Challenge


data from https://github.com/gunnarmorling/1brc/blob/main/data/weather_stations.csv

## build

```bash
make
time ./main ./weather_stations.csv
```

## performance

My time on my macbook pro 14 m3 pro

### simple solution
```
-54.9333/25.9337/81.7166

real    0m0.054s
user    0m0.044s
sys     0m0.007s

$ time ./bin/simple measurements.txt ## with asserts etc 

-67.800003052/1.078078866/82.599998474

real    13m3.310s
user    12m56.843s
sys     0m5.780s

-67.8/1.07808/82.6 bsplit

real    5m18.316s
user    5m12.590s
sys     0m5.446s
```
