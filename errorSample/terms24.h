
#ifndef EXCEPTIONAL_C___TERMS24_H
#define EXCEPTIONAL_C___TERMS24_H
#include "iostream"

using namespace std;

template <class T>
class MyList{
public:
    bool Insert(const T&, size_t index);
    T Access(size_t index) const;
    size_t Size() const;

private:
    T* buf;
    size_t bufsize_;
};

template <class T>
class MySet : private  MyList<T>{
public:
    bool Add(const T&);
    T Get(size_t index);

    using MyList<T>::Size;

};

template<class T>
class MySet1 : private MyList<T>{
public:
    bool Add(const T&);
    T Get(size_t index) const;

    using MyList<T>::Size;
};

template<class T>
class MySet2{
public:
    bool Add(const T&);
    T Get(size_t index) const;

    size_t Size() const;

private:
    MyList<T> impl_;
};
#endif //EXCEPTIONAL_C___TERMS24_H
