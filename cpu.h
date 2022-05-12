#ifndef _CPU_
#define _CPU_

#include "instruction.h"
#include "stats.h"
#include "registers.h"
#include "benchmark.h"

class CPU {
    InstCollection instCollection;
    RegisterFile regFile;
    
    public:
        CPU() = default;
        CPU (InstCollection i, RegisterFile r){
            instCollection = i;
            regFile = r;
        }
        void printInstCollection();
        void printRegFile();
        void runBenchmark( Benchmark &B, Stat &s);

};
#endif