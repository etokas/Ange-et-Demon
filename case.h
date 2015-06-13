//
//  case.h
//  2CPP Ange Et Demon
//
//  Created by Etok's Sylva on 11/02/2015.
//  Copyright (c) 2015 Etok's Sylva. All rights reserved.
//

#ifndef ___CPP_Ange_Et_Demon__case__
#define ___CPP_Ange_Et_Demon__case__

#include "include.h"

//======================================
//          CLASSE CASE
//======================================

class Case {
    
private:
    bool _broken;
    bool _free;
    
public:
    Case();
    Case(bool d, bool l);
    bool free() const { return _free;};
    bool broken() const { return _broken;};
    Case setCase(bool bro, bool fre);
};



//======================================
//          CLASSE PLATEAU
//======================================

class Plateau {
    
private:            		
    Case ** _gameboard;
    int _dim;
    
public:
    Plateau(int d);
    
    /* Forme canonique coplien */
    Plateau();
    ~Plateau();
    Plateau(const Plateau &obj);
    Plateau & operator=(const Plateau &obj);
    /**************************************/
    
    Case ** gameboard() const {return _gameboard;}
    int dim() const {return _dim;}
    void affiche();
    Plateau& operator++(int);
    
private:
    //une methode qui sert juste a modeliser mon tableau.
    void delimiter(int x);
};


#endif /* defined(___CPP_Ange_Et_Demon__case__) */
