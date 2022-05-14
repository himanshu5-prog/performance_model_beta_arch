#g++ perf_model.cpp benchmark/benchmark.cpp cpu/cpu.cpp instruction/instruction.cpp memory/memory.cpp register/registers.cpp stats/stats.cpp -o bin/perf_model

g++ -c instruction/instruction.cpp -o bin/instruction
g++ -c benchmark/benchmark.cpp -o bin/benchmark
g++ -c cpu/cpu.cpp -o bin/cpu
g++ -c memory/memory.cpp -o bin/memory
g++ -c register/registers.cpp -o bin/register
g++ -c stats/stats.cpp -o bin/stats
g++ -c perf_model.cpp -o bin/perf_model
g++ bin/instruction bin/benchmark bin/cpu bin/memory bin/register bin/stats bin/perf_model -o bin/Perf_model.out