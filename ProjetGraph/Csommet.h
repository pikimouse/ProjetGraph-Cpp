#include "Carc.h"

#pragma once
class Csommet {
public:
    Csommet(int numero);
    ~Csommet();

    int SOMLireNumero() const;
    void SOMModifierNumero(int iSOMNum);

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

private:
    int iSOMNumero; // Le numéro du sommet
    Carc** ARCSOMArrivant;// Liste des arcs Arrivant du sommet
    Carc** ARCSOMPartant;//Liste des arcs Partant du sommet
};

