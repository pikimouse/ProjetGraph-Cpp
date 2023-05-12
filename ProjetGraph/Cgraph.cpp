#include "Cgraph.h"
#include <iostream>

// Constructeur par défaut
Cgraphe::Cgraphe() {
    iGPHNbsommets = 0;
    iGPHNbarcs = 0;
    SOMGPHSommets = nullptr;
}

// Constructeur qui prend en entrée le nombre de sommets et d'arcs
Cgraphe::Cgraphe(int nbsommets, int nbarcs) {
    iGPHNbsommets = nbsommets;
    iGPHNbarcs = nbarcs;
    SOMGPHSommets = new Csommet * [iGPHNbsommets];
    for (int i = 0; i < iGPHNbsommets; i++) {
        SOMGPHSommets[i] = new Csommet(i + 1);
    }
}

// Destructeur
Cgraphe::~Cgraphe() {
    for (int i = 0; i < iGPHNbsommets; i++) {
        delete SOMGPHSommets[i];
    }
    delete[] SOMGPHSommets;
}

// Ajouter un sommet
void Cgraphe::GPHAjouterSommet(int numero) {
    // Vérifier si le sommet existe déjà
    for (int i = 0; i < iGPHNbsommets; i++) {
        if (SOMGPHSommets[i]->SOMLireNumero() == numero) {
            //throw Cexception("Erreur : le sommet existe déjà !");
        }
    }

    // Ajouter le sommet
    Csommet** temp = new Csommet * [iGPHNbsommets + 1];
    for (int i = 0; i < iGPHNbsommets; i++) {
        temp[i] = SOMGPHSommets[i];
    }
    temp[iGPHNbsommets] = new Csommet(numero);
    delete[] SOMGPHSommets;
    SOMGPHSommets = temp;
    iGPHNbsommets++;
}

// Ajouter un arc
void Cgraphe::GPHAjouterArc(int debut, int fin) {
    // Vérifier si les sommets de début et de fin existent
    Csommet* somDebut = nullptr;
    Csommet* somFin = nullptr;
    for (int i = 0; i < iGPHNbsommets; i++) {
        if (SOMGPHSommets[i]->SOMLireNumero() == debut) {
            somDebut = SOMGPHSommets[i];
        }
        if (SOMGPHSommets[i]->SOMLireNumero() == fin) {
            somFin = SOMGPHSommets[i];
        }
    }
    if (somDebut == nullptr || somFin == nullptr) {
        //throw Cexception("Erreur : les sommets de début et de fin doivent exister !");
    }

    // Ajouter l'arc
    Carc* arc = new Carc(fin);
    somDebut->SOMAjouterArcArrivant(arc);
    somFin->SOMAjouterArcPartant(arc);
    iGPHNbarcs++;
}

// Supprimer un sommet
void Cgraphe::GPHSupprimerSommet(int numero)
{
    // Vérifier si le sommet existe dans le graphe
    bool sommetExiste = false;
    for (int i = 0; i < iGPHNbsommets; i++) {
        if (SOMGPHSommets[i]->SOMLireNumero() == numero) {
            sommetExiste = true;
            break;
        }
    }
    if (!sommetExiste) {
        std::cout << "Le sommet " << numero << " n'existe pas dans le graphe." << std::endl;
        return;
    }

    // Supprimer les arcs liés au sommet à supprimer
    for (int i = 0; i < iGPHNbsommets; i++) {
        if (i != numero) {
            for (int j = 0; j < SOMGPHSommets[i]->SOMLireNbArcArrivants(); j++) {
                if (SOMGPHSommets[i]->SOMLireArcArrivant()[j]->ARCLireDestination() == numero) {
                    SOMGPHSommets[i]->SOMSupprimerArcArrivant(j);
                    break;
                }
            }
            for (int j = 0; j < SOMGPHSommets[i]->SOMLireNbArcPartants(); j++) {
                if (SOMGPHSommets[i]->SOMLireArcPartant()[j]->ARCLireDestination() == numero) {
                    SOMGPHSommets[i]->SOMSupprimerArcPartant(j);
                    break;
                }
            }
        }
    }

    // Supprimer le sommet du tableau de sommets du graphe
    int index = -1;
    for (int i = 0; i < iGPHNbsommets; i++) {
        if (SOMGPHSommets[i]->SOMLireNumero() == numero) {
            index = i;
            break;
        }
    }
    delete SOMGPHSommets[index];
    for (int i = index; i < iGPHNbsommets - 1; i++) {
        SOMGPHSommets[i] = SOMGPHSommets[i + 1];
    }
    SOMGPHSommets[iGPHNbsommets - 1] = nullptr;
    iGPHNbsommets--;
}

// Supprimer un arc
void Cgraphe::GPHSupprimerArc(int debut, int fin) {
    // Recherche du sommet de départ
    Csommet* sommetDebut = nullptr;
    for (int i = 0; i < iGPHNbsommets; i++) {
        if (SOMGPHSommets[i]->SOMLireNumero() == debut) {
            sommetDebut = SOMGPHSommets[i];
            break;
        }
    }
    if (sommetDebut == nullptr) {
        //throw Cexception("Le sommet de départ n'existe pas.");
    }

    // Recherche de l'arc à supprimer dans les arcs partants
    Carc** arcsPartants = sommetDebut->SOMLireArcPartant();
    bool arcTrouve = false;
    int i = 0;
    while (arcsPartants[i] != nullptr) {
        if (arcsPartants[i]->ARCLireDestination() == fin) {
            arcTrouve = true;
            break;
        }
        i++;
    }

    // Si l'arc est trouvé, on le supprime
    if (arcTrouve) {
        delete arcsPartants[i];
        // Décalage des arcs pour combler le vide laissé par l'arc supprimé
        while (arcsPartants[i] != nullptr) {
            arcsPartants[i] = arcsPartants[i + 1];
            i++;
        }
        iGPHNbarcs--;
    }
    else {
        //throw Cexception("L'arc n'existe pas.");
    }
}

// Afficher le graphe
void Cgraphe::GPHAfficherGraphe() {
    for (int i = 0; i < iGPHNbsommets; i++) {
        Csommet* sommet = SOMGPHSommets[i];
        std::cout << "Sommet " << sommet->SOMLireNumero() << " : ";
        Carc** arcsPartants = sommet->SOMLireArcPartant();
        int j = 0;
        while (arcsPartants[j] != nullptr) {
            std::cout << "(" << sommet->SOMLireNumero() << ", " << arcsPartants[j]->ARCLireDestination() << ") ";
            j++;
        }
        std::cout << std::endl;
    }
}

// Retourne le nombre de sommets du graphe
int Cgraphe::GPHLireNbSommets() {
    return iGPHNbsommets;
}

// Retourne le nombre d'arcs du graphe
int Cgraphe::GPHLireNbArcs() {
    return iGPHNbarcs;
}

// Retourne un pointeur vers le tableau de pointeurs de sommets du graphe
Csommet** Cgraphe::GPHLireSommets() {
    return SOMGPHSommets;
}
