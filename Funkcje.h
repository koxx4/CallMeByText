#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <string>
#include "Urodziny.h"


bool    WypiszPrzywtianie(std::string* wywolanie);
bool    WypiszTwojWiek(std::string* wywolanie);
bool    WydajReszte(std::string* wywolanie);
bool    PoliczPoleTrojkata(std::string* wywolanie);
bool    PoliczPoleTrojkataH(std::string* wywolanie);

std::string* ZwrocArgumenty(std::string* wywolanie, unsigned int nOczekiwanychArgumentow);

#endif
