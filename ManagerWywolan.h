#ifndef MANAGER_WYWOLAN_H
#define MANAGER_WYWOLAN_H

#include "FunkcjaTekstowa.h"

int ZbudujListe(FunkcjaTekstowa*& listaFunkcji);
bool WywolajPoNazwie(std::string* wywolanie, FunkcjaTekstowa* listaFunkcji, unsigned int n);
bool WczytajWywolanie(FunkcjaTekstowa* listaFunkcji, unsigned int liczbaFunkcji);
std::string ZwrocNazweFunkcji(std::string* wywolanie);

#endif //MANAGER_WYWOLAN_H
