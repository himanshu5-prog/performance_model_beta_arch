#ifndef _REG_
#define _REG_

#include <iostream>
#include <map>
#include <cassert>
using namespace std;

 struct Register {
    bool reserved;
    int value;
    string name;
    string info;
 };

 class RegisterFile {
    map <string, Register> reg;
    public:
        RegisterFile() = default;
        void add (string name, Register r){
            reg.insert ({name, r});
        }
        bool findReg (string name){
            if (reg.find(name) != reg.end())
                return true;
            
            return false;
        }
        void changeRegInfo (string name, string info){
            assert (findReg(name));

            reg[name].info = info;
        }
        void changeReserveBit (string name, bool bit){
            assert (findReg(name));
            reg[name].reserved = bit;
        }
        void changeRegValue(string name, int value){
            assert (findReg(name));
            reg[name].value = value;
        }
        int readReg(string name){
            assert(name.length() > 0);
            if (!findReg(name))
                cout << " Error: Reg " << name << " is  not found\n";
            assert(findReg(name));
            return reg[name].value;
        }
        void print();
 };

 RegisterFile createRegisters();
#endif