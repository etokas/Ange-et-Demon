//
//  Partie.h
//  2CPP Ange Et Demon
//
//  Created by Etok's Sylva on 13/02/2015.
//  Copyright (c) 2015 Etok's Sylva. All rights reserved.
//

#ifndef ___CPP_Ange_Et_Demon__Partie__
#define ___CPP_Ange_Et_Demon__Partie__

#include "Joueur.h"

class Partie {
private:
    Plateau _plateau;
    Joueur * _joueurs[2];
    int _choixAnge;
    int _puissance;
    
public:
    Partie(int dim, int choix, string ps1, string ps2, int p);
    void tourDeJeu();
};

#endif /* defined(___CPP_Ange_Et_Demon__Partie__) */