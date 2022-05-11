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
    if (ip.is_open()){
        string str;
        while( getline(ip,str)){
            strVect = sepLine(str);
            cout << str << "\n";
            printStringVect(strVect);
            assert(instCollection.find(strVect[0]));
            cout << "opcode: " << instCollection.getOpcode(strVect[0]) << "\n";
        }
    }
    ip.close();
    return B;
}