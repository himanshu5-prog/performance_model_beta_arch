#include "registers.h"

void RegisterFile :: print (){
    map <string, Register> :: iterator itr;
    string name;
    Register tempReg;
    for (itr = reg.begin(); itr != reg.end(); itr++){
        name = itr->first;
        tempReg = itr->second;

        cout << name << " : " << tempReg.value << " , " << tempReg.info << "\n";
    }
}

RegisterFile createRegisters(){
    RegisterFile rf;
    Register reg;

    reg.reserved = false;
    reg.name = "R0";
    reg.value = 0;
    reg.info ="This is R0 register.";
    
    rf.add(reg.name, reg);

    string p = "R";
    string p_name;
    for (int i=1; i<32; i++){
        p_name = p + to_string(i);
        reg.name = p_name;
        reg.info = "This is " + p_name + " register";
        rf.add(reg.name, reg);
    }

    rf.changeRegInfo("R27", "This reg points to base of frame pointer");
    rf.changeReserveBit("R27", true);

    rf.changeRegInfo("R28", "This reg points to linkage pointer");
    rf.changeReserveBit("R28", true);

    rf.changeRegInfo("R29", "This reg points to Stack pointer");
    rf.changeReserveBit("R29", true);

    rf.changeRegInfo("R30", "This reg points to Exception pointer");
    rf.changeReserveBit("R30", true);
    
    rf.changeRegInfo("R31", "This reg is always 0");
    rf.changeReserveBit("R30", true);

    return rf;

}