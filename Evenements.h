#ifndef DEF_EVENTS
#define DEF_EVENTS

#include "Tresorie.h"
#include "Mineur.h"
#include "Bandit.h"

class Evenements{

	public: 

		Evenements();

		int getCompteur() const;
		int getAleatoire() const;

		bool getFilonOr() const;
		bool getEffondrement() const;
		bool getRevolte() const;


		void Maj(int Tour);

		void filonOr(Tresorie &Tresor);
		void effondrement(std::vector<Mineur> &listeMineurs);
		void revolteBandits(std::vector<Bandit> &listeBandits,Tresorie &Tresor);


	private: 

		int m_compteur; //Plus le compteur augmente, plus la probabilité d'avoir un évènement augmente
		int m_aleatoire;

		bool m_filonOr;
		bool m_effondrement;
		bool m_revolte;

};

#endif