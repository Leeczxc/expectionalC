#ifndef EXCEPTIONAL_C___TERMS31_35_H
#define EXCEPTIONAL_C___TERMS31_35_H
#include "iostream"

namespace A{
    struct X;
    struct Y;
    void f(int);
    void g(X);
}

namespace B{
    void f(int i){
        f(i);
    }

    void g(A::X x){
        g(x);
    }

    void h(A::Y y){
        h(y);
    }
}

#endif //EXCEPTIONAL_C___TERMS31_35_H
