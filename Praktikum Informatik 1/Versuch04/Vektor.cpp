//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <iostream>

// Konstruktor
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

// Destruktor
Vektor::~Vektor()
{

}

/// Funktion zur Ausgabe der Vektorkomponenten
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl;
}

/// Subtrahiert zwei Vektoren und gibt das Ergebnis als neuen Vektor zurück
Vektor Vektor::sub(const Vektor& input) const
{
    return Vektor(x - input.x, y - input.y, z - input.z);
}

/// Berechnet die Länge des Vektors
double Vektor::laenge() const
{
    return std::sqrt(x * x + y * y + z * z);
}

/// Berechnet das Skalarprodukt zweier Vektoren
double Vektor::skalarProd(const Vektor& input) const
{
    return x * input.x + y * input.y + z * input.z;
}

/// Berechnet den Winkel zwischen zwei Vektoren in Grad
double Vektor::winkel(const Vektor& input) const
{
    double dot = skalarProd(input);
    double lenProduct = laenge() * input.laenge();
    double angleRad = acos(dot / lenProduct);
    return angleRad * (180.0 / M_PI);  // Umrechnung von Radiant in Grad
}

/// Rotiert einen Vektor um die Z-Achse um den gegebenen Winkel in Radiant
void Vektor::rotiereUmZ(const double rad)
{
    double tempX = x * cos(rad) - y * sin(rad);
    double tempY = x * sin(rad) + y * cos(rad);
    x = tempX;
    y = tempY;
    // Z-Komponente bleibt unverändert
}

// calculateMaximumViewDistance fonksiyonu tanımı
double calculateMaximumViewDistance(double observerHeight, double earthRadius) {
    Vektor originVector(earthRadius, 0, 0);  // Orijinal konum vektörü
    Vektor viewDirection(earthRadius + observerHeight, 0, 0); // İlk bakış yönü, x ekseninde

    double maxDistance = 0.0;
    int steps = 0;
    const double incrementAngle = -0.00001;  // Açı artış miktarı radyan cinsinden, saat yönünde
    double finalBeta = 0;  // Final beta değeri

    for (double beta = 0; beta >= -M_PI/2; beta += incrementAngle) {
        viewDirection.rotiereUmZ(incrementAngle);  // Vektor 2'yi saat yönünde döndür
        Vektor distanceVector = viewDirection.sub(originVector);  // Vektor 3 hesaplanır

        if (distanceVector.laenge() >= earthRadius) {
            break;
        }

        double currentDistance = distanceVector.laenge();
        if (currentDistance > maxDistance) {
            maxDistance = currentDistance;  // En uzun mesafeyi güncelle
            finalBeta = beta;  // En iyi beta açısını kaydet
        }
        steps++;
    }

    // Açıyı radyandan dereceye çevirme
    double finalBetaDegrees = finalBeta * (180.0 / M_PI);

    std::cout << "Der Winkel beträgt " << finalBetaDegrees << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << steps << std::endl;

    return maxDistance / 1000.0;  // Metreyi kilometreye çevir
}
