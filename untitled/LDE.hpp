#include <iostream>
#include "NoL.hpp"

#ifndef LDE_HPP
#define LDE_HPP

using namespace std;

template <typename T>
class LDE{
    private:
        int n;
        NoL<T>* primeiro;

    public:
        LDE(): n(0), primeiro(nullptr){

        }

        bool insere(T valor){
            NoL<T>* novo = new NoL<T>(valor);
            if(novo == nullptr)
                return false;

            NoL<T>* anterior = nullptr;
            NoL<T>* atual = primeiro;

            while(atual && valor > atual->valor){
                anterior = atual;
                atual = atual->proximo;
            }

            novo->proximo = atual;
            if(anterior!=nullptr){
                anterior->proximo = novo;
            }else{
                primeiro = novo;
            }
            n++;
            return true;
        }

        bool deletar(T valor){
            NoL<T>* atual = primeiro;
            NoL<T>* anterior;
            NoL<T>* proximo;

            while(atual && atual->valor != valor){
                anterior = atual;
                atual = atual->proximo;
            }
            if(atual->valor != valor) return false;
            proximo = atual->proximo;
            anterior->proximo = proximo;
            return true;
        }

    T busca(string valor){
            NoL<T>* atual = primeiro;
            NoL<T>* anterior;
            NoL<T>* proximo;
            while(atual && *(atual->valor) != valor){
                anterior = atual;
                atual = atual->proximo;
            }
            if(*(atual->valor) != valor) return atual->valor;

           // cout<<"a "<<atual->valor<<endl;
            return atual->valor;
        }

    void imprime(){
        NoL<T>* atual = primeiro;
        while(atual){
            cout << atual->valor << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    int getN() {
        return n;
    }

    T interador(int valor){
            NoL<T> * atual = primeiro;
            for(int i=0; i<valor; i++){
                atual = atual->proximo;
            }
        return atual->valor;
        }

    virtual ~LDE(){
        NoL<T>* atual = primeiro;
        NoL<T>* prox;
        while(atual){
            prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }

};

#endif