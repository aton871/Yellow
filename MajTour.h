#ifndef DEF_MAJTOUR
#define DEF_MAJTOUR

#include "Personnage.h"
#include "Tresorie.h"
#include "Mineur.h"
#include "Bandit.h"
#include "SuperMineur.h"
#include "Ville.h"
#include "Evenements.h"

#include <vector>
#include <iostream>

void MajMinage(std::vector<Mineur> &listeMineurs, Tresorie &Tresor);

void MajRepos(std::vector<Mineur> &listeMineurs);

void MajAttaque(std::vector<Bandit> &listeBandits, Tresorie &Tresor);

void MajVenteOr(Ville &V,Tresorie &Tresor);

void MajDepenses(std::vector<Mineur> &listeMineurs,Tresorie &Tresor);

void MajPersonnages(std::vector<Mineur> &listeMineurs,std::vector<Bandit> &listeBandits);



#endif