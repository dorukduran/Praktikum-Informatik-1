/*
 * Magazin.h
 *
 *  Created on: 2 Tem 2024
 *      Author: ASUS
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"

using namespace std;


class Magazin: public Medium {
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	virtual ~Magazin();


	bool ausleihen(Person person, Datum ausleihdatum) override;
	void ausgabe(ostream& outStream = cout) const override;

private:
	Datum erscheinungsdatum;
	string sparte;
};

#endif /* MAGAZIN_H_ */
