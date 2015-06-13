//
//  main.cpp
//  2CPP Ange Et Demon
//
//  Created by Etok's Sylva on 11/02/2015.
//  Copyright (c) 2015 Etok's Sylva. All rights reserved.
//

#include "Partie.h"

int main(int argc, const char * argv[]) {

  	int taille, choix, puissance;
  	string nom1, nom2;
  	cout << "BIENVENU DANS MON JEU DE L'ANGE ET DEMON \n" << endl;
  	Joueur::verifier(taille, "Entrez la taille du tableau");
  	cout << "Entrez le nom de l'ange : "; cin >> nom1;
  	cout << "Entrez le nom du demon : "; cin >> nom2;

  	do {

  	    Joueur::verifier(choix, "Entrez 1 pour l'Ange normal ou 2 pour Puissant");
  	
  	} while (choix != 1 && choix != 2);

  	if (choix == 2) {

  		do {

	       Joueur::verifier(puissance, "Entrez la puissance de l'ange >= 2");
	       
  		} while (puissance < 2);
  	}

  	cout << endl;

  	Partie maPartie(taille, choix, nom1, nom2, puissance);
  	maPartie.tourDeJeu();

    
    return 0;

}
