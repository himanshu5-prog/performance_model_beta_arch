#include "instruction.h"

ISA :: ISA (int op, string m){
    this -> nameOpcodeMap.insert({m, op});
    this -> opcodeNameMap.insert( { op,m });
}

void ISA :: printISA (){
    map <int, string> :: iterator itr;
    cout << "Instruction set architecture of Beta\n";
    for (itr = opcodeNameMap.begin(); itr != opcodeNameMap.end(); itr++){
        cout << itr->first << " : " << itr ->second << "\n";
    }
}
//-------------------------------------------------