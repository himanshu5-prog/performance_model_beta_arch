#include "stats.h"
#include "instruction.h"

int main(){
    Stat stat = createStatistics();
    cout << "statistic:\n";
    stat.print();

    InstCollection instList = createInstructionList();
    cout << "Instructions: \n";
    instList.print();

    return 0;
}