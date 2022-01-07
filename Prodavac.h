
#ifndef LAB_3_DZ2_PRODAVAC_H
#define LAB_3_DZ2_PRODAVAC_H
#include "Posiljka.h"

class Prodavac : public Rukovalac {
private:

    struct tip_podatka_lista{
        Artikal artikal;
        double marza=0;
        int broj_dana_za_nabavku=0;

        /*tip_podatka_lista(Artikal a, double m, int bdzn): artikal(a){
            marza=m;
            broj_dana_za_nabavku=bdzn;
        }*/
        tip_podatka_lista()=default;

    };



    Lista<tip_podatka_lista> lista_katalog;

    double prodajna_cena_artikla=0;

    string naziv;

public:

    Prodavac(string name) : naziv(name){

    }


    const string &getNaziv() const {
        return naziv;
    }

    void dodajUKatalog(Artikal& a, double marge, int dani_nabavka){
        tip_podatka_lista katalog;
        katalog.artikal=a;
        katalog.marza=marge;
        katalog.broj_dana_za_nabavku=dani_nabavka;
        lista_katalog+=katalog;
    }

    void obrada(Posiljka& p){
        for(int i=0; i<lista_katalog.dohvBrojUListi(); i++){
            if(lista_katalog[i].artikal==p.getArtikal()){
                p.detalj.broj_dana_cekanja=p.detalj.broj_dana_cekanja+lista_katalog[i].broj_dana_za_nabavku;
                prodajna_cena_artikla=lista_katalog[i].artikal.getRealnaNabavnaCena()*lista_katalog[i].marza;
                p.detalj.cena_posiljke=p.detalj.cena_posiljke+prodajna_cena_artikla;
            }
        }
    }


};


#endif
