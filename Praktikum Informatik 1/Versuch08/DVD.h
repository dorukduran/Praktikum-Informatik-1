/*
 * DVD.h
 *
 *  Created on: 2 Tem 2024
 *      Author: ASUS
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

using namespace std;

class DVD: public Medium {
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();

	bool ausleihen(Person person, Datum ausleihdatum) override;
	void ausgabe(ostream& outStream = cout) const override;

private:
	int altersfreigabe;
	string genre;
};

#endif /* DVD_H_ */
