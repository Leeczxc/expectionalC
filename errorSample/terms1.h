#ifndef EXCEPTIONAL_C___TERMS1_H
#define EXCEPTIONAL_C___TERMS1_H

#include <sstream>
#include "iostream"
#include "vector"
#include "istream"
#include "iterator"

using namespace std;

class Date{};

int main(){
    vector<Date> e;

//  z
    copy(istream_iterator<Date>( cin),
         istream_iterator<Date>(),
                 back_inserter(e));

}
#endif //EXCEPTIONAL_C___TERMS1_H
