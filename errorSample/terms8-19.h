#ifndef EXCEPTIONAL_C___TERMS8_19_H
#define EXCEPTIONAL_C___TERMS8_19_H

#include <cassert>
#include "iostream"
#include "vector"

using namespace std;


template<class T>
class Stack {
public:
    Stack();
    ~Stack();
    Stack(const Stack&);
    Stack& operator=(const Stack&);
    size_t Count() const;
    void Push(const T&);
    T Pop(); // 如果Stack对象为空，则抛出异常
    const T& Top() const;
    bool Empty();

private:
    T* v_;
    // 能够容纳的T对象数量
    size_t vsize_;
    // 实际容纳的T对象数量
    size_t vused_;
};

template<class T>
Stack<T>::Stack() : v_(0), vsize_(10), vused_(0){
    v_ = new T[vsize_];
}

template<class T>
Stack<T>::~Stack(){
    delete [] v_;
}

template<class T>
T* NewCopy(const T* src, size_t srcsize, size_t destsize){
    assert(destsize > srcsize);
    T* dest = new T[destsize];
    try{
        copy(src, src + srcsize, dest);
    }catch (...){
        delete[] dest;
        throw;
    }
    return dest;
}

template<class T>
Stack<T>::Stack(const Stack<T>& other) : v_(NewCopy(other.v_, other.vsize_, other.vsize_)),
vsize_(other.vsize_), vused_(other.vused){

}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T> &other) {
    if(this != other){
        T* v_new = NewCopy(other.v_, other.vsize_, other.vsize_);
        delete[] v_;
        v_ = v_new;
        vsize_ = other.vsize_;
        vused_ = other.vused_;
    }
    return *this;
}

template<class T>
size_t Stack<T>::Count() const {
    return vused_;
}

template<class T>
void Stack<T>::Push(const T& t) {
    if(vused_ == vsize_){
        size_t vsize_new = vsize_ * 2 + 1;
        T* v_new = NewCopy(v_, vsize_, vsize_new);
        delete[] v_;
        v_ = v_new;
        vsize_ = vsize_new;
    }
    v_[vused_] = t;
    ++vused_;
}

template<class T>
const T& Stack<T>::Top() const {
    if(vused_ == 0)
        throw "empty stack";
    else
        return v_[vused_ - 1];
}

template<class T>
bool Stack<T>::Empty() {
    return vused_ == 0;
}

template<class T>
class StackImpl{
    StackImpl(size_t size = 0);
    ~StackImpl();
    void Swap(StackImpl& other) throw();

    T* v_;
    size_t vsize_;
    size_t vused_;

private:
    StackImpl(const StackImpl);
    StackImpl& operator=(const StackImpl&);
};


template<class T>
StackImpl<T>::StackImpl(size_t size) :
v_(static_cast<T*>(size == 0 ? 0 : operator new(sizeof(T) * size))), vsize_(size), vused_(0){

}

template<class T>
StackImpl<T>::~StackImpl(){
    destroy(v_, v_ + vused_);
    operator delete(v_);
}

template<class T>
void StackImpl<T>::Swap(StackImpl<T> &other) throw() {
    swap(v_, other.v_);
    swap(vsize_, other.vsize_);
    swap(vused_, other.vused_);
}


#endif //EXCEPTIONAL_C___TERMS8_19_H
