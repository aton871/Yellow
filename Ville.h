#ifndef DEF_VILLE
#define DEF_VILLE

#include <string>
#include "Personnage.h"
#include "Tresorie.h"
#include "Mineur.h"

class Ville{

	public: 

		Ville(std::string nom, int txChange);

		std::string getNom() const;
		int getTxChange() const;

		int vendreOr(int qteOr);
		void medecin(Personnage &P, Tresorie &Tresor);

	private: 

		std::string m_nom;
		int m_txChange;

};




#endif