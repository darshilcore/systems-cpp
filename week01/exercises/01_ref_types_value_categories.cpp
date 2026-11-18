#include <iostream>

void pass_copy(int i) { //:1.1
    i = 10; //:1.2
}
void pass_lvref(int& x) { //:4.1
    x = 10; //:4.3
} 
void pass_rvref(int&& x) { //:5.1 - :5.4
    x = 10;
}
int main() {
    pass_copy(10); //:1.1, :3.2
    int x = 1; //:2.1
    pass_lvref(x); //:4.2, :2.1
    pass_rvref(1); //:5.3, :3.1, :3.2 
}

/*
Experiment Notes

1. What is a copy?
-> Process of creating a duplicate of an existing variable or object in the memory.
   For Example: 
   1.1* Integer i in pass_copy func is a variable that obtains either an rvalue or an lvalue and stores it in a new local memory location. 
   1.2* Changing the value of i does not change the value of the lvalue it was copied from.

2. What is an Lvalue?
-> 2.1* Expressions that have an identity in the memory.
   2.2* What is an identity?
   -> An exoression has an identity when it has persistent (non-temporary) memory address that you can access using &.

3. What is an Rvalue?
-> 3.1* An rvalue is either a prvalue or an xvalue (expiring value).
   3.2* What is a prvalue?
   -> A pure rvalue is an expression that initializes an object or computes a value that does not have an identity in the memory.
   3.3* What is an xvalue?
   -> An lvalue expression (has indentity) whose resources can be safely reused/moved from, an object that is nearing the end of its lifespan, whose identity in the memory is temporary.  

4. Pass by Lvalue Reference (int&)
-> 4.1* The func pass_lvref is an example of passing an argument by lvalue reference.
   4.2* The data type int& is an lvalue reference to int and hence pass_lvref cannot accept rvalues as arguments.
   4.3* Rule: An lvalue reference to non-const (int&) binds to immutable lvalues. Which meams a change of value of i would also result in the change of value of the lvalue.

5. Pass by Rvalue Reference (int&&)
-> 5.1* The func pass_rvref is an exammple of passing an argument by rvalue reference.
   5.2* The data type int&& is an rvalue reference to int and hence pass_rvref cannot accept lvalues as arguments.
   5.3* Rule: Am rvalue reference of type T&& can bind to an rvalue (pr and x) of type U if T and U are reference-compatible.
   5.4. Binding to a prvalue 
   ->   5.4.1* A prvalue does not have an identity in the memory.
        5.4.2* The compiler materializes a temporary object in the memory to store the prvalue.
        5.4.3* The prvalue is assigned to the memory and hence becomes an xvalue.
        5.4.4* The rvalue reference binds to the xvalue and the lifetime of the xvalue is updated to match the scope of the rvref.
   5.5. Binding to an xvalue
   ->   5.5.1* The rvalue reference directly binds to the xvalue because an xvalue
        already has an identity in the memory.
*/ 