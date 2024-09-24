///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort) {
    string verschluesselt = ""; // Verschlüsselte Wort speichern
    for (char &c : wort) {
        if (isalpha(c)) { // Prüfen, ob es ein Buchstabe ist
            c = toupper(c); // Den Buchstaben in Großbuchstaben umwandeln
            verschluesselt += schluessel[1][c - 'A']; // Mit der Schlüsseltabelle verschlüsseln
        } else {
            cout << "kein Buchstabe"; // Wenn kein Buchstabe, direkt hinzufügen
            exit(404);
        }
    }
    return verschluesselt;
}

// Schlüsseln zurückgesetzte Wort
string entschluesseln(char schluessel[2][26], string wort) {
    string entschluesselt = ""; // Entschlüsselte Wort speichern
    for (char &c : wort) {
        if (isalpha(c)) {
            int index = 0;
            while (index < 26 && schluessel[1][index] != c) { // Den Index des verschlüsselten Buchstabens finden
                ++index;
            }
            entschluesselt += schluessel[0][index]; // Originalen Buchstaben finden und hinzufügen
        } else {
            entschluesselt += c; // Wenn kein Buchstabe, direkt hinzufügen
        }
    }
    return entschluesselt;
}

int main() {
    // Schlüsseltabelle erstellen
    char schluessel[2][26];
    // Klartext-Buchstaben
    for (int i = 0; i < 26; i++) {
        schluessel[0][i] = 'A' + i;
    }
    // Gemischte Buchstaben (Beispiel einer Verschlüsselungsregel)
    string shuffled = "QWERTYUIOPLKJHGFDSAZXCVBNM";
    for (int i = 0; i < 26; i++) {
        schluessel[1][i] = shuffled[i];
    }

    // Benutzer nach einem Wort fragen
    string wort;
    cout << "Bitte geben Sie ein Wort ein: ";
    cin >> wort;

    // Wort verschlüsseln und ausgeben
    string verschluesselt = verschluesseln(schluessel, wort);
    cout << "Verschlüsseltes Wort: " << verschluesselt << endl;

    // Verschlüsseltes Wort entschlüsseln und ausgeben
    string entschluesselt = entschluesseln(schluessel, verschluesselt);
    cout << "Entschlüsseltes Wort: " << entschluesselt << endl;

    return 0;
}
