#include "cpu.h"

void CPU::printInstCollection (){
    instCollection.print();
}

void CPU :: printRegFile (){
    regFile.print();
}

void CPU :: runBenchmark (Benchmark &B, Stat &S){
    int pc;
    BenchElem bm;
    int instID;
    benchStruct bstr;
    int startAddr = B.getStartAddr();
    int endAddr = B.getEndAddr();
    int i;
    
    string opcode, source1, source2, dest;
    sourceType t1, t2;
    int addr = startAddr;
    while ( i <= endAddr){
        pc = i;
        if ( B.find(pc) == false){
            i += 4;
            continue;
        }
        bm = B.getBenchElem(pc);
        bstr = B.getBenchStruct(pc);

        opcode = bstr.opcode;
        source1 = bstr.source1;
        t1 = bstr.type1;
        source2 = bstr.source2;
        t2 = bstr.type2;
        dest = bstr.dest;

        instID = instCollection.getOpcode(opcode);

        i += 4;
    }
}