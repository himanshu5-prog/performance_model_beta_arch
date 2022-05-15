#include "stats/stats.h"
#include "instruction/instruction.h"
#include "register/registers.h"
#include "benchmark/benchmark.h"
#include "memory/memory.h"
#include "cpu/cpu.h"

int main(){
    //Creating statistics
    Stat stat = createStatistics();
    
    //Creating instruction collection
    InstCollection instList = createInstructionList();

    //Creating register file
    RegisterFile regFile = createRegisters();
    
    //Benchmark file
    string fileName = "benchmarkFiles/simple_b.txt";
    string fileName2 = "benchmarkFiles/ap.txt";
    //Creating benchmark data structure
    Benchmark B = createBenchmark(fileName2, instList);
    
    cout << "Benchmark:\n";
    B.print();
     
    // Memory-------------------------------
    Memory Mem;
    Mem.createMem();
    //--------------------------------------
    // CPU definittion----------------------
    CPU cpu (instList, regFile, Mem);
    //Running the benchmark
    cpu.runBenchmark(B, stat);
    
    //Printing the register file
    cout << " register file:\n";
    cpu.printRegFile();
    
    //Printing the stats
    cout << "Stats:\n";
    stat.print();
    //----------------------------------
    return 0;
}
