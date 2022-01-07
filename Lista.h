

#ifndef LAB_3_DZ2_LISTA_H
#define LAB_3_DZ2_LISTA_H
#include <exception>
#include <iostream>
using namespace std;


class GNemaElementa : public exception{
    const char* what() const noexcept override{
        return " ***Ne postoji podatak na toj poziciji";
    }
};

template<typename T>

class Lista {
private:

    struct node{
        T pod;
        node* next;
        int pozicija=0;
        node(T& podatak, node* sled=nullptr){
            pod=podatak;
            next=sled;
        }
    };

    node* first, *last, *tek;

    int ukupan_br=0;

    void kopiraj(const Lista& l);

    void premesti(Lista&& l){
        first=l.first;
        last=l.last;
        tek=l.tek;
    }

    void brisi();

public:

    Lista(){
        first=nullptr;
        last= nullptr;
        tek=nullptr;
    }

    Lista(Lista&& l){
        premesti(l);
    }
    Lista(const Lista& l){
        kopiraj(l);
    }
    ~Lista(){
        brisi();
    }

    Lista& operator += (T& podatak){
        last=(!first ? first : last->next)=new node(podatak);
        last->pozicija=ukupan_br;
        ukupan_br++;
        return *this;
    }

    int dohvBrojUListi(){
        return ukupan_br;
    }

    T& operator [](int i){
        for(node* temp=first; temp; temp=temp->next){
            if(i>ukupan_br){
                throw GNemaElementa();
            }

            if(temp->pozicija==i){
                return temp->pod;
            }
        }
    }



};

template<typename T>
void Lista<T>::kopiraj(const Lista& l){
    first=last=tek=nullptr;
    for(auto temp=l.first; temp; temp=temp->next){
        last=(!first ? first : last->next)=new node(temp->pod);
    }
}

template<typename T>
void Lista<T>::brisi(){
    while(first){
        node* temp=first;
        first=first->next;
        delete temp;
    }
    last=tek=nullptr;
}


#endif //LAB_3_DZ2_LISTA_H
