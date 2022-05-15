#ifndef _BENCH_
#define _BENCH_

#include<iostream>
#include<map>
#include <cassert>
#include <fstream>
#include<string>
#include<vector>
#include "../instruction/instruction.h"
using namespace std;

enum SourceType {NONE, REG, LITERAL};
typedef enum SourceType sourceType;

struct benchStruct {
    string opcode;
    string source1;
    string source2;
    string dest;
    sourceType type1;
    sourceType type2;
};

class BenchElem {
    string opcode;
    string source1;
    string source2;
    string dest;
    sourceType type1;
    sourceType type2;

    public:
        BenchElem();
        BenchElem (string opcode, string source1, string source2, string dest, sourceType type1, sourceType type2);
        void print();
        benchStruct getBenchStruct();
};

//Benchmark class-----------------------------------------------------
class Benchmark {
    map <int, BenchElem> benchmark;
    int startAddr;
    int endAddr; 
    public:
        Benchmark() = default;
        void add (int pc, BenchElem b);
        bool find (int pc);
        void print();
        void setAddr (int sa, int ea);
        int getStartAddr();
        int getEndAddr();
        benchStruct getBenchStruct(int pc);
        BenchElem getBenchElem (int pc);
};
//--------------------------------------------------------------------
//Function to create benchmark----------------------------------------
Benchmark createBenchmark ( string fileName, InstCollection instList);
//--------------------------------------------------------------------
#endif