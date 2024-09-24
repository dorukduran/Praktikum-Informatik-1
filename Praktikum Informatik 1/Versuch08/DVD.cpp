/*
 * DVD.cpp
 *
 *  Created on: 2 Tem 2024
 *      Author: ASUS
 */
#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre):
	Medium(initTitel),
	altersfreigabe(initAltersfreigabe),
	genre(initGenre) {
}

bool DVD::ausleihen(Person person, Datum ausleihdatum) {
	if ((ausleihdatum - person.getGeburtsdatum())  < (this->altersfreigabe * 12)) {
		cout << "Die ausleihende Person ist nicht alt genug für diese DVD." << endl;
		return false;
	} else {
		return Medium::ausleihen(person, ausleihdatum);
	}
}

void DVD::ausgabe(ostream& outStream) const {

	Medium::ausgabe(outStream);
	outStream << "FSK: ab " << this->altersfreigabe << " Jahre" << endl;
	outStream << "Genre: " << this->genre << endl;
}

DVD::~DVD() {
	// TODO Auto-generated destructor stub
}



