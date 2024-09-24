/*
 * Buch.cpp
 *
 *  Created on: 2 Tem 2024
 *      Author: ASUS
 */
#include "Buch.h"

using namespace std;

Buch::Buch(std::string initTitel, std::string initAutor):
	Medium(initTitel),
	autor(Person(initAutor, Datum())) {
	// TODO Auto-generated constructor stub

}

void Buch::ausgabe(ostream& outStream) const {

	Medium::ausgabe(outStream);

	outStream << "Name des Autors: " << this->autor.getName() << endl;

}

Buch::~Buch() {
	// TODO Auto-generated destructor stub
}



