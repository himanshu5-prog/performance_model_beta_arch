#include "benchmark.h"

BenchElem :: BenchElem(){
    opcode = "";
    source1 = "";
    source2 = "";
    dest = "";
    type1 = NONE;
    type2 = NONE;
}

BenchElem :: BenchElem (string op, string s1, string s2, string d, sourceType t1, sourceType t2){
    opcode = op;
    source1 = s1;
    source2 = s2;
    dest = d;
    type1 = t1;
    type2 = t2;
}

void Benchmark :: add (int pc, BenchElem b){
    benchmark.insert( {pc, b});
}

bool Benchmark :: find(int pc){
    if ( benchmark.find(pc) != benchmark.end())
        return true;
    
    return false;
}

BenchElem Benchmark :: getBenchElem (int pc){
    assert ( find(pc));
    return benchmark[pc];

}