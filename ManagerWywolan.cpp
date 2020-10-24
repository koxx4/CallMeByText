#include "ManagerWywolan.h"
#include "Funkcje.h"
#include <iostream>


int ZbudujListe(FunkcjaTekstowa*& listaFunkcji)
{
	unsigned int wielkoscTablicy = 5;
	listaFunkcji = new FunkcjaTekstowa[5];

	//1
	listaFunkcji[0].nazwaFunkcji =  new std::string("Przywitanie");
	listaFunkcji[0].funkcja = WypiszPrzywtianie;
	//2
	listaFunkcji[1].nazwaFunkcji = new std::string("TwojWiek");
	listaFunkcji[1].funkcja = WypiszTwojWiek;
	//3
	listaFunkcji[2].nazwaFunkcji =  new std::string("WydajReszte");
	listaFunkcji[2].funkcja = WydajReszte;
	//4
	listaFunkcji[3].nazwaFunkcji = new std::string("PoleTrojkata");
	listaFunkcji[3].funkcja = PoliczPoleTrojkata;
	//5
	listaFunkcji[4].nazwaFunkcji = new std::string("PoleTrojkataH");
	listaFunkcji[4].funkcja = PoliczPoleTrojkataH;

	return wielkoscTablicy;
}

bool WywolajPoNazwie(std::string* wywolanie, FunkcjaTekstowa* listaFunkcji, unsigned int n)
{
	std::string nazwaFunkcji = ZwrocNazweFunkcji(wywolanie);

	for (int i = 0; i < n; i++)
	{
		if (nazwaFunkcji.empty())
			return false;
		else if (*(listaFunkcji[i].nazwaFunkcji) == nazwaFunkcji)
		{
			return listaFunkcji[i].funkcja(wywolanie);
		}
	}

	//Jezeli nie znaleziono odpowiadajacej funkcji
	return false;
}

std::string ZwrocNazweFunkcji(std::string* wywolanie)
{
	unsigned int index = wywolanie->find_first_of('(');
	if (index == std::string::npos)
		return "";

	return wywolanie->substr(0, index);
}

bool WczytajWywolanie(FunkcjaTekstowa* listaFunkcji, unsigned int liczbaFunkcji)
{
	std::string wywolanie;

	std::cout << "\nWywolanie: ";
	std::getline(std::cin, wywolanie);

	return WywolajPoNazwie(&wywolanie, listaFunkcji, liczbaFunkcji);
}
