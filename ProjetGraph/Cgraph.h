#pragma once
#include "Cexception.h"
#include "Csommet.h"
#include "Carc.h"
class Cgraphe {
private:
    int iGPHNbsommets; // Nombre de sommets du graphe
    int iGPHNbarcs; // Nombre d'arcs du graphe
    Csommet** SOMGPHSommets; // Tableau de pointeurs de Csommet
public:
    // Constructeur par défaut
    Cgraphe();

    // Constructeur qui prend en entrée le nombre de sommets et d'arcs
    Cgraphe(int nbsommets, int nbarcs);

    // Destructeur
    ~Cgraphe();

    // Ajouter un sommet
    void GPHAjouterSommet(int numero);

    // Ajouter un arc
    void GPHAjouterArc(int debut, int fin);

    // Supprimer un sommet
    void GPHSupprimerSommet(int numero);

    // Supprimer un arc
    void GPHSupprimerArc(int debut, int fin);

    // Afficher le graphe
    void GPHAfficherGraphe();

    // Getters
    int GPHLireNbSommets();
    int GPHLireNbArcs();
    Csommet** GPHLireSommets();
};

