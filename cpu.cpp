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
    int temp, temp1, temp2;
    int mem_data;
    int addr = startAddr;
    i = startAddr;
    int cycleCount = 0;

    while ( i <= endAddr){
        pc = i;
        cout << "CPU :: runBenchmark : PC: " << pc << "\n";
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
        
        cycleCount += instCollection.getLatency(opcode);

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
            S.incrementStat("branchInstCount", 1);
        } else if ( opcode == "JMP") {
            temp = regFile.readReg(reg1_id);
            temp = (temp >> 2) << 2;
            regFile.changeRegValue(dest,pc+4);
            i = temp - 4; 
            S.incrementStat("branchInstCount", 1);

        } else if (opcode == "LD"){
            reg1_id = source1;
            assert (regFile.findReg(reg1_id));
            literal = stoi(source2);
            temp = regFile.readReg(reg1_id) + literal;
            mem_data = memory.getValue(temp);
            regFile.changeRegValue(dest,mem_data);
            S.incrementStat("loadInstCount", 1);

        } else if (opcode == "ST"){
            literal = stoi(source2);
            reg1_id = source1;
            assert(regFile.findReg(reg1_id));
            //Address calculation
            temp = regFile.readReg(dest) + literal;

            memory.store(temp, regFile.readReg(reg1_id));
            S.incrementStat("storeInstCount", 1);

        } else if (opcode == "LDR"){
            literal =  stoi(source1);
            temp = pc + 4 + (4*literal);   
            regFile.changeRegValue(dest, memory.getValue(temp)); 
            S.incrementStat("loadInstCount", 1);

        }else if (instID >> 4 == 3){

            assert (t2 == LITERAL);
            literal = stoi(source2);
            assert (t1 == REG);

            temp1 = regFile.readReg(source1);
            temp2 = literal;
            if (debugMode) cout << "CPU :: runBenchmark :: source1: " << source1 << " literal: " << literal << " dest: " << dest << "\n";
            if (opcode == "ADDC"){
                temp = temp1 + temp2;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("aluInstCount", 1);

            } else if ( opcode == "ANDC"){
                temp = temp1 & temp2;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);

            } else if ( opcode == "CMPEQC"){
                if ( regFile.readReg(source1) == literal){
                    regFile.changeRegValue(dest,1);
                } else
                    regFile.changeRegValue(dest,0);
                S.incrementStat("aluInstCount", 1);

            } else if ( opcode == "CMPLEC"){
                if ( regFile.readReg(source1) <= literal){
                    regFile.changeRegValue(dest,1);
                } else {
                    regFile.changeRegValue(dest,0);
                }
                S.incrementStat("aluInstCount", 1);

            } else if ( opcode == "CMPLTC"){
                if ( regFile.readReg(source1) < literal){
                    regFile.changeRegValue(dest,1);
                } else {
                    regFile.changeRegValue(dest,0);
                }
                S.incrementStat("aluInstCount", 1);

            } else if ( opcode == "DIVC"){
                temp = regFile.readReg(source1)/literal;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("aluInstCount", 1);

            } else if (opcode == "MULC"){
                temp = regFile.readReg(source1) * literal;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("aluInstCount", 1);

            } else if ( opcode == "ORC"){
                temp = regFile.readReg(source1) | literal;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);

            } else if ( opcode == "SHLC"){
                literal = literal & 0x1F;
                temp = regFile.readReg(source1) << literal;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);

            } else if ( opcode == "SHRC" || opcode == "SRAC"){
                literal = literal & 0x1F;
                temp = regFile.readReg(source1) >> literal;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);

            } else if ( opcode == "SUBC"){
                temp = regFile.readReg(source1) - literal;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("aluInstCount", 1);

            } else if ( opcode == "XORC"){
                temp = regFile.readReg(source1) ^ literal;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);

            } else if ( opcode == "XNORC"){
                temp = ~(regFile.readReg(source1) ^ literal);
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);

            }
        } else {
            //Instructions have both sources as register
            if (debugMode){
                cout << "CPU :: runBenchmark :source1: " << source1 << " source2: " << source2 << " dest: " << dest<< endl;
            }
            
            temp1 = regFile.readReg(source1);
            temp2 = regFile.readReg(source2);
            if (opcode == "ADD"){
                if (debugMode) cout << "Instruction is ADD\n";

                temp = temp1 + temp2;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("aluInstCount", 1);

            } else if (opcode == "AND" ){
                temp = regFile.readReg(source1) & regFile.readReg(source2);
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);

            } else if (opcode == "CMPEQ"){
                if (regFile.readReg(source1) == regFile.readReg(source2)){
                    temp = 1;
                } else temp = 0;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("aluInstCount", 1);

            } else if ( opcode == "CMPLE"){
                if (regFile.readReg(source1) <= regFile.readReg(source2)){
                    temp = 1;
                } else temp = 0;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("aluInstCount", 1);

            } else if (opcode == "CMPLT"){
                if (regFile.readReg(source1) < regFile.readReg(source2)){
                    temp = 1;
                } else temp = 0;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("aluInstCount", 1);

            } else if ( opcode == "DIV"){
                temp = regFile.readReg(source1) / regFile.readReg(source2);
                regFile.changeRegValue(dest, temp);
                S.incrementStat("aluInstCount", 1);

            } else if (opcode == "MUL"){
                temp = regFile.readReg(source1) * regFile.readReg(source2);
                regFile.changeRegValue(dest, temp);
                S.incrementStat("aluInstCount", 1);

            } else if (opcode == "OR"){
                temp = regFile.readReg(source1) | regFile.readReg(source2);
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);

            } else if (opcode == "SHL"){
                literal = regFile.readReg(source2) & 0x1F;
                temp = regFile.readReg(source1) << literal;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);

            } else if (opcode == "SHR" || opcode == "SRA"){
                literal = regFile.readReg(source2) & 0x1F;
                temp = regFile.readReg(source1) >> literal;
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);
                
            } else if (opcode == "SUB"){
                temp = regFile.readReg(source1) - regFile.readReg(source2);
                regFile.changeRegValue(dest, temp);
                S.incrementStat("aluInstCount", 1);

            } else if ( opcode == "XOR"){
                temp = regFile.readReg(source1) ^ regFile.readReg(source2);
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);

            } else if ( opcode == "XNOR"){
                temp = ~(regFile.readReg(source1) ^ regFile.readReg(source2));
                regFile.changeRegValue(dest, temp);
                S.incrementStat("booleanInstCount", 1);

            }
        }
        S.incrementStat("totalInstCount", 1);
        i += 4;
    }
    S.incrementStat("cycleCount", cycleCount);
}