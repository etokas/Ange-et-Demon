//
//  Partie.cpp
//  2CPP Ange Et Demon
//
//  Created by Etok's Sylva on 13/02/2015.
//  Copyright (c) 2015 Etok's Sylva. All rights reserved.
//

#include "Partie.h"

Partie::Partie(int dim, int choix, string ps1, string ps2, int p): _puissance(p), _choixAnge(choix){

    _plateau = * new Plateau(dim);

    switch (_choixAnge) {
        case 1:
            _joueurs[0] = new Ange(ps1, _plateau.dim()/2, _plateau.dim()/2);
            break;
        case 2:
            _joueurs[0] = new AngePuissant(ps1, _plateau.dim()/2, _plateau.dim()/2, _puissance);
            break;
        default:
            break;
    }
    
    _joueurs[1] = new Demon(ps2);
}


void Partie::tourDeJeu() {
    
    int counter = 0, taille;

    
    // a chaque tour de boucl il y'aura que un jour qui va jouer
    do{
        cout << "Tour : " << counter + 1 << endl;
        _plateau.affiche();

        if(counter % 2 == 0) {

            cout << "C'est à " << _joueurs[0]->pseudo() << " (Ange) de jouer !" << endl;
            _joueurs[0]->jouer(_plateau);

        } else {

            cout << "C'est à " << _joueurs[1]->pseudo() << " (Démon) de jouer !" << endl;

            do {

                Joueur::verifier(taille, "Augmenter la taille du plateau 1 = oui / 2 = non");

            } while (taille != 1 && taille != 2);

            cout << endl;

            if (taille == 1) {

                _plateau++;

                _plateau.affiche();
            }

            _joueurs[1]->jouer(_plateau);
        }
        
        counter++;
        // verification si l'ange ou le demon gagne ou le demon
    } while (!_joueurs[0]->gagne(_plateau) && !_joueurs[1]->gagne(_plateau));
    
}



