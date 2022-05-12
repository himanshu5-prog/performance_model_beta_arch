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