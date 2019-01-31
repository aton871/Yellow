#ifndef DEF_TRESORIE
#define DEF_TRESORIE

#include <vector>
#include "Mineur.h"


class Tresorie{

	public : 

		Tresorie();

		int getDollars() const;
		int getOr() const;

		void MajOr(std::vector<Mineur> listeMineurs);
		void ajouterOr(int qteOr);
		void retirerOr(int qteOr);

		void operator+=(int dollars);  //Ajouter des dollars
		void operator-=(int dollars);  //Retirer des dollars

	private : 

		int m_dollars;
		int m_or;   //Pépites d'or


};





#endif 