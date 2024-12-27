@echo off

REM Path to your compiled executable
set executable=.\Build\Release\gol.exe

REM Output file
set output_file=mai24m030_openmp_time.csv

echo. >> %output_file%

REM Define the arguments for each run
set args1=--mode omp --threads 8 --load .\files\random1000_in.gol --save .\outfiles\mai24m030_1000_openmp_out.gol --generations 250 --measure
set args2=--mode omp --threads 8 --load .\files\random2000_in.gol --save .\outfiles\mai24m030_2000_openmp_out.gol --generations 250 --measure
set args3=--mode omp --threads 8 --load .\files\random3000_in.gol --save .\outfiles\mai24m030_3000_openmp_out.gol --generations 250 --measure
set args4=--mode omp --threads 8 --load .\files\random4000_in.gol --save .\outfiles\mai24m030_4000_openmp_out.gol --generations 250 --measure
set args5=--mode omp --threads 8 --load .\files\random5000_in.gol --save .\outfiles\mai24m030_5000_openmp_out.gol --generations 250 --measure
set args6=--mode omp --threads 8 --load .\files\random6000_in.gol --save .\outfiles\mai24m030_6000_openmp_out.gol --generations 250 --measure
set args7=--mode omp --threads 8 --load .\files\random7000_in.gol --save .\outfiles\mai24m030_7000_openmp_out.gol --generations 250 --measure
set args8=--mode omp --threads 8 --load .\files\random8000_in.gol --save .\outfiles\mai24m030_8000_openmp_out.gol --generations 250 --measure
set args9=--mode omp --threads 8 --load .\files\random9000_in.gol --save .\outfiles\mai24m030_9000_openmp_out.gol --generations 250 --measure
set args10=--mode omp --threads 8 --load .\files\random10000_in.gol --save .\outfiles\mai24m030_10000_openmp_out.gol --generations 250 --measure

%executable% %args1% >> %output_file%
%executable% %args2% >> %output_file%
%executable% %args3% >> %output_file%
%executable% %args4% >> %output_file%
%executable% %args5% >> %output_file%
%executable% %args6% >> %output_file%
%executable% %args7% >> %output_file%
%executable% %args8% >> %output_file%
%executable% %args9% >> %output_file%
%executable% %args10% >> %output_file%

echo All runs completed. Combined output saved to %output_file%.
pause