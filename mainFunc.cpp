#include "stats.h"
#include "instruction.h"
#include "registers.h"
#include "benchmark.h"

int main(){
    Stat stat = createStatistics();
    cout << "statistic:\n";
    stat.print();

    InstCollection instList = createInstructionList();
    cout << "Instructions: \n";
    instList.print();

    RegisterFile regFile = createRegisters();
    cout << " Registers:\n";
    regFile.print();

    string fileName = "benchmark/simple_b.txt";
    Benchmark B = createBenchmark(fileName, instList);
    return 0;
}