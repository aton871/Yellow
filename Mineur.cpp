#include "Mineur.h"
#include "Personnage.h"

#include <iostream>
#include <cmath>  //Pour utiliser l'exponentiel
#include <cstdlib>

Mineur::Mineur(int vie, int moral, std::string nom, int rendementMax, bool joueur) : Personnage(vie,moral,nom,joueur), m_rendementMax(rendementMax){

}

int Mineur::getRendementMax() const{

	return(m_rendementMax);
}

void Mineur::apresMinage(){  //En minant un mineur perd petit à petit du moral

	m_moral=m_moral-10;


	if (m_moral<0)  {  //Si le mineur a un moral négatif, il perds de la vie ou démissionne ou pars en grève

		int degatsMoraux(exp(-m_moral/10));

		Personnage::degats(degatsMoraux);

	}

}

bool Mineur::estSuperMineur() const{

	return(false);
}

void Mineur::repos(){   //En se reposant, un mineur gagne du moral

	int nb_alea;  //Variable aléatoire

	m_moral=m_moral+60;  //Pourquoi 60 et pas 50 ? Pour éviter que le joueur fasse trop facilement des arrondis, pour perturber sa planification

	if (m_moral>100) m_moral=100;


	//Une chance sur trois pour le mineur de regagner 5 points de vie

	nb_alea=rand()%3;

	if (nb_alea==0 && m_vie!=0){

		m_vie+=5;

		if (m_vie>100) m_vie=100;

	}

}


