#include "SystTour.h"
#include "Personnage.h"
#include "Tresorie.h"
#include "Mineur.h"
#include "Bandit.h"
#include "SuperMineur.h"
#include "Ville.h"
#include "Evenements.h"

#include "MajTour.h"
#include "consoleDev.h"


#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>


SystTour::SystTour(std::string nomJoueur){


	m_nbTour=1;
	m_ligne1="Bonjour " + nomJoueur + ", et bienvenue dans ta nouvelle mine d'or! A toi de jouer maintenant";
	m_ligne2="La fortune te tend les bras !"; 



}

int SystTour::getNbTour(){

	return(m_nbTour);
}

std::string SystTour::getLigne1(){

	return(m_ligne1);
}

std::string SystTour::getLigne2(){

	return(m_ligne2);
}


void SystTour::description(int affichage){


	switch (affichage){

		case 1 : {
			m_ligne1="Tu es parti miner de l'or";
			m_ligne2="";
			break;
		}

		case 2 : {
			m_ligne1="Rien ne vaut un peu de repos";
			m_ligne2="";
			break;
		}


		case 4 :{
			m_ligne1="Une bien bonne transaction";
			m_ligne2="";
			break;
		}

		case 5 : {
			m_ligne1="Ce n'est pas parce qu'on est au Far West qu'il ne faut pas mettre ton manteau !";
			m_ligne2="";
			break;
		}

		case 61 : { // Il n'y a pas assez d'argent dans la trésorie pour recruter un mineur

			m_ligne1="Je ne travaillerai pas avec une pioche en bois !";
			m_ligne2="";
			break;
		}

		case 62 : { // Il y a assez d'argent dans la trésorie pour recruter un mineur
			m_ligne1="Un mineur travaille maintenant pour toi";
			m_ligne2="";
			break;
		}

		case 71 : {
			m_ligne1="Un bandit est maintenant sous tes ordres";
			m_ligne2="";
			break;

		}

		case 72 : {

			m_ligne1="Je suis pas un mec gentil tu vois";
			m_ligne2="Paye moi un abri, et je verrai ce que je peux faire pour toi";
			break;
		}

		case 8 : {

			m_ligne1="";
			m_ligne2="";
			break;

		}

		case 10 : {

			m_ligne1="Un filon d'or dans la mine !";
			m_ligne2="";
			break;

		}

		case 11 : {

			m_ligne1="Une partie de la mine s'effondre sur nous !";
			m_ligne2="";
			break;

		}

		case 12 : {

			m_ligne1="Ces chiens de bandits m'ont pris mon argent dans la nuit !";
			m_ligne2="";
			break;

		}
	}
}



int SystTour::suivant(int choixJoueur, Ville &V, Tresorie &Tresor, Personnage &Joueur,std::vector<Mineur> &listeMineurs, std::vector<Bandit> &listeBandits, Evenements &CHAOS){

	int affichage;

	switch (choixJoueur){

		case 0 :{
			break;
		}

		case 1 : {
			MajMinage(listeMineurs,Tresor);
			break;
		}

		case 2 : {
			MajRepos(listeMineurs);
			break;
		}


		case 4 :{
			MajVenteOr(V,Tresor);
			break;
		}

		case 5 : {
			V.medecin(Joueur, Tresor);
			//cheat(V,Tresor,listeMineurs[0],CHAOS);
			break;
		}

		case 6 : {

			//S'il n'y a pas assez d'argent en trésorie pour embaucher un mineur
			if (Tresor.getDollars()<1000){
				affichage=61;
			}

			//S'il y a assez d'argent en trésorie pour embaucher un mineur
			else {
				Tresor-=1000;

				recruterMineur(listeMineurs);

				affichage=62;
			}
			break;	
		}

		case 7 : {

			if (Tresor.getDollars()>=100){
				Tresor-=100;
				std::string prenom;
				prenom = "Bandit";
				prenom += std::to_string(listeBandits.size()+1);
				Bandit Voleur(100,100,prenom,false,rand()%999);  //La férocité est initialisée aléatoirement entre 0 et 999
				listeBandits.push_back(Voleur);
				affichage=71;
			}

			else affichage=72;
			
			break;
		}

		case 8 : {

			MajAttaque(listeBandits,Tresor);
			break;
		}

		case 9 : {
			m_nbTour--;
			cheat(V,Tresor,listeMineurs[0],CHAOS);
			break;
		}


	}

	MajPersonnages(listeMineurs,listeBandits);   //Si un personnage est mort, il est retiré de la liste


	//Salaires
	MajDepenses(listeMineurs,Tresor);



	//Si le joueur est encore vivant, et qu'il a pu se payer un salaire
	if (listeMineurs[0].estJoueur()==true && listeMineurs[0].estVivant()==false) affichage=0;

	m_nbTour++;

	return(affichage);
}		

int SystTour::gestionChaos(Evenements &CHAOS, std::vector<Mineur> &listeMineurs, std::vector<Bandit> &listeBandits, Tresorie &Tresor){

	int affichage(42);

	CHAOS.Maj(m_nbTour);

	if (CHAOS.getFilonOr()==true) affichage=10;

	if (CHAOS.getEffondrement()==true) affichage=11;


	CHAOS.filonOr(Tresor);
	CHAOS.effondrement(listeMineurs);
	if (listeBandits.size()>0) CHAOS.revolteBandits(listeBandits,Tresor);

	if (CHAOS.getRevolte()==true) affichage=12;


	return(affichage);

}



void recruterMineur(std::vector<Mineur> &listeMineurs){

	std::string prenom;
	prenom = "Mineur";
	prenom += std::to_string(listeMineurs.size());

	//Probabilité d'avoir un super mineur
	int alea=rand()%2;
	
	if (alea==1){ 
		SuperMineur Travailleur(100,100,prenom,4+rand()%4,false);  //Le rendement max est initialisé aléatoirement entre 4 et 8
		listeMineurs.push_back(Travailleur);
	}

	else{ 
		Mineur Travailleur(100,100,prenom,2+rand()%4,false);
		listeMineurs.push_back(Travailleur);
	}
}
