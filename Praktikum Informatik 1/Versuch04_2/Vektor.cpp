//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

using namespace std;

/**
 * @brief Konstruktor zur Initialisierung der Vektorkomponenten
 * @param inX X-Komponente
 * @param inY Y-Komponente
 * @param inZ Z-Komponente
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{
}

/**
 * @brief Destruktor
 */
Vektor::~Vektor()
{
}

/**
 * @brief Ausgabe der Vektorkomponenten
 */
void Vektor::ausgabe() const
{
    cout << "X-Komponente: " << x << endl;
    cout << "Y-Komponente: " << y << endl;
    cout << "Z-Komponente: " << z << endl << endl;
}

/**
 * @brief Berechnet die Länge des Vektors
 * @return Die Länge des Vektors
 */
double Vektor::laenge() const
{
    return sqrt(x * x + y * y + z * z);
}

/**
 * @brief Berechnet das Skalarprodukt zweier Vektoren
 * @param input Der Vektor, mit dem das Skalarprodukt gebildet werden soll
 * @return Das Skalarprodukt
 */
double Vektor::skalarProd(const Vektor& input) const
{
    return x * input.x + y * input.y + z * input.z;
}

/**
 * @brief Berechnet den Winkel zwischen zwei Vektoren in Grad
 * @param input Der Vektor, mit dem der Winkel berechnet werden soll
 * @return Den Winkel zwischen den beiden Vektoren in Grad
 */
double Vektor::winkel(const Vektor& input) const
{
    double cosTheta = skalarProd(input) / (laenge() * input.laenge());
    return acos(cosTheta) * 180.0 / M_PI;
}

/**
 * @brief Subtrahiert zwei Vektoren
 * @param input Der Vektor, der subtrahiert werden soll
 * @return Den Ergebnisvektor (this - input)
 */
Vektor Vektor::sub(const Vektor& input) const
{
    return Vektor(x - input.x, y - input.y, z - input.z);
}

/**
 * @brief Rotiert den Vektor um die Z-Achse um den gegebenen Winkel in Radiant
 * @param rad Den Winkel in Radiant, um den der Vektor gedreht werden soll
 */
void Vektor::rotiereUmZ(const double rad)
{
    double tempX = cos(rad) * x - sin(rad) * y;
    double tempY = sin(rad) * x + cos(rad) * y;
    x = tempX;
    y = tempY;
}
