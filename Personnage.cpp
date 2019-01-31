#include "Personnage.h"

#include <string>
#include <iostream>

Personnage::Personnage(int vie, int moral, std::string nom, bool joueur) : m_vie(vie),m_moral(moral),m_nom(nom),m_joueur(joueur){

}


int Personnage::getMoral() const{

	return(m_moral);
}


int Personnage::getVie() const{

	return(m_vie);
}


std::string Personnage::getNom() const{

	return(m_nom);
}

bool Personnage::estJoueur() const{

	return(m_joueur);

}

bool Personnage::estVivant() const{

	if(m_vie<1) return(false);

	else return(true);
} 


void Personnage::degats(int viePerdu){

	m_vie -= viePerdu;

	if (m_vie<0) m_vie=0;

}


void Personnage::soigner(int vieRecup){

	m_vie+=vieRecup;

	if (m_vie==0) m_vie=0;

	else if (m_vie>100 && m_joueur==false) m_vie=100;

	else if (m_vie>101 && m_joueur==true) m_vie=101;

}

void Personnage::demoralisation(int moralPerdu){

	m_moral-=moralPerdu;

}

void Personnage::cheatVie(int vie){

	m_vie=vie;
}


void Personnage::cheatMoral(int moral){

	m_moral=moral;
}


