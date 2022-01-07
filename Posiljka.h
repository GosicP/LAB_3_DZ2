

#ifndef LAB_3_DZ2_POSILJKA_H
#define LAB_3_DZ2_POSILJKA_H
#include "Artikal.h"
#include "Rukovalac.h"

class GDohvatanje : public exception {
    const char* what() const noexcept override{
        return "***Dohvatanje pre izracunavanja";
    }
};

class GDodavanje : public exception {
    const char* what() const noexcept override{
        return "***Dodavanje pre izracunavanja";
    }
};

class Posiljka {
protected:

    struct Detalji{
        int broj_dana_cekanja=0;
        double cena_posiljke=0;
    };
    Artikal artikal;
    static int posiljka_id;
    int id = ++posiljka_id;
    Lista<Rukovalac*> lista_rukovalaca;
    bool stanje=false;

    virtual void pisi(ostream& os){
        os<<"POSILJKA"<<"["<<id<<","<<artikal.getNaziv()<<"]";
    }


public:

    Detalji detalj;

    Posiljka (Artikal article) : artikal(article){}

    void operator += (Rukovalac* rukovalac){
        if(stanje){
            throw GDodavanje();
        }
        lista_rukovalaca+=rukovalac;
    }

    void izracunajDetalje(){
       for (int i=0; i<lista_rukovalaca.dohvBrojUListi(); i++){
           lista_rukovalaca[i]->obrada(*this);
       }
       stanje=true;
    }

    Artikal &getArtikal();

    int getId() const;

    Detalji dohvDetalje(){
        if(stanje){
            throw GDohvatanje();
        }
        return detalj;
    }

    friend ostream& operator <<(ostream& os, Posiljka& p){}

};


#endif
