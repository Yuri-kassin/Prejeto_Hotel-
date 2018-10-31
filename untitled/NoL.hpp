#ifndef NOL_HPP
#define NOL_HPP

#include <iostream>
using namespace std;

template <typename T>
class LDE;

template <typename T>
class NoL{
    private:
        T valor;
        NoL<T>* proximo;
        NoL(T valor): valor(valor), proximo(nullptr){
        }
    public:
        ~NoL(){
        }

    friend class LDE<T>;

};


#endif