#include <iostream>
#ifndef NOQ_HPP
#define NOQ_HPP
template <typename T>
class Queue;
template <typename T>

class NoQ {
private:
    T Valor;
    NoQ* proximo;
    NoQ(T valor): Valor(valor),proximo(nullptr){
    }
public:
    ~NoQ(){
    }
    friend class Queue<T>;
};


#endif //FILA_DINAMICA_NO_H
