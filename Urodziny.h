#ifndef URODZINY_H
#define URODZINY_H

enum Miesiac
{
	Styczen,
	Luty,
	Marzec,
	Kwiecien,
	Maj,
	Czerwiec,
	Lipiec,
	Sierpien,
	Wrzesien,
	Pazdziernik,
	Listopad,
	Grudzien
};

struct Data
{
	unsigned int rok;
	Miesiac miesiac;
	unsigned char dzien;
};


#endif

