#ifndef DEF_MINEUR
#define DEF_MINEUR

#include "Personnage.h"

class Mineur : public Personnage{

	public: 

		Mineur(int vie, int moral, std::string nom, int rendementMax, bool joueur);

		int getRendementMax() const;

		virtual void apresMinage();   //Effets du minage sur les stats du mineur
		virtual bool estSuperMineur() const;

		void repos();


	protected: 

		int m_rendementMax; //Rendement max d'or par tour


};


#endif