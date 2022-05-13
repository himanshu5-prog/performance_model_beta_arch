#ifndef _CPU_
#define _CPU_

#include "instruction.h"
#include "stats.h"
#include "registers.h"
#include "benchmark.h"
#include "memory.h"

class CPU {
    InstCollection instCollection;
    RegisterFile regFile;
    Memory memory;
    bool debugMode = true;

    public:
        CPU() = default;
        CPU (InstCollection i, RegisterFile r, Memory m){
            instCollection = i;
            regFile = r;
            memory = m;
        }
        void printInstCollection();
        void printRegFile();
        void runBenchmark( Benchmark &B, Stat &s);

};
#endif