#include "stats.h"
#include "instruction.h"
#include "registers.h"
#include "benchmark.h"
#include "memory.h"
#include "cpu.h"

int main(){
    Stat stat = createStatistics();
    /*
    cout << "statistic:\n";
    stat.print();
    */
    
    InstCollection instList = createInstructionList();
    //instList.print();

    RegisterFile regFile = createRegisters();
    //regFile.print();
    

    string fileName = "benchmark/simple_b.txt";
    string fileName2 = "benchmark/ap.txt";
    Benchmark B = createBenchmark(fileName2, instList);

    cout << "Benchmark:\n";
    B.print();
     
    // Memory-------------------------------
    Memory Mem;
    Mem.createMem();
    /*
    cout << "Memory content\n:";
    Mem.print();
    */
    //--------------------------------------
    // CPU definittion----------------------
    CPU cpu (instList, regFile, Mem);
    cpu.runBenchmark(B, stat);
    /*
    cout << "instruction set architecture\n";
    cpu.printInstCollection();
    */
    cout << " register file:\n";
    cpu.printRegFile();
    
    cout << "Stats:\n";
    stat.print();
    //----------------------------------
    return 0;
}