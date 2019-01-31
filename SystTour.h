#ifndef DEF_SYSTTOUR
#define DEF_SYSTTOUR

#include "Personnage.h"
#include "Tresorie.h"
#include "Mineur.h"
#include "Bandit.h"
#include "Ville.h"
#include "Evenements.h"
#include "SuperMineur.h"

#include "MajTour.h"
#include "consoleDev.h"


#include <iostream>
#include <vector>
#include <string>
#include <ctime>


class SystTour{

	public:

		SystTour(std::string nomJoueur);

		int getNbTour();
		std::string getLigne1();
		std::string getLigne2();

		void description(int choixJoueur);
		int suivant(int choixJoueur, Ville &V, Tresorie &Tresor, Personnage &Joueur,std::vector<Mineur> &listeMineurs,std::vector<Bandit> &listeBandits, Evenements &CHAOS);
		int gestionChaos(Evenements &CHAOS, std::vector<Mineur> &listeMineurs, std::vector<Bandit> &listeBandits, Tresorie &Tresor);

	private: 

		int m_nbTour;
		std::string m_ligne1;
		std::string m_ligne2;

};

void recruterMineur(std::vector<Mineur> &listeMineurs);

#endif