#pragma once
#include "biblioteka.h"

class Studentai {
private:
	string vardas;
	string pavarde;
	float galbal;
	float med;

public:
	Studentai(string vardass, string pavardee, float galball, float medd) :
		vardas{ vardass },
		pavarde{ pavardee },
		galbal{ galball },
		med{ medd } {};

	Studentai(const Studentai& g) :
		vardas{ g.vardas },
		pavarde{ g.pavarde },
		galbal{ g.galbal },
		med{ g.med } {};

	Studentai& operator=(const Studentai& g) {
		vardas = g.vardas;
		pavarde = g.pavarde;
		galbal = g.galbal;
		med = g.med;
		return *this;
	}
};