#ifndef DEF_CONSOLEDEV
#define DEF_CONSOLEDEV

#include <iostream>

#include "Tresorie.h"
#include "Personnage.h"
#include "Mineur.h"
#include "Ville.h"
#include "Bandit.h"
#include "Evenements.h"


void etatPersonnage(Personnage const& P);

void etatMineur(Mineur const& M);

void etatBandit(Bandit const& B);

void Finances(Tresorie const& Tresor);

void etatVille(Ville const& V);

void etatEvenements(Evenements const& CHAOS);

void cheat(Ville &V, Tresorie &Tresor, Personnage &P, Evenements &CHAOS);


#endif