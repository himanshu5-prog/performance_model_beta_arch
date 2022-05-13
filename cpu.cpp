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
    
    string reg1_id, reg2_id;
    int literal;
    int pc_temp;
    int temp;
    int mem_data;
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

        if (opcode == "BEQ" || opcode == "BNE"){
            reg1_id = source1;
            assert(regFile.findReg(reg1_id));
            literal = stoi(source2);
            assert(t2 == LITERAL);

            pc_temp = pc + (4*literal);
            temp = regFile.readReg(reg1_id);
            regFile.changeRegValue(dest,pc);

            if (opcode == "BEQ"){
                if (temp == 0){
                    i = pc_temp;
                }
            } else if ( opcode == "BNE"){
                if (temp != 0){
                    i = pc_temp;
                }
            }
        } else if ( opcode == "JMP") {
            temp = regFile.readReg(reg1_id);
            temp = (temp >> 2) << 2;
            regFile.changeRegValue(dest,pc+4);
            i = temp - 4; 

        } else if (opcode == "LD"){
            reg1_id = source1;
            assert (regFile.findReg(reg1_id));
            literal = stoi(source2);
            temp = regFile.readReg(reg1_id) + literal;
            mem_data = memory.getValue(temp);
            regFile.changeRegValue(dest,mem_data);

        } else if (opcode == "ST"){
            literal = stoi(source2);
            reg1_id = source1;
            assert(regFile.findReg(reg1_id));
            //Address calculation
            temp = regFile.readReg(dest) + literal;

            memory.store(temp, regFile.readReg(reg1_id));

        } else if (instID >> 4 == 3){

            assert (t2 == LITERAL);
            literal = stoi(source2);
            assert (t1 == REG);
            if (opcode == "ADDC"){
                temp = regFile.readReg(source1) + literal;
                regFile.changeRegValue(dest, temp);

            } else if ( opcode == "ANDC"){
                temp = regFile.readReg(source1) & literal;
                regFile.changeRegValue(dest, temp);

            } else if ( opcode == "CMPEQC"){
                if ( regFile.readReg(source1) == literal){
                    regFile.changeRegValue(dest,1);
                } else
                    regFile.changeRegValue(dest,0);

            } else if ( opcode == "CMPLEC"){
                if ( regFile.readReg(source1) <= literal){
                    regFile.changeRegValue(dest,1);
                } else {
                    regFile.changeRegValue(dest,0);
                }

            } else if ( opcode == "CMPLTC"){
                if ( regFile.readReg(source1) < literal){
                    regFile.changeRegValue(dest,1);
                } else {
                    regFile.changeRegValue(dest,0);
                }
            } else if ( opcode == "DIVC"){
                temp = regFile.readReg(source1)/literal;
                regFile.changeRegValue(dest, temp);

            } else if (opcode == "MULC"){
                temp = regFile.readReg(source1) * literal;
                regFile.changeRegValue(dest, temp);

            } else if ( opcode == "ORC"){
                temp = regFile.readReg(source1) | literal;
                regFile.changeRegValue(dest, temp);

            } else if ( opcode == "SHLC"){
                literal = literal & 0x1F;
                temp = regFile.readReg(source1) << literal;
                regFile.changeRegValue(dest, temp);

            } else if ( opcode == "SHRC" || opcode == "SRAC"){
                literal = literal & 0x1F;
                temp = regFile.readReg(source1) >> literal;
                regFile.changeRegValue(dest, temp);

            } else if ( opcode == "SUBC"){
                temp = regFile.readReg(source1) - literal;
                regFile.changeRegValue(dest, temp);

            } else if ( opcode == "XORC"){
                temp = regFile.readReg(source1) ^ literal;
                regFile.changeRegValue(dest, temp);

            } else if ( opcode == "XNORC"){
                temp = ~(regFile.readReg(source1) ^ literal);
                regFile.changeRegValue(dest, temp);

            }
        }

        i += 4;
    }
}