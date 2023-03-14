#ifndef EXCEPTIONAL_C___TEMRS18_19_H
#define EXCEPTIONAL_C___TEMRS18_19_H

#include <memory>
#include "iostream"
#include "string"

using namespace std;

class Employee{
public:
    string Title(){
        return string("");
    };
    int Salary(){
        return 0;
    };
    string First(){
        return "";
    };
    string Last(){return "";};
};

//string EvaluateSalaryAndReturnName(Employee e){
//    if(e.Title() == "CEO" || e.Salary() == 0){
//        cout << e.First() << " " << e.Last() << "is overpaid" << endl;
//    }
//    return e.First() + " " + e.Last();
//}


unique_ptr<string> EvaluateSalaryAndReturnName(Employee e){
   unique_ptr<string> result = new string(e.First() + " " + e.Last());
   if(e.Title() == "CEO" || e.Salary() > 10000){
       string message = (*result) + " is overpaid\n";
       cout <<  message;
   }
   return result;
}
#endif //EXCEPTIONAL_C___TEMRS18_19_H
