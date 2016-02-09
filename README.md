# ACX 
Kernel written for an atmega2560

- [X] x_init
  - [X] Create protoypes, C files, and makefile
  - [X] Create all stubs
  - [X] Initialize all globals (timer, delay counter, etc)
  - [X] initialize kernel data structures, create all threads, place canarys
- [X] x_new
  - [X] Create thread0 function
  - [X] Set up new stack for thread0 (first three for ret address and 18 for callee save registers)
  - [X] Set disable variable 
