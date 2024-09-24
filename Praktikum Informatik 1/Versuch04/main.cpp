//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cmath>
#include <iomanip>
#include "vektor.h"

// calculateMaximumViewDistance fonksiyonu tanımı
double calculateMaximumViewDistance(double observerHeight, double earthRadius);

int main()
{
    std::cout << std::fixed << std::setprecision(4);  // Sayısal çıktıları düzenler

    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);
    Vektor vector3(0, 0, 1);

    // Vektörlerin konsola yazdırılması
    std::cout << "Vector 1:" << std::endl;
    vector1.ausgabe();
    std::cout << "Vector 2:" << std::endl;
    vector2.ausgabe();
    std::cout << "Vector 3:" << std::endl;
    vector3.ausgabe();

    // Vektörlerin çıkarma işlemi
    Vektor subResult = vector1.sub(vector2);
    std::cout << "Subtraction of Vector 1 and Vector 2:" << std::endl;
    subResult.ausgabe();

    // Vektör uzunlukları
    std::cout << "Length of Vector 1: " << vector1.laenge() << std::endl;
    std::cout << "Length of Vector 2: " << vector2.laenge() << std::endl;

    // Skalar çarpım
    double dotProduct = vector1.skalarProd(vector2);
    std::cout << "Dot product of Vector 1 and Vector 2: " << dotProduct << std::endl;

    // İki vektör arası açı
    double angle = vector1.winkel(vector2);
    std::cout << "Angle between Vector 1 and Vector 2: " << angle << " degrees" << std::endl;

    // Vektörün z-ekseni etrafında döndürülmesi
    std::cout << "Vector 1 before rotation around Z-axis:" << std::endl;
    vector1.ausgabe();
    vector1.rotiereUmZ(M_PI / 4);  // 45 derece döndürme
    std::cout << "Vector 1 after rotation of 45 degrees around Z-axis:" << std::endl;
    vector1.ausgabe();

    Vektor vector4(0, 0, 0);  // Dummy vector since we are not using vector properties for this calculation

    const double observerHeight = 557.7;  // Gözlemci yüksekliği (555.7 m platform + 1.7 m insan boyu)
    const double earthRadius = 6371000;   // Dünya yarıçapı metre cinsinden

    double maxDistance = calculateMaximumViewDistance(observerHeight, earthRadius);

    std::cout << "Sie können " << maxDistance << " Km weit sehen." << std::endl;
    std::cout << "Sie sind " << observerHeight << " Meter hoch." << std::endl;

    return 0;
}

