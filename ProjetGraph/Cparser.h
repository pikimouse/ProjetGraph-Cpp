#pragma once
#include "Cgraph.h"
#include <string>
class Cparser {
public:
    Cparser(std::string filename); // Constructeur, prend en entrée le nom du fichier à lire
    Cgraphe* PARGraphe(); // Renvoie un pointeur vers l'objet Cgraphe créé à partir du fichier
private:
    void PARLireSommets(std::ifstream& file); // Lit les sommets du graphe à partir du fichier et les ajoute dans l'objet Cgraphe correspondant
    void PARLireArcs(std::ifstream& file); // Lit les arcs du graphe à partir du fichier et les ajoute dans l'objet Cgraphe correspondant
    std::string PARLireProchaineBalise(std::ifstream& file); // Renvoie la prochaine balise du fichier (ex: "NBSommets =", "Sommets =", ...)
    int PARLireProchainNombre(std::ifstream& file); // Renvoie le prochain nombre présent dans le fichier (ex: le nombre de sommets, le numéro d'un sommet, ...)
    std::string sPARFilename; // Nom du fichier à lire
    Cgraphe* GPHPARGraphe; // Pointeur vers l'objet Cgraphe créé à partir du fichier
};