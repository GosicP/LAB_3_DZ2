

#ifndef LAB_3_DZ2_ARTIKAL_H
#define LAB_3_DZ2_ARTIKAL_H
#include "Lista.h"

class Artikal {
private:
    string naziv;
    int barkod, realna_nabavna_cena;

public:

    Artikal(string name, int barcode, int nabcena){
        naziv=name;
        barkod=barcode;
        realna_nabavna_cena=nabcena;
    }

    const string &getNaziv() const {
        return naziv;
    }

    int getBarkod() const {
        return barkod;
    }

    int getRealnaNabavnaCena() const {
        return realna_nabavna_cena;
    }

    bool operator ==(Artikal& a2){
        if(this->barkod==a2.barkod){
            return true;
        }else{
            return false;
        }
    }

};


#endif //LAB_3_DZ2_ARTIKAL_H
