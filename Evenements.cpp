#include "Evenements.h"
#include "Tresorie.h"
#include "Mineur.h"
#include "Bandit.h"

#include <cstdlib>
#include <iostream>

Evenements::Evenements() : m_compteur(0), m_aleatoire(42), m_filonOr(false), m_effondrement(false), m_revolte(false){

}

int Evenements::getCompteur() const{

	return(m_compteur);
}

int Evenements::getAleatoire() const{

	return(m_aleatoire);
}

bool Evenements::getFilonOr() const{

	return(m_filonOr);
}

bool Evenements::getEffondrement() const{

	return(m_effondrement);
}

bool Evenements::getRevolte() const{

	return(m_revolte);
}

void Evenements::Maj(int Tour){

	int choix_event;

	m_compteur++;

	m_aleatoire=rand()%(250-m_compteur);




	//Après le Tour 46 c'est le début des éboulements dans la mine




	if (m_compteur==249)  m_compteur=0;

	if (m_aleatoire==0){

		m_compteur=0;

		if (Tour>46){  //Les éboulements viennent à partir du tour 47

			choix_event=rand()%2;

			if (choix_event==0) m_filonOr=true;

			if (choix_event==1) m_effondrement=true;

		}

		else {

		m_filonOr=true;

		}

	}


}

void Evenements::filonOr(Tresorie &Tresor){


	if (m_filonOr==true){

		int qteOr;

		qteOr=rand()%103 + 33 ; //Un filon d'or peut contenir au maximum 136 pépites, et au minimum 33


		Tresor.ajouterOr(qteOr);

		m_filonOr=false;
	}


}


void Evenements::effondrement(std::vector<Mineur> &listeMineurs){

	if (m_effondrement==true){

		int i;
		int degatsEffondrement;
		int N=listeMineurs.size();





		for (i=0;i<N;i++){

			degatsEffondrement=rand()%100;

			listeMineurs[i].degats(degatsEffondrement);  //Un mineur peut perdre jusqu'à tous ses points de vie
		}


		m_effondrement=false;

	}
}

void Evenements::revolteBandits(std::vector<Bandit> &listeBandits,Tresorie &Tresor){

	int i,nb_alea;

	m_revolte=false;

	//Plus les bandits sont féroces, plus il y a des chances qu'ils se révoltent

	for (i=0;i<listeBandits.size();i++){

		nb_alea=rand()%2500-listeBandits[i].getFerocite();

		if (nb_alea==0){
			//Si un des bandits se révole, ils se révoltent tous, et il repartent avec au mieux 1/4 du trésor au pire tout le trésor
			listeBandits.clear();
			Tresor-=Tresor.getDollars()/(rand()%4+1);
			m_revolte=true;
		}
	}
}



