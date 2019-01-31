#include "Tresorie.h"
#include "Mineur.h"

#include <cstdlib>
#include <iostream>

Tresorie::Tresorie(){

	m_dollars=0;
	m_or=0;
}

int Tresorie::getDollars() const{

	return(m_dollars);
}

int Tresorie::getOr() const{


	return(m_or);
}

void Tresorie::MajOr(std::vector<Mineur> listeMineurs){

	int i,j,rendementMax;
	int orMineur;
	int nb_alea;  //Nombre aléatoire
	int N(listeMineurs.size());


	//Parcours de la liste des mineurs
	for (i=0;i<N;i++){

		if (listeMineurs[i].getMoral()<50)  rendementMax=listeMineurs[i].getRendementMax()/2;


		else rendementMax=listeMineurs[i].getRendementMax();


		orMineur=0;
		

		//Pépite qu'il peut obtenir en fonction de son rendement
		for (j=0;j<rendementMax;j++){

			//Une chance sur 4 de trouver une pépite


			nb_alea=rand()%4;

			if (nb_alea==2) orMineur++;

		}

		
		//orMineur = listeMineurs[i].getRendement();
		m_or += orMineur; 	
		
	}

}


void Tresorie::ajouterOr(int qteOr){

	m_or+=qteOr;

}


void Tresorie::retirerOr(int qteOr){

	m_or-=qteOr;
}



void Tresorie::operator+=(int dollars){

	m_dollars+=dollars;

}

void Tresorie::operator-=(int dollars){

	m_dollars-=dollars;

	if (m_dollars<0) m_dollars=0;
}

