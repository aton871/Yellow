#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>

class Personnage{

	public: 

	Personnage(int vie, int moral, std::string nom, bool joueur); 

	int getMoral() const;
	int getVie() const;
	std::string getNom() const;
	bool estJoueur() const;

	bool estVivant() const; 
	void degats(int viePerdu);
	void soigner(int vieRecup);
	void demoralisation(int moralPerdu); 

	void cheatVie(int vie);
	void cheatMoral(int moral);


	protected: 

		int m_vie;
		int m_moral;
		std::string m_nom;
		bool m_joueur;


};


#endif