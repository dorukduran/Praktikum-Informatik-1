//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

using namespace std;

/**
 * @brief Hauptfunktion zum Testen der Vektorklasse
 * @return 0 bei erfolgreicher Ausführung
 */
int main()
{
    Vektor vector1(0, 5, 0);
    Vektor vector2(5, 5, 0);

    vector1.ausgabe();
    vector2.ausgabe();
    vector1.skalarProd(vector2);
    cout << "Winkel zwischen test: " << vector1.winkel(vector2) << endl;

    Vektor neu = vector2.sub(vector1);

    cout << "Winkel zwischen test2: " << vector1.winkel(neu) << endl;

    neu.ausgabe();

    double PLATFORM = 555.7;
    double GROESSE = 1.7;
    double ERDRADIUS = 6371000;

    double ROTIEREN_PRO_SCHRITT = 0.000001;

    Vektor erdradius(0, ERDRADIUS, 0);
    Vektor mensch(0, ERDRADIUS + PLATFORM + GROESSE, 0);

    int steps = 0;
    double rotierterWinkel = 0.0;

    steps = 0;
    rotierterWinkel = 0.0;

    int tempSteps = 0;

    cout << fixed;
    cout << setprecision(4);
    while (steps < 1000000000)
    {
        erdradius.rotiereUmZ(-ROTIEREN_PRO_SCHRITT);
        rotierterWinkel += ROTIEREN_PRO_SCHRITT;
        tempSteps++;
        steps++;

        Vektor sicht = erdradius.sub(mensch);

        /// Winkel zwischen Sicht und Erdradius (Zeichnung rechts in der Aufgabe)
        double angleGrad = erdradius.winkel(sicht);

        if (fabs(angleGrad - 90.0) < 0.0000001)
        {
            cout << "FERTIG" << endl;
            cout << "Sie können " << sicht.laenge() / 1000 << " Km weit sehen." << endl;
            cout << "Sie sind " << PLATFORM + GROESSE << " Meter hoch." << endl;
            cout << "Der Winkel beträgt: " << rotierterWinkel * 180 / M_PI << endl;
            cout << "Anzahl Schritte: " << steps << endl;
            break;
        }
        else if (angleGrad < 90 && ROTIEREN_PRO_SCHRITT > 0)
        {
            cout << "Zu weit vorwärts gedreht. Ändere Schrittweite von " << ROTIEREN_PRO_SCHRITT << " zu " << ROTIEREN_PRO_SCHRITT * -0.1 << endl;
            cout << "Winkel: " << angleGrad << "\t Schritte in diesem Durchlauf: " << tempSteps << endl;
            tempSteps = 0;
            ROTIEREN_PRO_SCHRITT = ROTIEREN_PRO_SCHRITT * -0.1;
        }
        else if (angleGrad > 90 && ROTIEREN_PRO_SCHRITT < 0)
        {
            cout << "Zu weit rückwärts gedreht. Ändere Schrittweite von " << ROTIEREN_PRO_SCHRITT << " zu " << ROTIEREN_PRO_SCHRITT * -0.1 << endl;
            cout << "Winkel: " << angleGrad << "\t Schritte in diesem Durchlauf: " << tempSteps << endl;
            tempSteps = 0;
            ROTIEREN_PRO_SCHRITT = ROTIEREN_PRO_SCHRITT * -0.1;
        }
    }

    return 0;
}
