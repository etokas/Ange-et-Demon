//
//  Joueur.h
//  2CPP Ange Et Demon
//
//  Created by Etok's Sylva on 12/02/2015.
//  Copyright (c) 2015 Etok's Sylva. All rights reserved.
//

#ifndef ___CPP_Ange_Et_Demon__Joueur__
#define ___CPP_Ange_Et_Demon__Joueur__

#include "case.h"



//======================================
//          CLASSE ABSTRAITE JOUEUR
//======================================

class Joueur {
protected:
    string _pseudo;

public:
    Joueur(string ps);
    void saisir(int &numLigne, int &numColonne);
    virtual bool incorrect(int &ligne, int &colonne, Plateau &plateau) = 0;
    void choisirCase(int &ligne, int &colonne, Plateau &plateau);
    virtual void modifierCase(int &ligne, int &colonne, Plateau &plateau) = 0;
    void jouer(Plateau &plateau);
    virtual bool gagne(Plateau &) = 0;
    string pseudo() {return _pseudo;}

    //Fonction qui verifie juste si l'utilisateur ne rentre pas n'importe quoi.
    static void verifier(int &, string message);

};



//======================================
//          CLASSE ANGE
//======================================

class Ange: public Joueur {
protected:
    int _ligne;
    int _colonne;

public:
    Ange(string ps, int l, int c);
    bool incorrect(int &ligne, int &colonne, Plateau &plateau);
    void modifierCase(int &ligne, int &colonne, Plateau &plateau);
    bool gagne(Plateau &);
};


//======================================
//          CLASSE ANGE PUISSANT
//======================================

class AngePuissant: public Ange{
private:
    int _puissance;

public:
    AngePuissant(string ps, int l, int c, int p);
    bool incorrect(int &ligne, int &colonne, Plateau &plateau);
    void modifierCase(int &ligne, int &colonne, Plateau &p);
    bool gagne(Plateau &);

};



//======================================
//          CLASSE DEMON
//======================================

class Demon : public Joueur {
public:
    Demon(string ps);
    bool incorrect(int &ligne, int &colonne, Plateau &plateau);
    void modifierCase(int &ligne, int &colonne, Plateau &plateau);
    bool gagne(Plateau &);
};




#endif /* defined(___CPP_Ange_Et_Demon__Joueur__) */







