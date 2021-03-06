# Virtual Inheritance
Both B and C contain an instance of A. Which is the real one?
```
     A
   /   \
 B       C
   \   /
     D
```

This implementation tries to solve the diamond problem in C.

Unlike C++'s implementation, this version doesn't involve VTT's. Instead, an instance of the struct contains an additional pointer that points to the reference of the inherited struct instance. In this case, both B and C inherit A, of which D inherits B and C. B's baseA is the instance which B's virtualA and c's virtualA point to.

```
     A
   /   \
 B <---- C
   \   /
     D

B: virtualA -> baseA
C: virtualA -> B's baseA
```

When using this implementation, use the virtual pointer to manipulate the inherited instance and pass the instance reference top-down in the constructor. Initialize the instances bottom-up.
