#pragma once
Je dois créé un projet en c++ pour gérer des graphs et je dois utiliser cette structure :
La classe Cexception : qui permettra de lever des exceptions
La classe Carc : qui représentera des arcs dans le graphe,
La classe Csommet : qui représentera des sommets dans le graphe,
La classe Cgraphe : qui représentera un graphe.
La classe Cparser : qui permet de lire le contenu d’un graphe dans un fichier texte et créer un objet graphe en mémoire pour stocker les données lues dans le fichier.Le format du fichier texte(imposé) est donné ci - dessous et illustré dans le cadre d’un exemple : il repose sur l’utilisation de quelques balises.
NBSommets = <Nombre_de_Sommets_du_graphe>
NBArcs = < Nombre_d_arcs_du_graphe >
Sommets = [
	Numero = <Numéro_sommet >
		Numero = <Numéro_sommet>
		…
		Numero = <Numéro_sommet>
]
Arcs = [
	Debut = <Sommet_départ_arc>, Fin = <Sommet_arrivée_arc>
		Debut = <Sommet_départ_arc>, Fin = <Sommet_arrivée_arc>
		…
		Debut = <Sommet_départ_arc>, Fin = <Sommet_arrivée_arc>
]

La classe graphe va tout simplement contenir un tableau de Csommet qui seront les sommets du graphe.
La librairie que vous devez fournir doit permettre :
	De créer des objets graphe,
		De faire des opérations « élémentaires » sur un graphe,
		Ajouter / modifier / supprimer un sommet au graphe,
		Ajouter / modifier / supprimer un arc du graphe,
		Afficher à l’écran un graphe.
		Les variables, types, classes, fonction et méthodes devront respecter les conventions de nommage,
		Les attributs de la classe Csommet sont un numero qui decrit le sommet, Carc** arrivant qui sera inséré dans la liste des Partant du sommet de départ et Carc** partant qui  sera inséré dans la liste des Arrivant du sommet d’arrivé.
		La classe Carc contiendra le seul attribut destination qui est le numéro du sommet destination(nommons le Destination) elle aura aussi le meme type que numéro
class Cparser
{
};

