#include <iostream>
#include "errorSample/terms21.h"
int main() {
    Base b;
    Deried d;
    Base* pd = new Deried;
    b.f(1.0);
    d.f(1.0);
    pd->f(1.0);
    b.g();
    d.g();
    pd->g();
}