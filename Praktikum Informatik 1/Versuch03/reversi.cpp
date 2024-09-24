/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
    {
        for(int i = 0; i < GROESSE_X; i++)
        {
            spielfeld[j][i] = 0;
        }
    }
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}

/**
 * @brief Ausgabe des Spielfelds auf der Konsole
 *
 * Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler 2.
 * Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren.
 *
 * @param spielfeld Spielfeld, das ausgeben wird
 */
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    /// Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | ";

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   ";
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        }  /// for i
        std::cout << std::endl;
    }  /// for j
}

/**
 * @brief Prueft, wer der Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld und ermittelt den Gewinner.
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return Gewinner (0 bei Unentschieden, 1 bei Spieler 1, 2 bei Spieler 2)
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }
        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
 * @brief Ueberprueft, ob zwei Indizes auf dem Spielfeld sind
 *
 * @param posX Index fuer die Spalte
 * @param posY Index fuer die Zeile
 * @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
 */
bool aufSpielfeld(const int posX, const int posY)
{
    return (posX >= 0 && posX < GROESSE_X) && (posY >= 0 && posY < GROESSE_Y);
}

/**
 * @brief Ueberprueft, ob der Zug gueltig ist
 *
 * Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt. Wenn ja, wird diese Richtung solange untersucht,
 * bis ein eigener Stein gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld gefunden, wird false zurueckgegeben, sonst true.
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return true, wenn der Zug gueltig ist, sonst false
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; /// dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       ///               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) /// ist das Feld leer?
    {
        return false;
    }

    /// Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            if (j == 0 && i == 0) continue;

            int currentX = posX + i;
            int currentY = posY + j;
            bool opponentFound = false;

            /// Mevcut yön boyunca ilerle
            while (currentX >= 0 && currentX < GROESSE_X && currentY >= 0 && currentY < GROESSE_Y) {
                if (spielfeld[currentY][currentX] == gegner) {
                    opponentFound = true; /// Gegnerischer Stein gefunden
                    currentX += i;
                    currentY += j;
                } else if (spielfeld[currentY][currentX] == aktuellerSpieler && opponentFound) {
                    return true; /// Gegnerischer Stein gefolgt von eigenem Stein gefunden, Zug ist gültig
                } else {
                    break; /// Leeres Feld oder eigener Stein ohne vorher gegnerischen Stein, Schleife beenden
                }
            }
        }
    }

    return false;
}

/**
 * @brief Fuehrt einen Zug aus
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY) {
    int gegner = 3 - aktuellerSpieler;
    spielfeld[posY][posX] = aktuellerSpieler;  /// Setze den Stein des Spielers auf das Spielfeld.

    /// Doppelschleife zum Überprüfen aller Richtungen.
    for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
            if (i == 0 && j == 0) continue;  /// Überspringe die eigene Position.

            int currentX = posX + i;
            int currentY = posY + j;
            bool foundOpponent = false;

            /// Solange in die aktuelle Richtung gehen, bis Gegnerstein gefunden wird.
            while (currentX >= 0 && currentX < GROESSE_X && currentY >= 0 && currentY < GROESSE_Y) {
                if (spielfeld[currentY][currentX] == gegner) {
                    foundOpponent = true;
                    currentX += i;
                    currentY += j;
                } else {
                    break;
                }
            }

            /// Wenn eigener Stein nach Gegnersteinen gefunden, dann alle Gegnersteine in dieser Richtung umdrehen.
            if (foundOpponent && currentX >= 0 && currentX < GROESSE_X && currentY >= 0 && currentY < GROESSE_Y && spielfeld[currentY][currentX] == aktuellerSpieler) {
                currentX -= i;
                currentY -= j;
                while (currentX != posX || currentY != posY) {
                    spielfeld[currentY][currentX] = aktuellerSpieler;
                    currentX -= i;
                    currentY -= j;
                }
            }
        }
    }
}

/**
 * @brief Ermittelt die Anzahl moeglicher Zuege fuer einen Spieler
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return Anzahl der moeglichen Zuege
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler) {
    int gegner = 3 - aktuellerSpieler; /// Bestimmt den gegnerischen Spieler
    int anzahlMoeglicheZuege = 0; /// Variable, um die Anzahl der möglichen Züge zu speichern

    /// Doppelschleife zum Überprüfen jeder Zelle des Spielfelds
    for (int y = 0; y < GROESSE_Y; y++) {
        for (int x = 0; x < GROESSE_X; x++) {
            /// Überprüft nur leere Zellen
            if (spielfeld[y][x] == 0) {
                /// Überprüft jede Richtung
                for (int j = -1; j <= 1; j++) {
                    for (int i = -1; i <= 1; i++) {
                        if (j == 0 && i == 0) continue; /// Überspringt die eigene Position

                        int currentX = x + i;
                        int currentY = y + j;
                        bool foundOpponent = false;

                        /// Verfolgt gegnerische Steine in eine bestimmte Richtung
                        while (currentX >= 0 && currentX < GROESSE_X && currentY >= 0 && currentY < GROESSE_Y) {
                            if (spielfeld[currentY][currentX] == gegner) {
                                foundOpponent = true;
                                currentX += i;
                                currentY += j;
                            } else if (spielfeld[currentY][currentX] == aktuellerSpieler && foundOpponent) {
                                /// Wenn gegnerische Steine gefunden und durch eigene Steine begrenzt sind, ist dies ein gültiger Zug
                                anzahlMoeglicheZuege++;
                                i = j = 2; /// Bricht die innere Schleife ab, keine weitere Überprüfung erforderlich
                                break;
                            } else {
                                break; /// Leeres Feld oder eigener Stein erreicht, keine weitere Überprüfung erforderlich
                            }
                        }
                    }
                }
            }
        }
    }

    return anzahlMoeglicheZuege; /// Gibt die Anzahl der möglichen Züge zurück
}

/**
 * @brief Fuehrt den Zug eines menschlichen Spielers aus
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return true, wenn ein gueltiger Zug ausgefuehrt wurde, sonst false
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            /// akzeptiere den Zug
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}

/**
 * @brief Fuehrt das Spiel durch
 *
 * @param spielerTyp Array mit den Typen der Spieler (1 fuer Mensch, 2 fuer Computer)
 */
