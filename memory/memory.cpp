#include "memory.h"

void Memory :: add (int addr, int v){
    mem.insert ({addr,v});
}

bool Memory :: find (int addr){
    if ( mem.find(addr) != mem.end())
        return true;
    
    return false;
}

int Memory :: getValue(int addr){
    assert (find(addr));

    return mem[addr];

}

//Creating memory. 64 entry with value set to 0
void Memory :: createMem(){
    for (int i=0; i<64; i++){
        add(i,0);
    }
}
//---------------------------------------------

void Memory :: print(){
    map <int, int> :: iterator itr;
    cout << "addr  :  data\n";
    for (itr = mem.begin(); itr != mem.end(); itr++){
         cout << itr->first << " : " << itr->second << "\n";
    }
}

void Memory :: store(int addr, int value){
    assert (find(addr));
    mem[addr] = value;
}