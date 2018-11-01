#include <iostream>
#include "NoQ.hpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP
using namespace std;

template <typename T>
class Queue {
private:
    NoQ<T>* primeiro;
    NoQ<T>* final;
public:
    Queue():primeiro(nullptr),final(nullptr){
    }
    bool adiciona(T Valor){ // adiciona um numero, se ele for o primeiro numero, ele sera o final e o inicial, se nao o ultimo sera o novo numero e o antigo ultimo apontara para ele
        NoQ<T>*novo = new NoQ<T>(Valor);
        if(novo == nullptr) return false;
        if(primeiro == nullptr){
            primeiro = novo;
            primeiro->proximo = novo;
            final = novo;
            return true;
        }
        NoQ<T>* anterior = final;
        final = novo;
        anterior->proximo = final;
        final->proximo = nullptr;
        return  true;
    }

    T retira(){ //retira o primeiro valor da fila, transformando o numero a frente no novo "primeiro"
        if(primeiro == nullptr) return primeiro->Valor;
        NoQ<T>* proximo;
        proximo = primeiro;
        T valor = primeiro->Valor;
        delete primeiro;
        primeiro = proximo->proximo;
        return valor;
    }

    ~Queue() {
        while (primeiro != nullptr){
            retira();
            puts("apagando") ;//confirmando destrutor
        }
    }
};


#endif //FILA_DINAMICA_QUEUE_HPP
