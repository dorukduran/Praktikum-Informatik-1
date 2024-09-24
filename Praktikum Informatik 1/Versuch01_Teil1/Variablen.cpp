//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int iErste = 0; // Erste eingegebene Zahl
    int iZweite = 0; // Zweite eingegebene Zahl


    int iSumme = 0; // Summe der Zahlen
    int iQuotient = 0; // Ganzzahliger Quotient der Zahlen
    double dSumme = 0.0; // Summe als double
    double dQuotient = 0.0; // Quotient als double
    double dSummeCast = 0.0; // Summe mit Typumwandlung zu double
    double dQuotientCast = 0.0; // Quotient mit Typumwandlung zu double
    string sVorname; // Vorname des Benutzers
    string sNachname; // Nachname des Benutzers
    string sVornameName; // Vollständiger Name in der Form "Vorname Nachname"
    string sNameVorname; // Vollständiger Name in der Form "Nachname, Vorname"

    // Zahlen von Benutzer einlesen
    cout << "Bitte geben Sie die erste Zahl ein: ";
    cin >> iErste;
    cout << "Bitte geben Sie die zweite Zahl ein: ";
    cin >> iZweite;

    // Berechnungen durchführen
    iSumme = iErste + iZweite;
    iQuotient = iErste / iZweite;
    cout << "Summe (int): " << iSumme << endl;
    cout << "Quotient (int): " << iQuotient << endl;

    dSumme = iErste + iZweite;
    dQuotient = static_cast<double>(iErste) / iZweite;
    cout << "Summe (double): " << dSumme << endl;
    cout << "Quotient (double): " << dQuotient << endl;

    dSummeCast = static_cast<double>(iErste) + static_cast<double>(iZweite);
    dQuotientCast = static_cast<double>(iErste) / static_cast<double>(iZweite);
    cout << "Summe mit Typecasting (double): " << dSummeCast << endl;
    cout << "Quotient mit Typecasting (double): " << dQuotientCast << endl;

    // Namen von Benutzer einlesen
    cout << "Bitte geben Sie Ihren Vornamen ein: ";
    cin >> sVorname;
    cout << "Bitte geben Sie Ihren Nachnamen ein: ";
    cin >> sNachname;

    sVornameName = sVorname + " " + sNachname;
    sNameVorname = sNachname + ", " + sVorname;
    cout << "Vollständiger Name: " << sVornameName << endl;
    cout << "Name, Vorname: " << sNameVorname << endl;

    // ASCII-Werte und Positionen im deutschen Alphabet berechnen
    int iName1 = static_cast<int>(sVorname[0]);
    int iName2 = static_cast<int>(sVorname[1]);
    cout << "ASCII Wert des ersten Buchstabens: " << iName1 << endl;
    cout << "ASCII Wert des zweiten Buchstabens: " << iName2 << endl;

    int position1 = ((toupper(iName1) - 'A') % 26) + 1;
    int position2 = ((toupper(iName2) - 'A') % 26) + 1;
    cout << "Position des ersten Buchstabens im deutschen Alphabet: " << position1 << endl;
    cout << "Position des zweiten Buchstabens im deutschen Alphabet: " << position2 << endl;

    // Array-Operationen in einem Block
    {
        int iFeld[2] = {1, 2}; // Zweielementiges Array
        cout << "Wert von iFeld[0]: " << iFeld[0] << endl;
        cout << "Wert von iFeld[1]: " << iFeld[1] << endl;

        int spielfeld[2][3] = {{1, 2, 3}, {4, 5, 6}}; // 2x3 Array
        cout << "Spielfeld Werte:" << endl;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << spielfeld[i][j] << " ";
            }
            cout << endl;
    }

        const int iZweiteConst = 1; // Konstante im Block definieren
        cout << "Wert von iZweite im Block: " << iZweiteConst << endl;
    }

    return 0;
}
