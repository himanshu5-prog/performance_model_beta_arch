#include "stats.h"
#include "instruction.h"
#include "registers.h"

int main(){
    Stat stat = createStatistics();
    cout << "statistic:\n";
    stat.print();

    InstCollection instList = createInstructionList();
    cout << "Instructions: \n";
    instList.print();

    RegisterFile regFile = createRegisters();
    cout << " Registers:\n";
    regFile.print();


    return 0;
}