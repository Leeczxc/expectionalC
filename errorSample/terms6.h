#ifndef EXCEPTIONAL_C___TERMS6_H
#define EXCEPTIONAL_C___TERMS6_H
#include "string"
#include "iostream"
#include "list"
#include "algorithm"

using namespace std;

class Employee{
public:
    string addr;
    string name;

    bool operator==(string b) const{
        return this->name == b;
    }
};

//string FindAddr(const list<Employee>& emps, const string& name){
//    auto ite =emps.cend();
//    for(list<Employee>::const_iterator i = emps.begin(); i != ite; i++){
//        if(i->name == name)
//            return i->addr;
//    }
//    return "";
//}

string FindAddr(const list<Employee>& emps, const string& name){
    list<Employee>::const_iterator i(
            find(emps.begin(), emps.end(), name)
            );
    if(i != emps.end()){
        return i->addr;
    }
    return "";
}
#endif //EXCEPTIONAL_C___TERMS6_H
