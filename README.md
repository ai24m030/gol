# Readme
## How to run
- Use CmakeLists.txt to build.
- main.cpp is entry point

On Windows I am running the following commands:
```
mkdir Build
cd .\Build\
cmake ..
cmake --build . --config Release
cd .\Release\
.\gol.exe
```

```
gol --load <filename> --save <filename> --generations <n> [--measure]
```

## Output
- with ```--measure```
  00:00.000;00:00.000;00:00.000
- without ```--measure``` no output


## Time

On my machine (Windows, Intel 13700K):

- random250_in.gol: ```0:00.002;0:01.444;0:00.006```
- random1000_in.gol: ```0:00.008;0:05.834;0:00.025```
- random10000_in.gol: ```0:00.078;0:58.476;0:00.280```