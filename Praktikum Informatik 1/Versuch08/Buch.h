/*
 * Buch.h
 *
 *  Created on: 2 Tem 2024
 *      Author: ASUS
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch : public Medium {
public:
	Buch(std::string initTitel, std::string initAutor);
	virtual ~Buch();

	void ausgabe(ostream& outStream = cout) const override ;

private:
	Person autor;
};

#endif /* BUCH_H_ */
