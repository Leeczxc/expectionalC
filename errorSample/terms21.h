#ifndef EXCEPTIONAL_C___TERMS21_H
#define EXCEPTIONAL_C___TERMS21_H
#include "iostream"
#include "complex"

using namespace std;

class Base{
public:
    virtual  void f(int);
    virtual void f(double);
    virtual void g(int i = 10);
};

void Base::f(int) {
    cout << "Base::f(int)" <<endl;
}

void Base::f(double) {
    cout <<"Base::f(double)" << endl;
}

void Base::g(int i) {
    cout << i << endl;
}

class Deried : public Base{
public:
    void f(complex<double>);
    void g(int i = 20);
};

void Deried::f(complex<double>) {
    cout << "Derived::f(complex)" << endl;
}

void Deried::g(int i) {
    cout << "Derived::g()" << i << endl;
}


#endif //EXCEPTIONAL_C___TERMS21_H
