/*! 
 * Praktikum Informatik 1 MMXXIV
 *
 * @ file Buecherei.cpp
 */

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 08: Vererbung und Polymorphie
//
// Datei:  Buecherei.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

/* Durch setzen dieser Variable k�nnen Sie entscheiden, welche Includes alle eingebunden werden sollen
 * Bei setzen auf true sind alle abgeleiteten Klassen (Buch, DVD, Magazin) vorhanden
 * Bei setzen auf false ist nur die Basisklasse Medium vorhanden
 */
 
#define UNTERKLASSENVORHANDEN true

#include <iostream>
#include <string>
#include <vector>
#include "Medium.h"
#include "Datum.h"

#if UNTERKLASSENVORHANDEN

    #include "Magazin.h"
    #include "Buch.h"
    #include "DVD.h"

#endif

void fuelleDatenbank(std::vector<Medium*>& medien);
void mediumHinzufuegen(std::vector<Medium*>& medien);
void mediumEntfernen(std::vector<Medium*>& medien);
void mediumAusleihen(std::vector<Medium*>& medien, Datum aktuellesDatum);
void mediumZurueckgeben(std::vector<Medium*>& medien);
void alleMedienAusgeben(std::vector<Medium*>& medien);
void alleAusgeliehenenAusgeben(std::vector<Medium*>& medien);

int main()
{
    std::vector<Medium*> medien;
    Datum aktuellesDatum;
    std::cout << "Aktuelles Datum: " << aktuellesDatum << std::endl;
    fuelleDatenbank(medien);

    char abfrage;
    do {
        std::cout << std::endl
                  << "Menue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Medium hinzufügen" << std::endl
                  << "(2): Medium löschen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Ein Medium verleihen" << std::endl
                  << "(5): Ein Medium zurücknehmen" << std::endl
                  << "(6): Alle ausgegebenen Medien ausgeben" << std::endl
                  << "(7): Beenden" << std::endl;

        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage) {
            case '1':
                mediumHinzufuegen(medien);
                break;
            case '2':
                mediumEntfernen(medien);
                break;
            case '3':
                alleMedienAusgeben(medien);
                break;
            case '4':
                mediumAusleihen(medien, aktuellesDatum);
                break;
            case '5':
                mediumZurueckgeben(medien);
                break;
            case '6':
                alleAusgeliehenenAusgeben(medien);
                break;
            case '7':
                std::cout << "Das Menü wird nun beendet." << std::endl;
                break;
            default:
                std::cout << "Falsche Eingabe, bitte nochmal versuchen.";
                break;
        }
    } while (abfrage != '7');

    for (auto it = medien.begin(); it != medien.end(); it++) {
        delete (*it);
    }

    return 0;
}

void fuelleDatenbank(std::vector<Medium*>& medien)
{
#if UNTERKLASSENVORHANDEN
    {
        Medium* neuesMedium = new Buch("Das Parfum", "Patrick Suskind");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Harry Potter und der Stein der Weisen", "J. K. Rowling");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Tom Sawyer", "Mark Twain");
        medien.push_back(neuesMedium);

        neuesMedium = new Magazin("Chip", Datum(1, 12, 2022), "Computer");
        medien.push_back(neuesMedium);

        neuesMedium = new DVD("Fluch der Karibik", 12, "Actionkomödie");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Huckleberry Finn", "Mark Twain");
        medien.push_back(neuesMedium);

        neuesMedium = new Magazin("BRANDNEU!", Datum(), "Ghostwriter");
        medien.push_back(neuesMedium);

    }
#else
    {
        Medium* neuesMedium = new Medium("Das Parfum");
        medien.push_back(neuesMedium);

        neuesMedium = new Medium("Harry Potter und der Stein der Weisen");
        medien.push_back(neuesMedium);

        neuesMedium = new Medium("Tom Sawyer");
        medien.push_back(neuesMedium);
    }
#endif
}

