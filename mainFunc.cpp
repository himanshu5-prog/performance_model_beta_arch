#include "stats.h"
#include "instruction.h"
#include "registers.h"
#include "benchmark.h"
#include "cpu.h"

int main(){
    Stat stat = createStatistics();
    cout << "statistic:\n";
    stat.print();
    
    
    InstCollection instList = createInstructionList();
    //instList.print();

    RegisterFile regFile = createRegisters();
    //regFile.print();
    

    string fileName = "benchmark/simple_b.txt";
    Benchmark B = createBenchmark(fileName, instList);

    cout << "Benchmark:\n";
    B.print();
    
    // CPU definittion----------------------
    CPU cpu (instList, regFile);
    cout << "instruction set architecture\n";
    cpu.printInstCollection();
    cout << " register file:\n";
    cpu.printRegFile();
    //----------------------------------
    return 0;
}