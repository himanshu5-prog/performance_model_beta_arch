#include "instruction.h"

void InstCollection :: add (string name, Instruction i){
    inst.insert ( {name,i});
}

bool InstCollection :: find (string name){
    if ( inst.find(name) != inst.end())
        return true;
    return false;
}

int InstCollection :: getLatency (string name){
    assert ( find(name));

    return inst[name].latency;

}

int InstCollection :: getOpcode (string name){
    assert ( this->find(name));

    return inst[name].opcode;
}

void InstCollection :: print(){
    map <string, Instruction> :: iterator itr;
    string name;
    Instruction i;
    for (itr = inst.begin(); itr != inst.end(); itr++){
        name = itr->first;
        i = itr-> second;

        cout << name << " : " << i.opcode << "\n";
    }
    cout << "Total instructions: " << inst.size() << "\n";
}

InstCollection createInstructionList(){
    InstCollection instructionList;
    
    Instruction addInst (32, 1, "ADD");
    instructionList.add (addInst.name, addInst);

    Instruction addcInst (48, 1, "ADDC");
    instructionList.add (addcInst.name, addcInst);

    Instruction andInst (40, 1, "AND");
    instructionList.add (andInst.name, andInst);

    Instruction andcInst (56, 1, "ANDC");
    instructionList.add (andcInst.name, andcInst);

    Instruction beqInst (28, 1, "BEQ");
    instructionList.add (beqInst.name, beqInst);

    Instruction bneInst (29, 1, "BNE");
    instructionList.add (bneInst.name, bneInst);

    Instruction cmpeqInst (36, 1, "CMPEQ");
    instructionList.add (cmpeqInst.name, cmpeqInst);

    Instruction cmpeqcInst (52, 1, "CMPEQC");
    instructionList.add (cmpeqcInst.name, cmpeqcInst);

    Instruction cmpleInst (38, 1, "CMPLE");
    instructionList.add (cmpleInst.name, cmpleInst);

    Instruction cmplecInst (54, 1, "CMPLEC");
    instructionList.add ( cmplecInst.name, cmplecInst  );

    Instruction cmpltInst (37, 1, "CMPLT");
    instructionList.add ( cmpltInst.name, cmpltInst);

    Instruction instr (53, 1, "CMPLTC");
    instructionList.add (instr.name, instr);

    instr.setInstr (35, 1, "DIV");
    instructionList.add (instr.name, instr);

    instr.setInstr (51, 1, "DIVC");
    instructionList.add (instr.name, instr);

    instr.setInstr (27, 1, "JMP");
    instructionList.add (instr.name, instr);

    instr.setInstr (24, 1, "LD");
    instructionList.add (instr.name, instr);

    instr.setInstr (31, 1, "LDR");
    instructionList.add (instr.name, instr);

    instr.setInstr (34, 1, "MUL");
    instructionList.add (instr.name, instr);

    instr.setInstr (50, 1, "MULC");
    instructionList.add (instr.name, instr);

    instr.setInstr (41, 1, "OR");
    instructionList.add (instr.name, instr);

    instr.setInstr (57, 1, "ORC");
    instructionList.add (instr.name, instr);
    
    instr.setInstr (44, 1, "SHL" );
    instructionList.add (instr.name, instr);

    instr.setInstr (60, 1, "SHLC" );
    instructionList.add (instr.name, instr);

    instr.setInstr (45, 1, "SHR");
    instructionList.add (instr.name, instr);

    instr.setInstr (61, 1, "SHRC");
    instructionList.add (instr.name, instr);

    instr.setInstr (46, 1, "SRA");
    instructionList.add (instr.name, instr);

    instr.setInstr (62, 1, "SRAC");
    instructionList.add (instr.name, instr);

    instr.setInstr (33, 1, "SUB" );
    instructionList.add (instr.name, instr);

    instr.setInstr (49, 1, "SUBC" );
    instructionList.add (instr.name, instr);

    instr.setInstr (25, 1,"ST" );
    instructionList.add (instr.name, instr);

    instr.setInstr (42, 1, "XOR" );
    instructionList.add (instr.name, instr);

    instr.setInstr (58, 1, "XORC");
    instructionList.add (instr.name, instr);

    instr.setInstr (43, 1, "XNOR" );
    instructionList.add (instr.name, instr);

    instr.setInstr (59, 1,"XNORC" );
    instructionList.add (instr.name, instr);
    return instructionList;

}
//-------------------------------------------------