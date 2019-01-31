#ifndef DEF_BANDIT
#define DEF_BANDIT

#include "Personnage.h"
#include <string>

class Bandit : public Personnage{

	public:

		Bandit(int vie, int moral, std::string nom, bool estJoueur,int ferocite);

		int getFerocite() const;

		void apresAttaque();

		void repos();


	private:
	
	//Plus la bandit est féroce, plus il rapporter d'argent, mais plus il a de chances de se retourner contre nous
		int m_ferocite;	

};

#endif
