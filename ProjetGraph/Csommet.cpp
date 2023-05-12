#include "Csommet.h"
using namespace std;


/**
    * @brief Constructeur par defaut de la classe CSommet
	*
	* Le constructeur initialise les attributs  iSOMNumero, ARCSOMArrivant, et ARCSOMPartant 
	*
	*/
Csommet::Csommet()
{
    iSOMNumero=0;
    ARCSOMArrivant=nullptr;
    ARCSOMPartant=nullptr;
};


/**
	* @brief Constructeur de recopie de la classe Csommet
	*
	* Il initialise le numéro du sommet
    *
    * @param numero de type int
	*/
Csommet::Csommet(const Csommet & SOMarg)
{
    iSOMNumero=SOMarg.iSOMNumero;
    ARCSOMArrivant = new (Carc*)();
    ARCSOMPartant = new (Carc*)();
 
			for (unsigned int uiBoucle1 = 0; uiBoucle1<iSOMNumero; uiBoucle1++)
			{
				for (unsigned int uiBoucle2 = 0; uiBoucle2 < iSOMNumero; uiBoucle2++)
			       {
                    ARCSOMArrivant[uiBoucle1,uiBoucle2] = SOMarg.ARCSOMPartant[uiBoucle1,uiBoucle2];
					ARCSOMPartant[uiBoucle1,uiBoucle2] = SOMarg.ARCSOMPartant[uiBoucle1,uiBoucle2];
					}
			}
};
/**
	* @brief Destructeur de la classe Csommet
	*
	* Il désalloue ARCSOMArrivant et ARCSOMPartant 
    *
	*/

    Csommet::~Csommet()
    {
        for (unsigned int uiBoucle1 = 0; uiBoucle1<iSOMNumero; uiBoucle1++)
	{
		delete[] ARCSOMArrivant[uiBoucle1];
    }
    for (unsigned int uiBoucle2 = 0; uiBoucle2<iSOMNumero; uiBoucle2++){
        delete[] ARCSOMPartant[uiBoucle2];
	}
	delete[] ARCSOMArrivant;
    delete[] ARCSOMPartant;

    };

    int Csommet::SOMLireNumero() const
    {
        return  iSOMNumero;
        
    };

    void Csommet::SOMModifierNumero(int numero){

        if(numero<0)
        {
            throw(Cexception(numero_non_naturel));

        }

        iSOMNumero=numero;

        
    }


    Carc** Csommet::SOMLireArcArrivant() const{
        return ARCSOMArrivant;

    }


    void Csommet::SOMModifierArcArrivant(Carc** ARCSOMArg)
    {
        if()
      

    }

    void Csommet::SOMAjouterArcArrivant(Carc* ARCSOMArg)
    {
        for(unsigned int uiBoucle1=0;uiBoucle1<iSOMNumero;uiBoucle1++){

        }

    }

    int Csommet::SOMLireNbArcArrivants() const
    {

    }
    void Csommet::SOMSupprimerArcArrivant(int iSOMNum)
    {

    }

    Carc** Csommet:: SOMLireArcPartant() const{
        return ARCSOMPartant;

    }
    void Csommet::SOMModifierArcPartant(Carc** ARCSOMArg){

    }
    void Csommet::SOMAjouterArcPartant(Carc* ARCSOMArg){

    }
    int Csommet::SOMLireNbArcPartants() const{

    }
    void Csommet::SOMSupprimerArcPartant(int iSOMDest){

    }














    
