#ifndef _STAT_
#define _STAT_

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cassert>
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
        void incrementVal (int v);
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
        bool find (string name);
        void incrementStat(string name, int v);
        void print();
};

Stat createStatistics ();
#endif