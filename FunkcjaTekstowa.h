#ifndef FUNKCJATESKTOWA_H
#define FUNKCJATESKTOWA_H

#include <string>


struct FunkcjaTekstowa
{
	std::string* nazwaFunkcji;
	bool(*funkcja)(std::string*);
};

#endif

