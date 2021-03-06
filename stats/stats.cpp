#include "stats.h"

//-------------------------------------------
Statistics ::Statistics(){
    this -> value = 0;
    this -> info = "NA";
}

Statistics :: Statistics (string n, float v, string str) {
    this -> name = n;
    this -> value = v;
    this -> info = str;
}

float Statistics :: getValue(){
    return this->value;
}

string Statistics :: getInfo (){
    return this->info;
}

string Statistics :: getName (){
    return this->name;
}

void Statistics :: incrementVal(int v){
    value += float(v);
}
//----------------------------------------------
void Stat :: print (){
    map <string, Statistics> :: iterator itr;
    string name;
    Statistics s;

    for (itr= st.begin(); itr != st.end(); itr++){
        name = itr -> first;
        s = itr ->second;

        cout << name << " : " << s.getValue() << " , " << s.getInfo() << "\n";
    }
}

bool Stat :: find ( string name){
    if ( st.find(name) != st.end())
        return true;
    return false;
}

void Stat :: incrementStat (string name, int v){
    assert (find(name) == true);

    st[name].incrementVal(v);
    
}

//Adding statistics to stat data structure-------------------------------------------------------------
Stat createStatistics (){
    Stat statList;
    // Total cycle count
    Statistics cycleCount("cycleCount", 0, "This stats calculate total cycle time of a program.");
    statList.add(cycleCount.getName(), cycleCount);

    Statistics aluInstCount ("aluInstCount", 0, "This stat refers total alu instructions.");
    statList.add(aluInstCount.getName(), aluInstCount);

    Statistics branchInstCount ("branchInstCount", 0, "This stat refers to branch instruction count.");
    statList.add(branchInstCount.getName(), branchInstCount);

    Statistics booleanInstCount ("booleanInstCount", 0, "This stat refers to boolean instruction count.");
    statList.add(booleanInstCount.getName(), booleanInstCount);

    Statistics loadInstCount ( "loadInstCount", 0, "This stat refer to load instruction count.");
    statList.add(loadInstCount.getName(), loadInstCount);

    Statistics storeInstCount ("storeInstCount", 0, "This stat refers to store instruction count.");
    statList.add(storeInstCount.getName(), storeInstCount);

    Statistics totalInst ("totalInstCount", 0, "This stat refers to total instruction count in benchmark");
    statList.add(totalInst.getName(), totalInst);
    
    return statList;  
}
//---------------------------------------------------------------------------------------------------------