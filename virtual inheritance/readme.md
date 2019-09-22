# Virtual Inheritance
Authors: Merijn Hendriks<br/>
License: [MIT License](https://github.com/MerijnHendriks/OOP-C89/blob/master/LICENSE)<br/>
Compile: ```clang main.c -std=c89 -Weverything -Wno-padded```

Both B and C contain an instance of A. Which is the real one?
```
   / B \
 D       A
   \ C /
```

This implementation tries to solve the diamond problem in C.

Unlike C++'s implementation, this version doesn't involve VTT's. Instead, an instance of the struct contains an additional pointer that points to the reference of the inherited struct instance. In this case, both B and C inherit A, of which D inherits B and C. B's baseA is the instance which B's virtualA and c's virtualA point to.

```
  / B (virtualA -> baseA)     \
D                               A
  \ C (virtualA -> B's baseA) /
```

When using this implementation, use the virtual pointer to manipulate the inherited instance and pass the instance reference top-down in the constructor. Initialize the instances bottom-up.
