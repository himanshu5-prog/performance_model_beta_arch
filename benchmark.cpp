#include "benchmark.h"
#include "instruction.h"

// BenchElem functio-----------------------------------------------------------------------------
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

void BenchElem :: print (){
    cout << "opcode: " << opcode << ", source1: " << source1 << ", source1 type: " << type1 << ", source2: "
    << source2 << ", source2 type: " << type2 <<", dest: " << dest << "\n";
}

benchStruct BenchElem :: getBenchStruct(){
    benchStruct answer;
    answer.opcode = opcode;
    answer.source1 = source1;
    answer.source2 = source2;
    answer.type1 = type1;
    answer.type2 = type2;
    answer.dest = dest;
}
//-----------------------------------------------------------------------------------------------
// Benchmark class function-----------------
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

void Benchmark :: print(){
    map <int, BenchElem> :: iterator itr;
    int pc;
    BenchElem B;
    cout << "Benchmark start address: " << getStartAddr() << " end address: " << getEndAddr() << "\n"; 
    for (itr = benchmark.begin(); itr != benchmark.end(); itr++){
        pc = itr->first;
        B = itr->second;
        cout <<" pc: " << pc << " ";
        B.print();
    }
}

void Benchmark :: setAddr (int sa, int ea){
    startAddr = sa;
    endAddr = ea;
}

int Benchmark :: getStartAddr(){
    return startAddr;
}

int Benchmark :: getEndAddr(){
    return endAddr;
}

benchStruct Benchmark :: getBenchStruct(int pc){
    return benchmark[pc].getBenchStruct();
}
//--------------------------------------------
void printStringVect ( vector <string> v){
    for (int i=0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

vector <string> sepLine (  string str){
    vector <string> answer;

    string temp = "";
    char SPACE = ' ';
    for (int i=0; i<str.length(); i++){
        if (str[i] == SPACE){
            if (temp.length() > 0)
                answer.push_back(temp);
                temp ="";
        } else {
            temp = temp + str[i];
        }
    }

    if (temp.length()){
        answer.push_back(temp);
    }

    return answer;
}
Benchmark createBenchmark(string fileName, InstCollection instCollection){
    Benchmark B; 
    int pc;
    fstream ip;
    ip.open(fileName, ios::in); 
    vector <string> strVect;
    pc = 0;
    int op;
    int startBenchAddr, endBenchAddr;
    string opcode;
    string source1, source2, dest;
    sourceType t1, t2;

    startBenchAddr = 0;
    if (ip.is_open()){
        string str;
        while( getline(ip,str)){
            strVect = sepLine(str);
            //cout << str << "\n";
            //printStringVect(strVect);
            assert(instCollection.find(strVect[0]));
            op = instCollection.getOpcode(strVect[0]);
            //cout << "opcode: " << instCollection.getOpcode(strVect[0]) << "\n";
            opcode = strVect[0];

            if ( op == 27 ){
                //JMP instruction
                t1 = REG;
                assert(strVect.size() == 3);
                source1 = strVect[1];
                t2 = NONE;
                source2 = "NONE";
                dest = strVect[2];
            } else if ( op >> 4 == 3){
                // The instruction has literal as one of the source
                t1 = REG;
                assert(strVect.size() == 4);
                source1 = strVect[1];
                t1 = REG;

                source2 = strVect[2];
                t2 = LITERAL;

                dest = strVect[3];
            } else {
                // Instructions have both sources as registers
                assert (strVect.size() == 4);
                t1 = REG;
                source1 = strVect[1];

                t2 = REG;
                source2 = strVect[2];
                
                dest = strVect[3];
            }

            BenchElem Bm (opcode, source1, source2, dest, t1, t2);
            
            B.add(pc, Bm);
            endBenchAddr = pc;
            pc += 4;

        }
    }
    B.setAddr(startBenchAddr, endBenchAddr);
    ip.close();
    return B;
}