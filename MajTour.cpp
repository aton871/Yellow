#include "MajTour.h"

#include "Personnage.h"
#include "Tresorie.h"
#include "Mineur.h"
#include "Bandit.h"
#include "SuperMineur.h"
#include "Ville.h"
#include "Evenements.h"
#include "consoleDev.h"

#include <vector>
#include <iostream>
#include <cstdlib>




void MajMinage(std::vector<Mineur> &listeMineurs, Tresorie &Tresor){


	//Mise à jour de l'or qu'on a miné

	Tresor.MajOr(listeMineurs);


	//Mise à jour de l'état des mineurs

	int i;
	int N(listeMineurs.size());


	for (i=0;i<N;i++){

		listeMineurs[i].apresMinage();
	}


}

void MajRepos(std::vector<Mineur> &listeMineurs){

	int i;
	int N(listeMineurs.size());

	for (i=0;i<N;i++){

		listeMineurs[i].repos();
	}


}

//Attaque d'une autre mine ou d'une banque par les bandits
void MajAttaque(std::vector<Bandit> &listeBandits,Tresorie &Tresor){


	int i,j,nb_alea;
	int argentVolee=0;

	for(i=0;i<listeBandits.size();i++){




		//Plus un bandit est feroce, plus il a de chance de rapporter de l'argent
		for (j=0;j<listeBandits[i].getFerocite();j++){

			//Une chance sur 2 de trouver de l'or
			nb_alea=rand()%2;

			if (nb_alea==1) argentVolee++;

		}

		listeBandits[i].apresAttaque();

		listeBandits[i].demoralisation(100);


		//Les bandits n'ont que 100 points de vie, et ont une chance sur 2 de décéder
		listeBandits[i].degats(rand()%50);
	}


	Tresor+=argentVolee;


}




void MajVenteOr(Ville &V,Tresorie &Tresor){

	int qteDollar,qteOr;


	qteOr=Tresor.getOr();

	qteDollar=V.vendreOr(qteOr);


	Tresor.retirerOr(qteOr);

	Tresor+=qteDollar;

}


void MajDepenses(std::vector<Mineur> &listeMineurs,Tresorie &Tresor){

	//Il faut 3 dollars par jour au joueur et aux autres mineurs pour vivre

	int depenses=0;
	


	int N=listeMineurs.size();
	int i;


	// CALCUL DES DÉPENSES

	for (i=0;i<N;i++){

			depenses+=3;   //Car chaque mineurs coûte 3 dollars par jour
	}



	// COMPARAISON AVEC LA TRÉSORIE


	//Si on peut payer tous les salaires
	if (depenses<Tresor.getDollars()){
		//Alors on les paye
		Tresor-=depenses;
	}


	//Si on ne peut pas payer les salaires
	else {
		
		i=0;

		//On paye les mineurs par ancienneté
		while(i<listeMineurs.size()){

			if (Tresor.getDollars()>=3){

				Tresor-=3;
				depenses-=3;
			}


			//S'il n'y a plus assez d'argent, pour les payer, les mineurs démissionnent 
			else{

				if (i!=0){  

				listeMineurs.pop_back();
				i--;
				}

				else { //Si le joueur ne peut même pas se payer son propre salaire, on le déclare mort pour obtenir le gameover
					listeMineurs[0].degats(101);
					i=N;
				}
			}

			i++;
		}
	}
}


void MajPersonnages(std::vector<Mineur> &listeMineurs,std::vector<Bandit> &listeBandits){

	int i,N;


	//MaJ pour listeMineurs

	i=0;
	N=listeMineurs.size();

	while (i<N){

		if (listeMineurs[i].estJoueur()==false){

			if (listeMineurs[i].estVivant()==false){

				listeMineurs.erase(listeMineurs.begin()+i);

				N=listeMineurs.size();

				i--;
			}
		}

		i++;
	}



	//Maj pour listeBandits

	i=0;
	N=listeBandits.size();

	while (i<N){


		if (listeBandits[i].estVivant()==false){

			listeBandits.erase(listeBandits.begin()+i);

			N=listeBandits.size();

			i--;
		}

		else listeBandits[i].repos(); //Les bandits se reposent entre deux attaques

		i++;
	}
}






