# performance_model_beta_arch

This repository contains source files to perform performance modelling of a single-cycle processor based on Beta architecture. This architecture is taught at MIT and course info can be
found at this url: https://ocw.mit.edu/courses/6-004-computation-structures-spring-2017/pages/c13/

Following are the statistics which are generated:

1) cycleCount : Total Cycle required to complete the program
2) aluInstCount: number of alu instructions executed
3) branchInstCount: Number of branch instructions executed
4) booleanInstCount: Number of boolean instructions executed
5) loadInstCount: Number of load instructions executed
6) storeInstCount: Number of store instructions executed
7) totalInstCount: Total number of instructions executed

All benchmark files are in benchmark directory.

The file name is provided in perf_model.cpp and it is provided as an argument for creating data structure for benchmark.

Compiling th code:
**source compile.tcl**

Compile + run the code:
**source run.tcl**
