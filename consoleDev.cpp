#include "consoleDev.h"

#include <iostream>

#include "Tresorie.h"
#include "Personnage.h"
#include "Mineur.h"
#include "Ville.h"
#include "Bandit.h"
#include "Evenements.h"


void etatPersonnage(Personnage const& P){

	std::cout << std::endl;
	std::cout << "------------ETAT PERSONNAGE-------------" << std::endl;

	if (P.estVivant()==1){

		std::cout << "Le personnage est vivant" << std::endl;

	}

	else {

		std::cout << "Le personnage est mort" << std::endl;

	}

	
	std::cout << "Nom : " << P.getNom() << std::endl;
	std::cout << "Vie : " << P.getVie() << std::endl;
	std::cout << "Moral : " << P.getMoral() << std::endl;


	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;

}

void etatMineur(Mineur const& M){

	std::cout << std::endl;
	std::cout << "------------ETAT MINEUR-------------" << std::endl;

	std::cout << "Rendement max d'or par tour par mineur : " << M.getRendementMax() << std::endl;

	std::cout << "------------------------------------" << std::endl;
	std::cout << std::endl;
}


void etatBandit(Bandit const& B){

		std::cout << std::endl;
	std::cout << "------------ETAT BANDIT-------------" << std::endl;

	std::cout << "Ferocite du bandit : " << B.getFerocite() << std::endl;

	std::cout << "------------------------------------" << std::endl;
	std::cout << std::endl;
}


void Finances(Tresorie const& Tresor){

	std::cout << std::endl;
	std::cout << "------------FINANCES-------------" << std::endl;


	std::cout << "Dollars en réserve : " << Tresor.getDollars() << std::endl;
	std::cout << "Pépites d'or en réserve : " << Tresor.getOr() << std::endl;


	std::cout << "---------------------------------" << std::endl;
	std::cout << std::endl;

}

void etatVille(Ville const& V){

	std::cout << std::endl;
	std::cout << "------------ETAT VILLE-------------" << std::endl;	


	std::cout << "Nom : " << V.getNom() << std::endl;
	std::cout << "Taux de change : " << V.getTxChange() << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::endl;
}


void etatEvenements(Evenements const& CHAOS){

	std::cout << std::endl;
	std::cout << "------------ETAT EVENEMENTS-------------" << std::endl;	


	std::cout << "Compteur : " << CHAOS.getCompteur() << std::endl;
	std::cout << "Aleatoire : " << CHAOS.getAleatoire() << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::endl;
	



}


void cheat(Ville &V, Tresorie &Tresor, Personnage &P, Evenements &CHAOS){

	//Coder l'invincibilité du joueur

	int choixJoueur;

	std::cout << std::endl;
	std::cout << "Avoir 100 000 points de vie (1)" << std::endl;
	std::cout << "Avoir 600 000 points de moral (2)" << std::endl;
	std::cout << "Ajouter 500 000 pépites d'or (3)" << std::endl;
	std::cout << "Ajouter 100 000 dollars (4)" << std::endl;

	std::cin >> choixJoueur;

	switch(choixJoueur){

		case 1 : 
			P.cheatVie(100000);
			break;

		case 2 : 
			P.cheatMoral(600000);
			break;

		case 3 : 
			Tresor.ajouterOr(500000);
			break;

		case 4 :
			Tresor+=100000;
			break;

	}


}

