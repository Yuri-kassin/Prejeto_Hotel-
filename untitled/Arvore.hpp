#ifndef ARVORE_HPP
#define ARVORE_HPP
#include "LDE.hpp"
#include "No.hpp"
#include "Coisa.hpp"
#define MAX(a,b) (( (a) > (b) ) ? (a) : (b))


using namespace std;
template <typename T>
class Arvore {
private:
    LDE<Coisa> *odn;
    int n;
    No<T>*raiz;
    void edr(No<T>* r){
//        puts("printanduuu");
        if(r){
            edr(r->Dirt);
           // cout << **r << endl;
            edr(r->Esqr);
        }
    }

    void erd(No<T>* r){
//        puts("printanduuu");
        if(r){
            erd(r->Esqr);
//            if(r->anterior)cout<<"anterior "<<**(r->anterior)<<endl;
            Coisa y = r->getonlyValor();
            odn->insere(y);
            //ui->stackedWidget->setCurrentIndex(1);
            //cout<<y.getNumero()<<endl;
            // cout << **r << endl;
//            if(r->Esqr)cout<<"esquerda "<<**(r->Esqr)<<endl;
//            if(r->Dirt)cout<<"direita "<<**(r->Dirt)<<endl;
            erd(r->Dirt);
        }
    }
    void red(No<T>* r){
        if(!r) return;
        cout<<**r<<endl;
        red(r->Esqr);
        red(r->Dirt);
    }
public:
    Arvore():n(0),raiz(nullptr){
    }

    LDE<Coisa>* erdd(){
        odn = new LDE<Coisa>;
        erd(raiz);
        return odn;
    }


    void edr(){
        edr(raiz);
    }
    void red(){
        red(raiz);
    }
    No<T>* busca(string valor){
        No<T>* atual = raiz;
    //    cout<<atual->getValor()<<endl;
        while(atual){
            if(valor==*(atual->valor))
              //  cout<<*(atual->valor);
                return atual;

            if(valor <= *(atual->valor)){
                atual = atual->Esqr;
            }else{
                atual = atual->Dirt;
            }
        }
        if(!atual || valor!=*(atual->valor))  return nullptr;
    }



    int altura(No<T>* n){
        if(!n) return -1;
        return MAX(altura(n->Esqr),altura(n->Dirt))+1;
    }

    int fb(No<T>* no){

        return altura(no->Dirt) - altura(no->Esqr);
    }

    void giradireita(No<T>* n){
//        cout<<"aqui "<<n->valor<<endl;
        No <T> * nd = n->Dirt;


        if(n == raiz) raiz = nd;
        else {
            if (n == n->anterior->Dirt)
                (n->anterior)->Dirt = nd;
            else
                (n->anterior)->Esqr = nd;
        }
        n->Dirt = nd->Esqr;
        if(n->Dirt) (n->Dirt)->anterior = n;
        nd->Esqr = n;
        nd->anterior = n->anterior;
        n->anterior = nd;
    }

     void giraesquerda(No<T>* n){
//        cout<<"AQUI "<<n->valor<<endl;
        No <T> * ne = n->Esqr;

        if(n == raiz) raiz = ne;
        else {
            if (n == n->anterior->Dirt)
                (n->anterior)->Dirt = ne;
            else
                (n->anterior)->Esqr = ne;
        }

        n->Esqr = ne->Dirt;
        if(n->Esqr)(n->Esqr)->anterior = n;
        ne->Dirt = n;
        ne->anterior = n->anterior;
        n->anterior = ne;

    }

    void balanceie(No<T>* n){
        while(n){
//            cout<<"hmmmmm "<<n->valor<<endl;
            if(fb(n)>=2){
//                cout<<"entrou "<<n->valor<<endl;
//                cout<<fb(n)<<endl;
                if(n->Dirt && fb(n->Dirt) < 0){
//                    cout<<"??"<<endl;
//                    cout<<"n "<<n->valor<<endl;
                    giraesquerda(n->Dirt);
                }
//                cout<<"direita "<<n->valor<<endl;
                giradireita(n);
            }
            else if(fb(n)<= -2){
//                cout<<"entrou "<<n->valor<<endl;
//                cout<<"nnnnnnnnn "<<fb(n)<<endl;
                if(fb(n->Esqr) > 0){
//                    cout<<"n "<<n->valor<<endl;
//                    cout<<"? "<<fb(n->Esqr)<<endl;
                    giradireita(n->Esqr);
                }
//                cout<<"esquerda "<<n->valor<<endl;
                giraesquerda(n);
            }
            n = n->anterior;
        }
    }

    int contaFilhos(No<T>* x){
        return (x->Esqr!=NULL)+(x->Dirt!=NULL);
    }

    No<T>** ponteiroDoPai(No<T>* p){
        if(p->anterior->Esqr == p){
            return &(p->anterior->Esqr);
        }else{
            return &(p->anterior->Dirt);
        }
    }

    void remove(T valor){
        No<T>* x = busca(valor);
        if(!x)
            return;

        int filhos = contaFilhos(x);
        if(filhos == 0){
             No<T>* y ;
            if(x != raiz){
                *ponteiroDoPai(x) = nullptr;
                y = x->anterior;
            }
            delete x;
            if(x!= raiz)balanceie(y);
        }
        else if(filhos == 1){
            No<T> *f = x->Esqr;
            if(!f) f = x->Dirt;

            if(x != raiz)*ponteiroDoPai(x) = f;
            else raiz = f;
            f->anterior = x->anterior;
            delete x;
            balanceie(f);
        }
        else{
            //bool aux = false;
            No<T> *atual = x;
            No<T> *anterior;
            //if(x==raiz) aux = true;
            while(contaFilhos(atual)!=0){
                atual->valor = (atual->Dirt)->valor;
                anterior = atual;
                atual = atual->Dirt;
                if(atual->Dirt) atual = atual->Esqr;
            }
            anterior->valor = atual->valor;
            *ponteiroDoPai(atual) = nullptr;
            delete atual;

        }
        if(raiz) balanceie(raiz);
    }

    bool insere(T valor){
        No<T>* novo = new No<T>(valor);
        if(novo == nullptr) return false;
        No<T>*atual = raiz;
        No<T>*ant = nullptr;
        while(atual){
            ant = atual;
            if(valor <= atual->valor) atual = atual->Esqr;

            else atual = atual->Dirt;
        }

        //if(atual)atual->anterior = ant;

        if(ant) {
            if(valor <= ant->valor){
                ant->Esqr = novo;
                (ant->Esqr)->anterior = ant;
            }
            else{
                ant->Dirt = novo;
                (ant->Dirt)->anterior = ant;
            }
        }

        else{
            raiz = novo;
        }
        n++;
//        cout<<"fodeu "<<valor<<endl;
        balanceie(novo->anterior);
//        cout<<"--------------------"<<endl;
//        erd();
//        cout<<"-------------------"<<endl<<endl;
        return true;
    }

};


#endif //ARVORE_AVL_ARVORE_HPP
