//
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

#ifndef VEKTOR_H
#define VEKTOR_H

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * @brief Klasse, die einen Vektor im 3D-Raum darstellt
 */
class Vektor
{
public:
    /// Konstruktor zur Initialisierung der Vektorkomponenten
    Vektor(double x, double y, double z);

    /// Destruktor
    ~Vektor();

    /// Ausgabe der Vektorkomponenten
    void ausgabe() const;

    /// Subtrahiert zwei Vektoren
    Vektor sub(const Vektor& input) const;

    /// Berechnet die Länge des Vektors
    double laenge() const;

    /// Berechnet das Skalarprodukt zweier Vektoren
    double skalarProd(const Vektor& input) const;

    /// Berechnet den Winkel zwischen zwei Vektoren in Grad
    double winkel(const Vektor& input) const;

    /// Rotiert den Vektor um die Z-Achse um den gegebenen Winkel in Radiant
    void rotiereUmZ(const double rad);

private:
    double x; ///< X-Komponente des Vektors
    double y; ///< Y-Komponente des Vektors
    double z; ///< Z-Komponente des Vektors
};

#endif // VEKTOR_H
