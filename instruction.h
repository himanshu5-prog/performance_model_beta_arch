#ifndef _INST_
#define _INST_
#include<iostream>
#include<map>

using namespace std;

//Data structure for instruction------------------
struct Instruction
{
    int opcode;
    int latency;

};

class InstCollection {
    map <string, Instruction> inst;
    
    public:
        InstCollection(string name, Instruction instr){
            inst.insert( {name, instr}  );
        }
};
// Instruction Set Architecture data structure----
class ISA {
    map <string, int> nameOpcodeMap;
    map <int, string> opcodeNameMap;

    public:
        ISA(int op, string m);
        void printISA ();

};

InstCollection createInstructionList ();
//-------------------------------------------------

#endif