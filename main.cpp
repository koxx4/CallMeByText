/*
Piotr W.
Informatyka Techniczna
Rok 1. Sem I.
Grupa ŚR TP
*/



/* 
2. Napisz program, który wprowadziwszy nazwę funkcji i jej argument, 
znajdzie w tablicy tę nazwę oraz odpowiedni wskaźnik do funkcji związanej z tą nazwą, 
a następnie wykona tę funkcję i wyprowadzi wynik. 
Przyjmij, że elementem tablicy jest struktura zawierająca wskaźnik do tekstu i wskaźnik do funkcji.

*/
#include <iostream>
#include "ManagerWywolan.h"


void Instrukcja();

int main()
{
    FunkcjaTekstowa* listaFunkcji = nullptr;
    unsigned int n = ZbudujListe(listaFunkcji);

    Instrukcja();
    while (1)
    {
        if (!WczytajWywolanie(listaFunkcji, 5))
            std::cout << "Niepoprawne wywolanie funkcji! Sprobuj ponownie\n";
    }

    delete[] listaFunkcji;

    std::cout << std::endl;
    system("pause");

    return 0;
}

void Instrukcja()
{
    system("cls");
    std::cout << "Witaj. Dostepne funkcje:\n";
    std::cout << "1.Przywtianie(twoje_imie), np Przywitanie(Arek)\n";
    std::cout << "2.TwojWiek(rok,miesiac,dzien), np TwojWiek(2001,5,28)\n";
    std::cout << "3.WydajReszte(cena,wplata), np WydajReszte(100,170)\n";
    std::cout << "4.PoleTrojkata(wysokos,podstawa), np PoleTrojkata(3.5,10)\n";
    std::cout << "5.PoleTrojkataH(a,b,c), np PoleTrojkata(4,5,3.4)\n\n";
}
