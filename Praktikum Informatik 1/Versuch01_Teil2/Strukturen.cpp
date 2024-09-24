/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

struct Person {
    std::string sNachname;
    std::string sVorname;
    int iGeburtsjahr;
    int iAlter;
};

int main() {
    Person nBenutzer;  // Person Variable nBenutzer deklarieren

    // Benutzerdaten eingeben
    std::cout << "Bitte geben Sie Ihren Nachnamen ein: ";
    std::cin >> nBenutzer.sNachname;
    std::cout << "Bitte geben Sie Ihren Vornamen ein: ";
    std::cin >> nBenutzer.sVorname;
    std::cout << "Bitte geben Sie Ihr Geburtsjahr ein: ";
    std::cin >> nBenutzer.iGeburtsjahr;
    std::cout << "Bitte geben Sie Ihr Alter ein: ";
    std::cin >> nBenutzer.iAlter;

    // Inhalt der nBenutzer Struktur ausgeben
    std::cout << "Nachname: " << nBenutzer.sNachname << std::endl;
    std::cout << "Vorname: " << nBenutzer.sVorname << std::endl;
    std::cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << std::endl;
    std::cout << "Alter: " << nBenutzer.iAlter << std::endl;

    // nBenutzer in eine neue Variable kopieren
    Person nKopieGesamt = nBenutzer;

    // Inhalte von nBenutzer einzeln in nKopieEinzeln kopieren
    Person nKopieEinzeln;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;

    // Ergebnisse der Kopien ausgeben
    std::cout << "Gesamtkopie - Nachname: " << nKopieGesamt.sNachname << ", Vorname: " << nKopieGesamt.sVorname << ", Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << ", Alter: " << nKopieGesamt.iAlter << std::endl;
    std::cout << "Einzelkopie - Nachname: " << nKopieEinzeln.sNachname << ", Vorname: " << nKopieEinzeln.sVorname << ", Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << ", Alter: " << nKopieEinzeln.iAlter << std::endl;

    return 0;
}
