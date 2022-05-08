#include "stats.h"

int main(){
    Statistics cycleCount (23, "This stats shows the total cycle count\n");

    float f = cycleCount.getValue();

    cout << "f: " << f << "\n"; 
    cout << "info: " << cycleCount.getInfo() << "\n";
}