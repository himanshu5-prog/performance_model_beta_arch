#ifndef _STAT_
#define _STAT_

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

class Statistics {
    string name;
    float value;
    string info;

    public:
        Statistics();
        Statistics(string n, float v, string str);
        float getValue();
        string getName();
        string getInfo();
};

class Stat {
    map<string, Statistics> st;

    public:
        Stat() = default;
        Stat(string name, Statistics s){
            st.insert({name,s});
        }
        void add(string name, Statistics s){
            st.insert (  {name,s});
        }
        void print();
};

Stat createStatistics ();
#endif