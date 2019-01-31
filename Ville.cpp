#include "Ville.h"
#include "Personnage.h"
#include "Tresorie.h"
#include "Mineur.h"


#include <string>
#include <iostream>

Ville::Ville(std::string nom,int txChange) : m_nom(nom),m_txChange(txChange){

}

std::string Ville::getNom() const{

	return(m_nom);
}

int Ville::getTxChange() const{

	return(m_txChange);
}

int Ville::vendreOr(int qteOr){

	int qteDollars;

	qteDollars = qteOr*m_txChange;

	return(qteDollars);

}

void Ville::medecin(Personnage &P, Tresorie &Tresor){

	int ptsVie;


	if (P.estJoueur()==true)  ptsVie=101-P.getVie();

	else ptsVie=100-P.getVie();

	
	//Si on n'a pas assez d'argent pour se soigner entièrement
	if (Tresor.getDollars()<ptsVie*100){ 
		//On se soigne, le plus possible
		P.soigner(Tresor.getDollars()/100);
		Tresor-=100*(Tresor.getDollars()/100);
	}

	else { //On se soigne totalement
		P.soigner(ptsVie);

		Tresor-=(ptsVie*100);
	}


}