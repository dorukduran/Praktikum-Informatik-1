/*
 * Magazin.cpp
 *
 *  Created on: 2 Tem 2024
 *      Author: ASUS
 */
#include "Magazin.h"

using namespace std;

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte):
	Medium(initTitel),
	erscheinungsdatum(initDatumAusgabe),
	sparte(initSparte) {

}

void Magazin::ausgabe(ostream& outStream) const  {

	Medium::ausgabe(outStream);
	outStream << "Ausgabe: " << this->erscheinungsdatum << endl;
	outStream << "Sparte: " << this->sparte << endl;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum) {
	if ((ausleihdatum - this->erscheinungsdatum)  <= 0) {
		cout << "Die neueste Ausgabe von Magazinen dürfen nicht ausgeliehen werden." << endl;
		return false;
	} else {
		return Medium::ausleihen(person, ausleihdatum);
	}
}


Magazin::~Magazin() {
	// TODO Auto-generated destructor stub
}



