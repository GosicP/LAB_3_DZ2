//
// Created by Pavle on 7.1.2022..
//

#include "Posiljka.h"

int Posiljka::posiljka_id = 0;

Artikal &Posiljka::getArtikal() {
    return artikal;
}

int Posiljka::getId() const {
    return id;
}
