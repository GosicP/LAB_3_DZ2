#include <iostream>
using namespace std;
#include "Prodavac.h"
int main() {
    string naziv;
    Artikal a1("Noblice", 123, 100);
    Artikal a2("Olovka", 105, 50);
    Artikal a3("Tunjevina", 202, 150);

    Prodavac *prodavac=new Prodavac("Pavle");

    Posiljka posiljka(a1);

    prodavac->dodajUKatalog(a1, 0.23, 5);
    prodavac->dodajUKatalog(a2, 0.2, 11);

    //prodavac->obrada(posiljka);

    posiljka+=prodavac;



    posiljka.izracunajDetalje();


    cout<<posiljka;

    cout<<*prodavac;




    return 0;
}
