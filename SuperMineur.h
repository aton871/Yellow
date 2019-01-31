#ifndef DEF_SUPERMINEUR
#define DEF_SUPERMINEUR

#include "Mineur.h"


//À la différence d'un simple mineur, un super mineur gagne de l'expérience, et augmente progressivement

class SuperMineur : public Mineur{

	public: 

		SuperMineur(int vie, int moral, std::string nom, int rendementMax, bool joueur);

		int getExperience() const;

		virtual void apresMinage();   
		virtual bool estSuperMineur() const;

	private:
	
		int m_experience;  //Experience Acquise par le superMineur	


};

#endif