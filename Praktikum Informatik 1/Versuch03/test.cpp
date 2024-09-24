/**
 * Praktikum Informatik 1 MMXXIV
 *
 * @file test.cpp
 *
 * Stellt Funktionen zum Testen der Spielfunktionen zur Verfuegung
 */


#include <iostream>
#include "config.h"
#include "test.h"


/*
 * Deklaration der in den Tests verwendeten Funktionen.
 * Dadurch weiss der Compiler, das es sich bei den Namen
 * um Funktionsaufrufe handelt, die in einer anderen Datei
 * definiert sind (extern).
 */
extern void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X]);
extern int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X]);
extern bool aufSpielfeld(const int posX, const int posY);
extern bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X],  const int player, const int posX, const int posY);
extern void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int player, const int posX, const int posY);
extern int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int player);


/**
 * @brief Funktion zum Testen der gewinner() Funktion.
 *
 * @param eingabefeld Das zu testende Spielfeld.
 * @param richtig Der erwartete Gewinner.
 * @param testNummer Nummer des laufenden Tests
 * @return True wenn der berechnete Gewinner und der erwartete Gewinner uebereinstimmen. False ansonsten.
 */
bool gewinnerTest(const int eingabefeld[GROESSE_Y][GROESSE_X], const int richtig, const int testNummer)
{
    std::cout << "Fuehre Test " << testNummer + 1 << " fuer 'gewinner()' aus ..." << std::endl;
    std::cout << "----------------------------------" << std::endl << std::endl;
    int ergebnis = gewinner(eingabefeld);
    if (ergebnis == richtig)
    {
        std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl << std::endl;
        if (AUSFUEHRLICH == 1)
        {
            zeigeSpielfeld(eingabefeld);
            std::cout << std::endl << "Berechnetes Ergebnis: " << ergebnis << std::endl << "Richtiges Ergebnis: " << richtig
                      << std::endl << std::endl;
        }
        return false;
    }
}


/**
 * @brief Funktion zum Testen der aufSpielfeld() Funktion
 *
 * @param posX Index Spalte
 * @param posY Index Zeile
 * @param richtig Das erwartete Ergebnis
 * @param testNummer Nummer des laufenden Tests
 * @return True wenn Test bestanden, ansonsten false
 */
bool aufSpielfeldTest(const int posX, const int posY, const bool richtig, const int testNummer)
{
    /// ueberprueft, ob eine gegebene Position auf dem Spielfeld ist

    bool ergebnis = aufSpielfeld(posX, posY);
    std::cout << "Test " << testNummer + 1 << " fuer 'aufSpielfeld()' ausfuehren..." << std::endl;

    if (ergebnis == richtig)
    {
        std::cout << "Test " << testNummer + 1 << " bestanden!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test " << testNummer + 1 << " fehlgeschlagen" << std::endl;
        std::cout << "Erwartet: " << (richtig ? "true" : "false") << ", Erhalten: " << (ergebnis ? "true" : "false") << std::endl;
        return false;
    }
    return 0;
}

/**
 * @brief Funktion zum Testen der zugGueltig() Funktion
 *
 * @param eingabeFeld Das zu testende Spielfeld
 * @param spieler Der Spieler, der den Zug macht
 * @param posX Die zu überprüfende Spalte
 * @param posY Die zu überprüfende Zeile
 * @param richtig Das erwartete Ergebnis
 * @param testNummer Nummer des laufenden Tests
 * @return True, wenn der Zug gültig ist, ansonsten false
 */
