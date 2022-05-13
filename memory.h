#ifndef _MEM_
#define _MEM_

#include<iostream>
#include<map>
#include<cassert>
using namespace std;

class Memory {
    map <int, int> mem;
    public:
        Memory() = default;
        void add (int addr, int value);
        bool find (int addr);
        int getValue (int addr);
        void store(int addr, int value);
        void createMem();
        void print();
};

#endif