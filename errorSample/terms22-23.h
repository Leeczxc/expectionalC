#ifndef EXCEPTIONAL_C___TERMS22_23_H
#define EXCEPTIONAL_C___TERMS22_23_H
#include "iostream"

using namespace std;
class BasicProtocol{
public:
    BasicProtocol();
    virtual ~BasicProtocol();
    bool BasicMsgA();
    bool BasicMsgB();
    bool BasicMsgC();
};

class Protocol1 : public  BasicProtocol{
public:
    Protocol1();
    ~Protocol1();
    bool DoMsg1();
    bool DoMsg2();
    bool DoMsg3();
    bool DoMsg4();
};

class Protocol2 : public  BasicProtocol{
public:
    Protocol2();
    ~Protocol2();
    bool DoMsg1();
    bool DoMsg2();
    bool DoMsg3();
    bool DoMsg4();
};

class GenericTableAlgorithm{
public:
    GenericTableAlgorithm(const string& table){};
    virtual ~GenericTableAlgorithm();
    bool Process();

private:
    virtual bool  Filter(const Record&);
    virtual bool ProcessRow(const PrimaryKey&) = 0;
    struct GenericTableAlgorithmImpl* pimpl_;
};

class MyAlgorithm : public GenericTableAlgorithm{
    // 对函数Filter() 和 ProcessRow() 进行覆盖
    // 并实现具体操作
};
#endif //EXCEPTIONAL_C___TERMS22_23_H