bool zugGueltigTest(const int eingabeFeld[GROESSE_Y][GROESSE_X], const int spieler, const int posX,
                     const int posY, const bool richtig, const int testNummer)
{
    /// ueberprueft, ob der Zug fuer eine gegebene Position gueltig ist
    bool ergebnis = zugGueltig(eingabeFeld, spieler, posX, posY);
    /// wenn AUSFUEHRLICH gleich 1 wird zusaetzlich das Spielfeld und die ungueltige Position ausgegeben
    if (AUSFUEHRLICH == 1) {
        std::cout << "Test " << testNummer + 1 << ": Überprüfung der Position (" << posX << ", " << posY << ")" << std::endl;
        std::cout << "Erwartetes Ergebnis: " << (richtig ? "true" : "false") << ", Tatsächliches Ergebnis: " << (ergebnis ? "true" : "false") << std::endl;
        if (!ergebnis == richtig) {
            std::cout << "Fehler gefunden! Spielfeldausgabe:" << std::endl;
            for (int j = 0; j < GROESSE_Y; ++j) {
                for (int i = 0; i < GROESSE_X; ++i) {
                    std::cout << eingabeFeld[j][i] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
    return ergebnis == richtig;


}

/**
 * @brief Funktion zum Testen der zugAusfuehren() Funktion
 *
 * @param eingabeFeld Das ursprüngliche Spielfeld vor dem Zug
 * @param ergebnisFeld Das erwartete Spielfeld nach dem Zug
 * @param spieler Der Spieler, der den Zug macht
 * @param posX Die Spalte, in die der Spieler den Zug macht
 * @param posY Die Zeile, in die der Spieler den Zug macht
 * @param testNummer Nummer des laufenden Tests
 * @return True, wenn der Zug korrekt ausgeführt wurde, ansonsten false
 */
bool zugAusfuehrenTest(int eingabeFeld[GROESSE_Y][GROESSE_X], const int ergebnisFeld[GROESSE_Y][GROESSE_X],
                       const int spieler, const int posX, const int posY, const int testNummer)
{
    /// Kopiere das Spielfeld
    int testFeld[GROESSE_Y][GROESSE_X];
    for (int y = 0; y < GROESSE_Y; ++y) {
        for (int x = 0; x < GROESSE_X; ++x) {
            testFeld[y][x] = eingabeFeld[y][x];
        }
    }

    /// Führe den Zug auf dem Testspielfeld aus
    zugAusfuehren(testFeld, spieler, posX, posY);

    /// Vergleiche das Ergebnis mit dem erwarteten Ergebnis
    bool testErgebnis = true;
    for (int y = 0; y < GROESSE_Y; ++y) {
        for (int x = 0; x < GROESSE_X; ++x) {
            if (testFeld[y][x] != ergebnisFeld[y][x]) {
                testErgebnis = false;
                break;
            }
        }
        if (!testErgebnis) break;
    }

    if (AUSFUEHRLICH == 1) {
        std::cout << "Test " << testNummer << ": " << (testErgebnis ? "Erfolgreich" : "Fehlgeschlagen") << std::endl;
        std::cout << "Erwartetes Spielfeld vs. Tatsächliches Spielfeld:" << std::endl;
        for (int y = 0; y < GROESSE_Y; ++y) {
            for (int x = 0; x < GROESSE_X; ++x) {
                std::cout << ergebnisFeld[y][x] << " ";
            }
            std::cout << "    ";
            for (int x = 0; x < GROESSE_X; ++x) {
                std::cout << testFeld[y][x] << " ";
            }
            std::cout << std::endl;
        }
    }

    return testErgebnis;
}

/**
 * @brief Funktion zum Testen der moeglicheZuege() Funktion
 *
 * @param eingabeFeld Das zu testende Spielfeld
 * @param spieler Der Spieler, der die möglichen Züge macht
 * @param richtig Die erwartete Anzahl der möglichen Züge
 * @param testNummer Nummer des laufenden Tests
 * @return True, wenn die Anzahl der möglichen Züge korrekt berechnet wurde, ansonsten false
 */
bool moeglicheZuegeTest(const int eingabeFeld[GROESSE_Y][GROESSE_X], const int spieler,
                         const int richtig, const int testNummer)
{
    /// Berechne die Anzahl der möglichen Züge für den Spieler
    int berechneteZuege = moeglicheZuege(eingabeFeld, spieler);

    /// Überprüfe das Testergebnis: Der berechnete Wert sollte dem erwarteten Wert entsprechen
    bool ergebnis = (berechneteZuege == richtig);

    /// Wenn der AUSFUEHRLICH-Modus aktiviert ist, drucke zusätzliche Informationen
    if (AUSFUEHRLICH == 1) {
        std::cout << "Test " << testNummer << ": Überprüfung der möglichen Züge für Spieler " << spieler << std::endl;
        std::cout << "Erwartetes Ergebnis: " << richtig << ", Berechnetes Ergebnis: " << berechneteZuege << std::endl;
        if (!ergebnis) {
            std::cout << "Fehler gefunden! Spielfeldausgabe:" << std::endl;
            for (int y = 0; y < GROESSE_Y; ++y) {
                for (int x = 0; x < GROESSE_X; ++x) {
                    std::cout << eingabeFeld[y][x] << " ";
                }
                std::cout << std::endl;
            }
        }
    }

    /// Rückgabe des Testergebnisses
    return ergebnis;
}

/**
 * @brief Funktion, die alle Tests ausfuehrt
 *
 * @return True, wenn alle Tests bestanden wurden, ansonsten false
 */
bool ganzenTestAusfuehren()
{
    bool gesamtErgebnis = true;

    /// Jeder Test steht in einem eigenen Block {}, damit es keine Namenskonflikte gibt
    /// z.B. eingabeFeld oder korrektesErgebnis

    /// ---------- TESTE GEWINNER ---------- //
    {
        int eingabeFeld[3][8][8] = {
            {   {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2},
                {1, 2, 1, 2, 1, 2, 1, 2}
            },

            {   {1, 1, 2, 1, 1, 2, 1, 1},
                {2, 1, 1, 2, 1, 1, 2, 1},
                {1, 2, 1, 1, 2, 1, 1, 2},
                {1, 1, 2, 1, 1, 2, 1, 1},
                {2, 1, 1, 2, 1, 1, 2, 1},
                {1, 2, 1, 1, 2, 1, 1, 2},
                {1, 1, 2, 1, 1, 2, 1, 1},
                {2, 1, 1, 2, 1, 1, 2, 1}
            },

            {   {1, 2, 2, 1, 2, 2, 1, 2},
                {2, 1, 2, 2, 1, 2, 2, 1},
                {2, 2, 1, 2, 2, 1, 2, 2},
                {1, 2, 2, 1, 2, 2, 1, 2},
                {2, 1, 2, 2, 1, 2, 2, 1},
                {2, 2, 1, 2, 2, 1, 2, 2},
                {1, 2, 2, 1, 2, 2, 1, 2},
                {2, 1, 2, 2, 1, 2, 2, 1}
            }
        };

        int korrektesErgebnis[3] = {0, 1, 2};

        for (int i = 0; i < 3; i++)
        {
            bool tmp_ergebnis = gewinnerTest(eingabeFeld[i], korrektesErgebnis[i], i);
            if (gesamtErgebnis == true && tmp_ergebnis == false)
            {
                gesamtErgebnis = false;
            }
        }

        std::cout << "Ende des Tests fuer 'gewinner()'" << std::endl << std::endl;
    }

    /// ---------- TESTE POSITION IM FELD ---------- //
    {
        int position[6][2] = { {2, 3}, {0, 8}, {-1, 7}, {2, -1}, {8, 5}, {-1,8} };   /// posX, posY
        bool korrektesErgebnis[6] = {true, false, false, false, false, false};

        for (int i = 0; i < 6; i++)
        {
            bool ergebnis = aufSpielfeld(position[i][0], position[i][1]);
            if (ergebnis != korrektesErgebnis[i]) {
                std::cout << "Test " << i + 1 << " fehlgeschlagen. Erwartet: " << (korrektesErgebnis[i] ? "true" : "false")
                          << ", Erhalten: " << (ergebnis ? "true" : "false") << std::endl;
                gesamtErgebnis = false;
            } else {
                std::cout << "Test " << i + 1 << " bestanden." << std::endl;
            }
        }
        std::cout << "Ende des Tests fuer 'im Feld'" << std::endl << std::endl;
    }

    /// ---------- TESTE ZUG GUELTIG ---------- //
    {
        int eingabeFeld[7][8][8] = {
                {   {1, 0, 2, 0, 0, 1, 1, 1},
                    {0, 0, 2, 0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0, 1, 2, 2},
                    {2, 2, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 2, 0},
                    {0, 0, 0, 2, 1, 1, 0, 2},
                    {1, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 0, 1}
                },

                {   {1, 0, 2, 0, 0, 1, 1, 1},
                    {0, 0, 2, 0, 0, 1, 0, 0},
                    {0, 0, 2, 0, 0, 2, 1, 1},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 2, 0},
                    {0, 0, 0, 2, 1, 1, 0, 2},
                    {1, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 0, 1}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 1, 0, 0, 2, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 0},
                    {2, 0, 1, 2, 0, 2, 0, 0},
                    {0, 2, 0, 2, 2, 2, 2, 2},
                    {0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 2, 2, 2},
                    {0, 2, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 1, 1, 1, 0, 0}
                },

                {   {2, 1, 0, 0, 2, 1, 1, 1},
                    {0, 2, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 2, 0, 0, 0, 1},
                    {0, 1, 1, 1, 0, 1, 0, 0},
                    {1, 0, 0, 1, 1, 0, 0, 2},
                    {0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 1, 0, 0, 0, 0, 2, 0},
                    {1, 1, 2, 0, 0, 2, 2, 1}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {
                    {1, 2, 2, 2, 2, 2, 2, 2},
                    {1, 2, 1, 1, 2, 2, 2, 2},
                    {1, 1, 1, 2, 2, 2, 2, 2},
                    {1, 1, 1, 2, 2, 2, 2, 2},
                    {1, 1, 1, 1, 2, 2, 2, 2},
                    {1, 1, 1, 0, 2, 2, 2, 2},
                    {1, 0, 0, 0, 2, 0, 0, 2},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                }
            };

        int spieler[7] = {1, 2, 2, 1, 2, 1,1};
        int position[7][2] = { {2, 3}, {0, 3}, {4, 3}, {3, 4}, {3, 5}, {3, 4}, {5, 7} };  /// posX, posY
        bool korrektesErgebnis[7] = {false, false, false, true, true, false, false};

        for (int i = 0; i < 7; i++)
        {
            /// Hier erfolgt jetzt Ihre Implementierung (entsprechende Testfunktion aufrufen) ...
            bool testErgebnis = zugGueltigTest(eingabeFeld[i], spieler[i], position[i][0], position[i][1], korrektesErgebnis[i], i);
            if (testErgebnis) {
                std::cout << "Test " << i+1 << " bestanden." << std::endl;
            } else {
                std::cout << "Test " << i+1 << " fehlgeschlagen." << std::endl;
            }
        }
        std::cout << "Ende des Tests fuer 'zugGueltig'" << std::endl << std::endl;
    }

    /// ---------- TESTE ZUG AUSFUEHREN ---------- //
    {
        int eingabeFeld[10][8][8] = {
                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 2, 2},
                    {2, 2, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 1, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 0},
                    {0, 0, 0, 2, 0, 2, 0, 0},
                    {0, 0, 0, 2, 2, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 1, 0},
                    {0, 0, 0, 2, 0, 2, 0, 0},
                    {0, 0, 0, 2, 2, 0, 0, 0},
                    {0, 1, 2, 0, 2, 2, 1, 0},
                    {0, 0, 0, 2, 2, 0, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 1, 1, 1, 1, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 2, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 2, 1},
                    {1, 0, 1, 1, 2, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 1, 0, 1},
                    {0, 0, 0, 0, 0, 2, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 2, 2, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 2, 0, 0, 2, 0, 0},
                    {0, 1, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                }
            };

        int ergebnisFeld[10][8][8] {
                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 2, 2},
                    {2, 2, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 1, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 2, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 2, 0, 1, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 1, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1, 0, 0, 0},
                    {0, 1, 1, 1, 1, 1, 1, 0},
                    {0, 0, 0, 1, 1, 0, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 0, 0},
                    {0, 0, 0, 0, 2, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 0, 0},
                    {0, 0, 2, 1, 1, 1, 1, 0},
                    {0, 0, 2, 0, 0, 0, 0, 0},
                    {0, 0, 2, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 2, 1},
                    {1, 2, 2, 2, 2, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },
                {   {0, 0, 0, 0, 0, 1, 0, 1},
                    {0, 0, 0, 0, 0, 1, 1, 0},
                    {0, 0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 1, 1, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 0},
                    {0, 0, 2, 0, 0, 2, 0, 0},
                    {0, 1, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                }
            };

        int spieler[10]={0,0,0,1,2,0,1,2,2,1};
        int position[10][2]=                       /// eine andere, moegliche Darstellung
                    {                              /// der gegebenen Positionen posX, posY
                        {0,0},
                        {0,0},
                        {0,0},
                        {3,4},
                        {3,5},
                        {0,0},
                        {3,4},
                        {2,4},
                        {1,4},
                        {5,2}
                    };

        for (int i = 0; i < 10; i++)
        {
            bool testErgebnis = zugAusfuehrenTest(eingabeFeld[i], ergebnisFeld[i], spieler[i], position[i][0], position[i][1], i);
            if (testErgebnis) {
                std::cout << "Test " << i + 1 << " bestanden." << std::endl;
            } else {
                std::cout << "Test " << i + 1 << " fehlgeschlagen." << std::endl;
            }
        }
        std::cout << "Ende des Tests für 'zugAusfuehren()'" << std::endl << std::endl;
    }

    /// ---------- TESTE MOEGLICHE ZUEGE ---------- //
    {
        int eingabeFeld[2][8][8] {
                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 2, 0, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                },

                {   {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 2, 1, 1, 0, 0},
                    {0, 0, 0, 2, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0}
                }
            };

        int spieler[2] = {1, 1};
        int korrektesErgebnis[2] = {4, 5};

        for (int i = 0; i < 2; i++) {
            int ergebnis = moeglicheZuege(eingabeFeld[i], spieler[i]);
            bool testErgebnis = (ergebnis == korrektesErgebnis[i]);
            if (testErgebnis) {
                std::cout << "Test " << i + 1 << " für mögliche Züge bestanden. Gefundene Züge: " << ergebnis << std::endl;
            } else {
                std::cout << "Test " << i + 1 << " für mögliche Züge fehlgeschlagen. Erwartet: " << korrektesErgebnis[i] << ", Gefunden: " << ergebnis << std::endl;
            }
        }

        std::cout << "Ende des Tests für 'moeglicheZuege()'" << std::endl << std::endl;
    }

    return gesamtErgebnis;
}
