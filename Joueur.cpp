//
//  Joueur.cpp
//  2CPP Ange Et Demon
//
//  Created by Etok's Sylva on 12/02/2015.
//  Copyright (c) 2015 Etok's Sylva. All rights reserved.

#include "Joueur.h"

//=========================================================================
//          IMPLEMENTATION JOUEUR 
//=========================================================================

void Joueur::verifier(int &valeur, string message) {

    do {
        
        if(cin.fail()) {

            cout << "Saisie incorrect" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cout << message << " : "; cin >> valeur;

    } while (cin.fail());
}


Joueur::Joueur(string ps): _pseudo(ps)  {}

void Joueur::saisir(int &numLigne, int &numColonne) {

    verifier(numLigne, "Entrez un numero de ligne");
    verifier(numColonne, "Entrez un numero de colonne");
    cout << endl;
    
    numLigne -= 1, numColonne -= 1;
}

void Joueur::choisirCase(int &ligne, int &colonne, Plateau &plateau) {

    do {
        saisir(ligne, colonne);
    } while (!incorrect(ligne, colonne, plateau));
}


void Joueur::jouer(Plateau &plateau) {

    int ligne, colonne;
    choisirCase(ligne, colonne, plateau);
    modifierCase(ligne, colonne, plateau);
}


//=========================================================================
//          IMPLEMENTATION ANGE
//=========================================================================


Ange::Ange(string ps, int l, int c):Joueur(ps), _ligne(l), _colonne(c) {}

bool Ange::incorrect(int &ligne, int &colonne, Plateau &plateau) {

    if(ligne < 0 || colonne < 0 || ligne > plateau.dim() - 1 || colonne > plateau.dim() - 1) {
        cout << "Cette case n'existe pas !!" << endl;
        return false;

    } else if(!plateau.gameboard()[ligne][colonne].broken() && !plateau.gameboard()[ligne][colonne].free()) {
        cout << "Vous êtes deja dessus !!" << endl;
        return false;

    } else if(plateau.gameboard()[ligne][colonne].broken() && !plateau.gameboard()[ligne][colonne].free()) {
        cout << "Case deja detruite !!" << endl;
        return false;

    } else {
        if(_colonne - 1 <= colonne && colonne <= _colonne + 1 && _ligne - 1 <= ligne && ligne <= _ligne + 1) {
            return true;

        } else {
            cout << "Vous pouvez bouger que d'une case" << endl;
            return false;
        }
    }
}

// la methode qui va tester si l'ange est arrivé aux coins des cases
bool Ange::gagne(Plateau &plateau) {

    if (_ligne == 0 || _ligne == plateau.dim() - 1 || _colonne == 0 || _colonne == plateau.dim() - 1) {
        plateau.affiche();
        cout << "Bravo !! vous avez gagné \n" << endl;
        return true;
    }
    return false;
}


void Ange::modifierCase(int &ligne, int &colonne, Plateau &plateau) {

    plateau.gameboard()[_ligne][_colonne].setCase(false, true);

    plateau.gameboard()[ligne][colonne].setCase(false, false);
    
    _ligne = ligne, _colonne = colonne;
}


//=========================================================================
//          IMPLEMENTATION ANGE PUISSANT
//=========================================================================



AngePuissant::AngePuissant(string ps,int l, int c, int p): Ange(ps,l,c), _puissance(p) {}

bool AngePuissant::incorrect(int &ligne, int &colonne, Plateau &plateau) {

    if (ligne < 0 || ligne > plateau.dim() - 1 || colonne < 0 || colonne > plateau.dim() - 1) {
        cout << "Cette case n'existe pas " << endl;
        return false;

    }else if(!plateau.gameboard()[ligne][colonne].broken() && !plateau.gameboard()[ligne][colonne].free()) {
        cout << "Vous êtes deja dessus !!\n" << endl;
        return false;

    } else if (plateau.gameboard()[ligne][colonne].broken() && !plateau.gameboard()[ligne][colonne].free()) {
        cout << "Case deja detruite !!\n" << endl;
        return false;
        
    }else{
        
        if (_colonne - _puissance <= colonne && colonne <= _colonne + _puissance && _ligne - _puissance <= ligne && ligne <= _ligne + _puissance) {
            return true;

        }else{
            cout << "Vous pouvez bouger que de " << _puissance << " cases" << endl;
            return false;
        }
    }
}


void AngePuissant::modifierCase(int &ligne, int &colonne, Plateau &p) {

    p.gameboard()[_ligne][_colonne].setCase(false, true);

    p.gameboard()[ligne][colonne].setCase(false, false);
 
    _ligne = ligne, _colonne = colonne;  //Je sauvegarde mes coordonées afin de faire les test plsu tard dans incorrect.
}


// la methode qui va tester si l'ange puissant est arrivé aux coins des cases
bool AngePuissant::gagne(Plateau &plateau) {
    
    if (_ligne == 0 || _ligne == plateau.dim() - 1 || _colonne == 0 || _colonne == plateau.dim() - 1) {
        plateau.affiche();
        cout << "Bravo !! vous avez gagné \n" << endl;
        return true;
    }
    
    return false;
}


//=========================================================================
//          IMPLEMENTATION DEMON
//=========================================================================


Demon::Demon(string ps):Joueur(ps) {}

void Demon::modifierCase(int &ligne, int &colonne, Plateau &plateau) {
    plateau.gameboard()[ligne][colonne].setCase(true, false);
}


bool Demon::incorrect(int &ligne, int &colonne, Plateau &plateau) {

    if (ligne < 0 || colonne < 0 || ligne > plateau.dim() - 1 || colonne > plateau.dim() - 1) {
        cout << "Entrez une case valide !!\n" << endl;
        return false;

    }else if (!plateau.gameboard()[ligne][colonne].free() && plateau.gameboard()[ligne][colonne].broken()) {
        cout << "La case est déja detruite !!\n" << endl;
        return false;

    }else if (!plateau.gameboard()[ligne][colonne].broken() && !plateau.gameboard()[ligne][colonne].free()) {
        cout << "Case occupée par l'ange !!\n" << endl;
        return false;

    }else{
        return true;
    }

}


// methode qui teste si le demon entoure l'ange de case detruite
bool Demon::gagne(Plateau &plateau) {

    for (int i = 0; i < plateau.dim(); i++) {

        for (int j = 0; j < plateau.dim(); j++) {

            if ((!plateau.gameboard()[i][j].broken() && !plateau.gameboard()[i][j].free()) && // Position ange
                (plateau.gameboard()[i + 1][j].broken() && !plateau.gameboard()[i + 1][j].free()) && // bas
                (plateau.gameboard()[i - 1][j].broken() && !plateau.gameboard()[i - 1][j].free()) && // haut
                (plateau.gameboard()[i][j - 1].broken() && !plateau.gameboard()[i][j - 1].free()) && // gauche
                (plateau.gameboard()[i][j + 1].broken() && !plateau.gameboard()[i][j + 1].free()) && // droite
                (plateau.gameboard()[i - 1][j + 1].broken() && !plateau.gameboard()[i - 1][j + 1].free()) && // droite haut
                (plateau.gameboard()[i - 1][j - 1].broken() && !plateau.gameboard()[i - 1][j - 1].free()) && // gauche haut
                (plateau.gameboard()[i + 1][j + 1].broken() && !plateau.gameboard()[i + 1][j + 1].free()) && // droite bas
                (plateau.gameboard()[i + 1][j - 1].broken() && !plateau.gameboard()[i + 1][j - 1].free())) { // gauche bas
                
                plateau.affiche();
                
                cout << "Bravo !! " <<  _pseudo << " vous avez gagné \n" << endl;
                return true;
            }
            
        }
    }
    
    return false;
}