void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    /// Setzt das Spielfeld in den Anfangszustand zurück.
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;  /// Der Spieler, der das Spiel beginnt.
    zeigeSpielfeld(spielfeld);  /// Zeigt das Spielfeld an.

    /// Das Spiel geht weiter, solange für beide Spieler Züge möglich sind.
    while (moeglicheZuege(spielfeld, 1) > 0 || moeglicheZuege(spielfeld, 2) > 0) {
        if (moeglicheZuege(spielfeld, aktuellerSpieler) > 0) {  /// Überprüft, ob der aktuelle Spieler einen Zug machen kann.
            if (spielerTyp[aktuellerSpieler - 1] == MENSCH) {
                menschlicherZug(spielfeld, aktuellerSpieler);  /// Menschlicher Zug, wenn der Spieler ein Mensch ist.
            } else {
                computerZug(spielfeld, aktuellerSpieler);  /// Computerzug, wenn der Spieler ein Computer ist.
            }
            zeigeSpielfeld(spielfeld);  /// Aktualisiert und zeigt das Spielfeld nach jedem Zug an.
        }
        aktuellerSpieler = 3 - aktuellerSpieler;  /// Wechselt zwischen den Spielern (1 zu 2 oder 2 zu 1).
    }

    /// Bestimmt den Gewinner, wenn das Spiel zu Ende ist, und zeigt das Ergebnis an.
    int gewinnerResult = gewinner(spielfeld);
    if (gewinnerResult == 0) {
        std::cout << "Das Spiel endet unentschieden!" << std::endl;
    } else {
        std::cout << "Spieler " << gewinnerResult << " gewinnt das Spiel!" << std::endl;
    }
}

/**
 * @brief Hauptprogramm
 *
 * Fuehrt Tests aus, wenn TEST auf 1 gesetzt ist. Startet das Spiel und fragt nach den Spielern.
 *
 * @return int Programmende-Status
 */
int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }

    char wiederholen = 'j';
    do {
        int spielerTyp[2];
        std::cout << "Spieler 1: Mensch (1) oder Computer (2)? ";
        std::cin >> spielerTyp[0];
        std::cout << "Spieler 2: Mensch (1) oder Computer (2)? ";
        std::cin >> spielerTyp[1];

        int spielfeld[GROESSE_Y][GROESSE_X];
        initialisiereSpielfeld(spielfeld);
        spielen(spielerTyp);

        std::cout << "Möchten Sie eine weitere Partie spielen? (j/n) ";
        std::cin >> wiederholen;
    } while (wiederholen == 'j' || wiederholen == 'J');

    return 0;
}
