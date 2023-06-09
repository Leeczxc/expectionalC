#ifndef EXCEPTIONAL_C___TERMS2_3_H
#define EXCEPTIONAL_C___TERMS2_3_H
#include "iostream"
#include "vector"
#include "cstring"
using namespace std;

struct ci_char_traits : public char_traits<char>{
    static bool eq(char c1, char c2){
        return toupper(c1) == toupper(c2);
    }

    static bool lt(char c1, char c2){
        return toupper(c1) < toupper(c2);
    }

    static int compare(const char* s1, const char* s2, size_t n){
        return memicmp(s1, s2, n);
    }

    static const char*
    find(const char* s, int n, char a){
        while(n-- > 0 && toupper(*s) != toupper(a))
            ++s;
        return n >= 0 ? s : 0;
    }
};

typedef basic_string<char, ci_char_traits> ci_string;

template<class charT, class traits, class Allocator>
basic_ostream<charT, traits>&
        operator <<(basic_ostream<charT, traits>& os, const basic_string<charT, traits, Allocator>& str);

#endif //EXCEPTIONAL_C___TERMS2_3_H
