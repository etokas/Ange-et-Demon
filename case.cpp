//
//  case.cpp
//  2CPP Ange Et Demon
//
//  Created by Etok's Sylva on 11/02/2015.
//  Copyright (c) 2015 Etok's Sylva. All rights reserved.
//

#include "case.h"

//======================================
//          IMPLEMENTAION CASE
//======================================

Case::Case(): _broken(false), _free(true) {}

Case::Case(bool d, bool l):_broken(d), _free(l) {}

Case Case::setCase(bool bro, bool fre) {

    _broken = bro; _free = fre;
    
    return *this;
}

//======================================
//          IMPLEMENTATION PLATEAU
//======================================

void Plateau::delimiter(int n) {
    
    for (int i = 0; i < n ; i++) {
        cout << "+---";
    }
    cout << "+" << endl;
}


Plateau::Plateau(): _dim(35) {
    
    _gameboard = new Case * [_dim];
    for (int i = 0; i  < _dim; i++) {
        _gameboard[i] = new Case[_dim];
    }
    _gameboard[_dim/2][_dim/2].setCase(false, false);

}

Plateau::Plateau(int d) {
    /*    // on prends la valeur absolue de "d" et on fait  + 1 
    si l'utilsateur saisie un nombre negatif */
    
    ((d % 2) != 0) ? _dim = abs(d) : _dim = abs(d) + 1;

    _gameboard = new Case * [_dim];
    for (int i = 0; i  < _dim; i++) {
        _gameboard[i] = new Case[_dim];
    }
    _gameboard[_dim/2][_dim/2].setCase(false, false);

}

void Plateau::affiche() {
    
    delimiter(_dim);
    for (int i = 0; i < _dim; i++) {
        for (int j = 0; j < _dim; j++) {
            cout << "|";
            
            if (_gameboard[i][j].free()) {
                cout << " . ";
            }else if(_gameboard[i][j].broken()) {
                cout << " X ";
            }else{
                cout << ">O<";
            }
        }
        cout << "| " << i + 1 << endl;
        delimiter(_dim);
    }
}


Plateau::Plateau(const Plateau &obj) {

    _dim = obj._dim;
    _gameboard = obj.gameboard();
}


Plateau& Plateau::operator=(const Plateau &obj) {

    if (this != &obj) {
        _dim = obj.dim() ;
        _gameboard = obj.gameboard();
    }
    return *this;
}


Plateau& Plateau::operator++(int) {
    
    //Je copie mon tableau dans un plateau temporaire
    Case * tempo[_dim][_dim];
    for (int i = 0; i < _dim; i++) {
        for (int j = 0; j < _dim; j++) {
            tempo[i][j] = &_gameboard[i][j];
        }
    }
    
    //J'efface l'ancien tableau

    delete _gameboard;

    _dim += 2;
    
    //je crée un tableau tout propre
    _gameboard = new Case * [_dim];
    for (int i = 0; i < _dim; i++) {
        _gameboard[i] = new Case[_dim];
    }
    
    
    //et je copie l'ancien dans le nouveau
    for (int i = 1; i < _dim - 1; i++) {
        for (int j = 1; j < _dim - 1; j++) {
            _gameboard[i][j] = *tempo[i - 1][j - 1];
        }
    }

    //Je renvoie son adresse.
    return *this;
}




Plateau::~Plateau() {

    for (int i = 0; i < _dim; i++) {
        delete [] _gameboard[i];
    }
    delete [] _gameboard;
}