void mediumHinzufuegen(std::vector<Medium*>& medien)
{
    #if UNTERKLASSENVORHANDEN
    {
        std::cout << "Geben Sie die Art des Mediums ein: " << std::endl
                  << "(1): Buch" << std::endl
                  << "(2): Magazin" << std::endl
                  << "(3): DVD" << std::endl;

        char abfrage;
        std::cin >> abfrage;
        std::cin.ignore(10,'\n');

        switch (abfrage)
        {
            case '1':
            {
                std::string titel;
                std::cout << "Bitte geben Sie den Titel des Buchs ein: " << std::endl;
                std::getline(std::cin, titel);

                std::string autor;
                std::cout << "Bitte geben sie den Autor des Buchs ein: " << std::endl;
                std::getline(std::cin, autor);

                Medium* neuesMedium = new Buch(titel,autor);
                medien.push_back(neuesMedium);
            }
            break;
            case '2':
            {
                std::string titel;
                std::cout << "Geben Sie den Titel des Magazins ein:" << std::endl;
                getline(std::cin, titel);

                std::string sparte;
                std::cout << "Geben Sie die Sparte an:" << std::endl;
                getline(std::cin, sparte);

                Datum datumAusgabe;
                std::cout << "Geben Sie das Erscheinungsdatum der Ausgabe an:" << std::endl;
                std::cin >> datumAusgabe;
                std::cin.ignore(10, '\n');

                Medium* neuesMedium = new Magazin(titel, datumAusgabe, sparte);
                medien.push_back(neuesMedium);
            }
            break;
            case '3':
            {
                std::string titel;
                std::cout << "Bitte geben Sie den Titel der DVD ein:" << std::endl;
                getline(std::cin, titel);

                std::string genre;
                std::cout << "Geben Sie das Genre an:" << std::endl;
                getline(std::cin, genre);

                int altersfreigabe;
                std::cout << "Geben Sie die Altersfreigabe ein:" << std::endl;
                std::cin >> altersfreigabe;
                std::cin.ignore(10, '\n');

                Medium* neuesMedium = new DVD(titel, altersfreigabe, genre);
                medien.push_back(neuesMedium);
            }
            break;
            default:
                std::cout << "Ungültige Eingabe!" << std::endl;
                break;
        }
    }
    #else
    {
        std::string titel;
        std::cout << "Bitte geben sie den Titel des Mediums ein:\n";
        getline(std::cin, titel);

        Medium* neuesMedium = new Medium(titel);
        medien.push_back(neuesMedium);
    }
    #endif
}

void mediumEntfernen(std::vector<Medium*>& medien)
{
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein, welches gelöscht werden soll: " ;
    std::cin >> id;
    std::cin.ignore(10, '\n');

    bool success = false;
    for(auto it = medien.begin(); it != medien.end(); it++)
    {
        if((*it)->getID() == id)
        {
            delete (*it);
            medien.erase(it);
            success = true;
            break;
        }
    }
    if(!success)
    {
        std::cout << "Keine gültige ID!" << std::endl;
    }
}

void mediumAusleihen(std::vector<Medium*>& medien, Datum aktuellesDatum)
{
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein:" << std::endl;
    std::cin >> id;
    std::cin.ignore(10, '\n');

    std::string name;
    std::cout << "Geben Sie den Namen der Person ein: ";
    getline(std::cin, name);

    Datum geburtsdatum;
    std::cout << "Geben Sie das Geburtsdatum der Person ein: (Format TT.MM.JJJJ) ";
    std::cin >> geburtsdatum;
    std::cin.ignore(10, '\n');

    Person person(name,geburtsdatum);

    bool id_vorhanden = false;
    for(auto it = medien.begin(); it != medien.end(); it++)
    {
        if((*it)->getID() == id)
        {
            (*it)->ausleihen(person,aktuellesDatum);
            id_vorhanden = true;
        }
    }
    if (!id_vorhanden)
    {
        std::cout << "Keine gültige ID!" << std::endl;
    }
}

void mediumZurueckgeben(std::vector<Medium*>& medien)
{
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein: ";
    std::cin >> id;
    std::cin.ignore(10,'\n');

    bool id_vorhanden = false;
    for(auto it = medien.begin(); it != medien.end(); it++)
    {
        if((*it)->getID() == id)
        {
            (*it)->zurueckgeben();
            id_vorhanden = true;
        }
    }
    if (!id_vorhanden)
    {
        std::cout << "Keine gültige ID!" << std::endl;
    }
}

void alleMedienAusgeben(std::vector<Medium*>& medien)
{
    std::cout << "Vorhandene Medien in der Bücherei:" << std::endl;

    for (unsigned int index = 0; index < medien.size(); index++)
    {
        std::cout << "*************************************************************" << std::endl;
        medien[index]->ausgabe();
    }
}

void alleAusgeliehenenAusgeben(std::vector<Medium*>& medien)
{
    std::cout << "Ausgeliehene Medien in der Bücherei:" << std::endl;

    bool einsAusgeliehen = false;
    for (unsigned int index = 0; index < medien.size(); index++)
    {
        if (medien[index]->getStatus()) {
            std::cout << "*************************************************************" << std::endl;
            std::cout << *(medien[index]) << std::endl;
            einsAusgeliehen = true;
        }
    }
    if (!einsAusgeliehen) {
        std::cout << "*************************************************************" << std::endl;
        std::cout << "Kein Medium ist momentan ausgeliehen!" << std::endl;
        std::cout << "*************************************************************" << std::endl;
    }
}
