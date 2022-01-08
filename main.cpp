#include <iostream>
using namespace std;
#include "Prodavac.h"
int main() {
    string naziv;
    Artikal a1("Noblice", 123, 100);
    Artikal a2("Olovka", 105, 50);
    Artikal a3("Tunjevina", 202, 150);

    Prodavac p("Pavle");

    Posiljka posiljka(a1);

    p.dodajUKatalog(a1, 0.23, 5);
    p.dodajUKatalog(a2, 0.2, 11);

    p.obrada(posiljka);


    //cout<<posiljka;

    cout<<p;




    return 0;
}
