#include "Funkcje.h"
#include <time.h>
#include <math.h>

bool WypiszPrzywtianie(std::string* wywolanie)
{
	std::string* args = ZwrocArgumenty(wywolanie, 1);
	if (args == nullptr)
		return false;

	time_t obecnaData = time(0);

	tm strukturaDaty;
	localtime_s(&strukturaDaty, &obecnaData);

	printf("Witaj %s! Jest teraz %02d:%02d", args[0].c_str(), strukturaDaty.tm_hour, strukturaDaty.tm_min);

	return true;
}

bool WypiszTwojWiek(std::string* wywolanie)
{
	std::string* args = ZwrocArgumenty(wywolanie, 3);
	if (args == nullptr)
		return false;

	time_t obecnaData = time(0);

	tm dataUrodzin;
	tm lokalnaData;
	localtime_s(&lokalnaData, &obecnaData);

	try
	{
		dataUrodzin.tm_year = std::stoi(args[0]);
		dataUrodzin.tm_mon = std::stoi(args[1]) - 1;
		dataUrodzin.tm_mday = std::stoi(args[2]);
	}
	catch (const std::exception&)
	{
		return false;
	}

	unsigned int lat = (1900 + lokalnaData.tm_year) - dataUrodzin.tm_year;
	unsigned int miesiecy = (lokalnaData.tm_mon + 1) - (dataUrodzin.tm_mon + 1);
	unsigned int dni = lokalnaData.tm_mday - dataUrodzin.tm_mday;

	printf("Masz obecnie %d lat, %d miesiecy oraz %d dni", lat, miesiecy, dni);

	return true;
}

bool WydajReszte(std::string* wywolanie)
{
	std::string* args = ZwrocArgumenty(wywolanie, 2);
	if (args == nullptr)
		return false;

	unsigned int nominaly[] = { 20,10,5,2,1 };
	unsigned int cena;
	unsigned int wplata;
	int reszta;

	try
	{
		cena =   std::stoi(args[0]);
		wplata = std::stoi(args[1]);
		reszta = wplata - cena;
	}
	catch (const std::exception&)
	{
		return false;
	}

	if (reszta < 0)
		return false;
	if (reszta == 0)
	{
		printf("Nie ma co wydawac!");
		return false;
	}

	while (reszta > 0)
	{
		for (int i = 0; i < 5;)
		{
			reszta -= nominaly[i];
			if (reszta < 0)
			{
				reszta += nominaly[i];
				i++;
			}
			else
				printf("%d zl|", nominaly[i]);
		}
	}
	return true;
}

bool PoliczPoleTrojkata(std::string* wywolanie)
{
	std::string* args = ZwrocArgumenty(wywolanie, 2);
	if (args == nullptr)
		return false;

	double h = 0;
	double a = 0;

	try
	{
		h = std::stod(args[0]);
		a = std::stod(args[1]);
	}
	catch (const std::exception&)
	{
		return false;
	}

	printf("Pole trojkata wynosi %.2f", 0.5f * h * a);

	return true;
}

bool PoliczPoleTrojkataH(std::string* wywolanie)
{
	std::string* args = ZwrocArgumenty(wywolanie, 3);
	if (args == nullptr)
		return false;

	double a;
	double b;
	double c;

	try
	{
		a = std::stod(args[0]);
		b = std::stod(args[1]);
		c = std::stod(args[2]);
	}
	catch (const std::exception&)
	{
		return false;
	}

	double p = 0.5f * (a + b + c);
	double x = p * (p - a) * (p - b) * (p - c);
	if (x <= 0)
	{
		printf("Nie istnieje trojkat o podanych bokach\n");
		return false;
	}

	double pole = sqrtf(x);
	printf("Pole trojkata ze wzoru Herona to %.2f", pole);

	return true;
}

std::string* ZwrocArgumenty(std::string* wywolanie, unsigned int nOczekiwanychArgumentow)
{
	std::string* tablicaArg = new std::string[nOczekiwanychArgumentow];
	unsigned int lewyNawias = wywolanie->find_first_of('(');
	unsigned int prawyNawias = wywolanie->find_first_of(')');

	std::string argumenty = wywolanie->substr(lewyNawias + 1, prawyNawias - lewyNawias - 1);

	for (int i = 0; i < nOczekiwanychArgumentow; i++)
	{
		tablicaArg[i] = argumenty.substr(0, argumenty.find_first_of(','));

		//Jezeli podano za malo argumentow
		//to ciag znakow bedzie pusty
		if (tablicaArg[i].empty())
			return nullptr;

		argumenty.erase(0, tablicaArg[i].size() + 1);
	}

	return tablicaArg;
}