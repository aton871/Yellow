#include "SuperMineur.h"
#include "Mineur.h"
#include "Personnage.h"

#include <string>
#include <cmath>  //Pour utiliser l'exponentiel
#include <iostream>

SuperMineur::SuperMineur(int vie, int moral, std::string nom, int rendementMax, bool joueur) : Mineur(vie,moral,nom,rendementMax,joueur), m_experience(20){

}


int SuperMineur::getExperience() const{

	return(m_experience);
}

void SuperMineur::apresMinage(){  //En minant un mineur perd petit à petit du moral

	m_experience++;

	m_rendementMax= m_experience/10;  //Tous les 10 tours le super mineur gagne un point de rendement max

	m_moral=m_moral-10;


	if (m_moral<0)  {  //Si le mineur a un moral négatif, il perds de la vie ou démissionne ou pars en grève

		int degatsMoraux(exp(-m_moral/10));

		Personnage::degats(degatsMoraux);

	}

}

bool SuperMineur::estSuperMineur() const{

	return(true);
}
