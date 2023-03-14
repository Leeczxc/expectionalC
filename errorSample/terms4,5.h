#include <cstddef>


#ifndef EXCEPTIONAL_C___TERMS4_5_H
#define EXCEPTIONAL_C___TERMS4_5_H

bool min(size_t a, size_t b){
    return a < b ? a : b;
}

//template<typename T, size_t size>
//class fixed_vector{
//public:
//    typedef T* iterator;
//    typedef const T* const_iterator;
//    iterator begin() {return v_;}
//    iterator end() {return v_ + size;};
//    const_iterator begin() const{return v_;}
//    const_iterator end() const{return v_ + size;}
//
//    template<class O, size_t osize>
//            fixed_vector(const fixed_vector<O, osize>& other){
//        copy(other.begin(),
//             other.begin() + min(size, osize),
//             begin());
//    }
//
//    template<class O, size_t osize>
//            fixed_vector<T, size>&
//            operator =(const fixed_vector<O, osize>& other){
//        copy(other.begin(),
//             other.begin() + min(size, osize),
//             begin());
//        return *this;
//    }
//
//private:
//    T v_[size];
//};


//template<class RAIter>
//fixed_vector(RAIter first, RAIter last){
//    copy(first, first + min(size, (size_t)last - first),
//         begin());
//}
//
//
//template<class RAIter>
//fixed_vector&
//assign(RAIter first, RAIter last){
//    copy(first, first + min(size, (size_t)last - first),
//    begin());
//    return *this;
//}

// 具有强异常安全性的版本
template<typename T, size_t size>
class fixed_vector{
public:

    typedef T* iterator;
    typedef const T* const_iterator;
    iterator begin() {return v_;}
    iterator end() {return v_ +size;}
    const_iterator begin() const {return v_;}
    const_iterator end() const {return v_ + size;}
    fixed_vector() : v_(new T[size]){ }
    ~fixed_vector() {delete[] v_; }

    template<class O, size_t osize>
            fixed_vector(const fixed_vector<O, osize>& other) : v_(new T[size]){
            try{
                copy(other.begin(), other.begin() + min(size, osize), begin());
            }catch (...){
                delete[] v_;
                throw;
            }
        }

    fixed_vector(const fixed_vector<T, size>& other) : v_(new T[size]){
        try {
            copy(other.begin(), other.end(), begin());
        }catch (...){
            delete [] v_;
            throw;
        }
    }

    void Swap(fixed_vector<T, size>& other) throw(){
        swap(v_, other.v_);
    }


    template<class O, size_t osize>
    fixed_vector<T, size>& operator=(const fixed_vector<O, osize>& other){
        fixed_vector<T, size> temp(other);
        Swap(temp);
        return *this;
    }

    fixed_vector<T, size>& operator=(const fixed_vector<T, size>& other){
        const fixed_vector<T, size> temp(other);
        Swap(temp);
        return *this;
    }


private:
    T* v_;
};
#endif //EXCEPTIONAL_C___TERMS4_5_H
