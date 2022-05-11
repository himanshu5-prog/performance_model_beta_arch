#ifndef _BENCH_
#define _BENCH_

#include<iostream>
#include<map>
#include <cassert>
#include <fstream>
#include<string>
#include<vector>
#include "instruction.h"
using namespace std;

enum SourceType {NONE, REG, LITERAL};
typedef enum SourceType sourceType;

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
};

class Benchmark {
    map <int, BenchElem> benchmark;
    public:
        Benchmark() = default;
        void add (int pc, BenchElem b);
        bool find (int pc);
        BenchElem getBenchElem (int pc);
};

Benchmark createBenchmark ( string fileName, InstCollection instList);
#endif