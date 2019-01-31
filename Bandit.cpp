#include "Bandit.h"

#include "Personnage.h"
#include <string>
#include <cstdlib>

Bandit::Bandit(int vie, int moral, std::string nom, bool estJoueur,int ferocite) : Personnage(vie,moral,nom,estJoueur), m_ferocite(ferocite){
}

int Bandit::getFerocite() const{

	return(m_ferocite);
}

//Après une attaque, la ferocite des bandits augmente
void Bandit::apresAttaque(){

	m_ferocite+=100;
}

void Bandit::repos(){

	if (m_moral<100) m_moral+=10;

	if (m_moral==100 && m_vie<100) m_vie+=rand()%10;

	if (m_moral>100) m_moral=100;

	if (m_vie>100) m_vie=100;
}