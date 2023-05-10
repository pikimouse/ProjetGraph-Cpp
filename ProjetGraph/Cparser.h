#pragma once
Je dois cr�� un projet en c++ pour g�rer des graphs et je dois utiliser cette structure :
La classe Cexception : qui permettra de lever des exceptions
La classe Carc : qui repr�sentera des arcs dans le graphe,
La classe Csommet : qui repr�sentera des sommets dans le graphe,
La classe Cgraphe : qui repr�sentera un graphe.
La classe Cparser : qui permet de lire le contenu d�un graphe dans un fichier texte et cr�er un objet graphe en m�moire pour stocker les donn�es lues dans le fichier.Le format du fichier texte(impos�) est donn� ci - dessous et illustr� dans le cadre d�un exemple : il repose sur l�utilisation de quelques balises.
NBSommets = <Nombre_de_Sommets_du_graphe>
NBArcs = < Nombre_d_arcs_du_graphe >
Sommets = [
	Numero = <Num�ro_sommet >
		Numero = <Num�ro_sommet>
		�
		Numero = <Num�ro_sommet>
]
Arcs = [
	Debut = <Sommet_d�part_arc>, Fin = <Sommet_arriv�e_arc>
		Debut = <Sommet_d�part_arc>, Fin = <Sommet_arriv�e_arc>
		�
		Debut = <Sommet_d�part_arc>, Fin = <Sommet_arriv�e_arc>
]

La classe graphe va tout simplement contenir un tableau de Csommet qui seront les sommets du graphe.
La librairie que vous devez fournir doit permettre :
	De cr�er des objets graphe,
		De faire des op�rations � �l�mentaires � sur un graphe,
		Ajouter / modifier / supprimer un sommet au graphe,
		Ajouter / modifier / supprimer un arc du graphe,
		Afficher � l��cran un graphe.
		Les variables, types, classes, fonction et m�thodes devront respecter les conventions de nommage,
		Les attributs de la classe Csommet sont un numero qui decrit le sommet, Carc** arrivant qui sera ins�r� dans la liste des Partant du sommet de d�part et Carc** partant qui  sera ins�r� dans la liste des Arrivant du sommet d�arriv�.
		La classe Carc contiendra le seul attribut destination qui est le num�ro du sommet destination(nommons le Destination) elle aura aussi le meme type que num�ro
class Cparser
{
};

