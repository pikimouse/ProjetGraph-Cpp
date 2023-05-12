#include "Carc.h"

#ifndef Sommet_H
#define Sommet_H
#pragma once

class Csommet {

    private:
    int iSOMNumero; // Le num�ro du sommet
    Carc** ARCSOMArrivant;// Liste des arcs Arrivant du sommet
    Carc** ARCSOMPartant;//Liste des arcs Partant du sommet


public:
    	//Constructeurs et destructeur

	/**
	* @brief Constructeur par d�faut de la classe CSommet
	*
	* Le constructeur initialise les attributs  iSOMNumero, ARCSOMArrivant, et ARCSOMPartant 
	*
	*/
    Csommet();


	/**
	* @brief Constructeur de recopie de la classe Csommet
	*
	* Il initialise le numéro du sommet
    *
    * @param numero de type int
	*/

   ~Csommet();

    /**
	* @brief Constructeur de recopie de la classe Csommet
	*
	* Il initialise le numéro du sommet
    *
    * @param numero de type int
	*/
    int SOMLireNumero() const;
    Csommet(const Csommet & SOMarg);
    void SOMModifierNumero(int numero);

    Carc** SOMLireArcArrivant() const;
    void SOMModifierArcArrivant(Carc** ARCSOMArg);
    void SOMAjouterArcArrivant(Carc* ARCSOMArg);
    int SOMLireNbArcArrivants() const;
    void SOMSupprimerArcArrivant(int iSOMNum);

    Carc** SOMLireArcPartant() const;
    void SOMModifierArcPartant(Carc** ARCSOMArg);
    void SOMAjouterArcPartant(Carc* ARCSOMArg);
    int SOMLireNbArcPartants() const;
    void SOMSupprimerArcPartant(int iSOMDest);


};

#endif

