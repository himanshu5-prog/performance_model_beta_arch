#ifndef _INST_
#define _INST_
#include<iostream>
#include<map>
#include<cassert>

using namespace std;

//Data structure for instruction------------------
struct Instruction
{
    int opcode;
    int latency;
    string name;

    Instruction() {
        opcode = 0; 
        latency = 0;
        name = "";
    }
    Instruction( int op, int lat, string n){
        opcode = op;
        latency = lat;
        name = n;
    }

    void setInstr ( int op, int lat, string n){
        opcode = op;
        latency = lat;
        name = n;
    }


};
//-----------------------------------------------------------
//Class for instruction collection-------------------------
class InstCollection {
    map <string, Instruction> inst;
    
    public:
        InstCollection() = default;
        InstCollection(string name, Instruction instr){
            inst.insert( {name, instr}  );
        }
        void add (string name, Instruction instr);
        bool find (string name);
        int getOpcode(string name);
        int getLatency (string name);
        void print();
};

InstCollection createInstructionList ();
//-------------------------------------------------

#endif