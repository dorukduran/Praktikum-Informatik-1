/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Liste.h"
#include "Student.h"

/**
 * @brief Hauptfunktion des Programms.
 *
 * Diese Funktion führt das Hauptmenü für die Verwaltung einer Studentenliste aus.
 * Benutzer können Studenten hinzufügen, entfernen und die Liste anzeigen.
 *
 * @return int Rückgabewert des Programms.
 */
int main()
{
    std::vector<Student> studentenListe;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        std::ifstream eingabe("studenten.txt");
        if (!eingabe)
        {
            std::cout << "Fehler beim Oeffnen der Datei!";
            return 1;
        }

        unsigned int matNr;
        std::string name;
        std::string geburtsdatum;
        std::string adresse;

        while (eingabe >> matNr)
        {
            eingabe.ignore(1, '\n');
            std::getline(eingabe, name);
            std::getline(eingabe, geburtsdatum);
            std::getline(eingabe, adresse);
            student = Student(matNr, name, geburtsdatum, adresse);
            studentenListe.push_back(student);
        }
        eingabe.close();
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
                  << "(5): Datenelement loeschen" << std::endl
                  << "(6): Datenelement vorne hinzufuegen" << std::endl
                  << "(7): Daten aus einer Datei einlesen" << std::endl
                  << "(8): Daten in eine Datei sichern" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            /// Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name); /// ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            /// Datenelement vorne entfernen
            case '2':
                {
                    if (!studentenListe.empty())
                    {
                        student = studentenListe.front();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            /// Datenbank vorwaerts ausgeben
            case '3':
                if (!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for (const auto& s : studentenListe)
                    {
                        s.ausgabe();
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

            /// Datenbank rueckwaerts ausgeben
            case '4':
                if (!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
                    for (auto it = studentenListe.rbegin(); it != studentenListe.rend(); ++it)
                    {
                        it->ausgabe();
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

            /// Datenelement loeschen
            case '5':
                {
                    int matrikelnummer;
                    std::cout << "Matrikelnummer eingeben: ";
                    std::cin >> matrikelnummer;
                    std::cin.ignore(10, '\n');

                    bool gefunden = false;
                    for (auto it = studentenListe.begin(); it != studentenListe.end(); ++it)
                    {
                        if (it->getMatNr() == matrikelnummer)
                        {
                            studentenListe.erase(it);
                            std::cout << "Student geloescht.\n";
                            gefunden = true;
                            break;
                        }
                    }
                    if (!gefunden)
                    {
                        std::cout << "Student nicht gefunden.\n";
                    }
                }
                break;

            /// Datenelement vorne hinzufuegen
            case '6':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name); /// ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.insert(studentenListe.begin(), student);
                }
                break;

            /// Daten aus einer Datei einlesen
            case '7':
                {
                    std::string dateiName;
                    std::cout << "Dateiname eingeben: ";
                    std::getline(std::cin, dateiName);

                    std::ifstream eingabe(dateiName);
                    if (!eingabe)
                    {
                        std::cout << "Fehler beim Oeffnen der Datei!";
                        break;
                    }

                    studentenListe.clear();

                    unsigned int matNr;
                    std::string name;
                    std::string geburtsdatum;
                    std::string adresse;

                    while (eingabe >> matNr)
                    {
                        eingabe.ignore(1, '\n');
                        std::getline(eingabe, name);
                        std::getline(eingabe, geburtsdatum);
                        std::getline(eingabe, adresse);
                        student = Student(matNr, name, geburtsdatum, adresse);
                        studentenListe.push_back(student);
                    }
                    eingabe.close();
                }
                break;

            /// Daten in eine Datei sichern
            case '8':
                {
                    std::string dateiName;
                    std::cout << "Dateiname eingeben: ";
                    std::getline(std::cin, dateiName);

                    std::ofstream ausgabe(dateiName);
                    if (!ausgabe)
                    {
                        std::cout << "Fehler beim Oeffnen der Datei!";
                        break;
                    }

                    for (const auto& s : studentenListe)
                    {
                        ausgabe << s.getMatNr() << '\n'
                                << s.getName() << '\n'
                                << s.getGeburtstag() << '\n'
                                << s.getAdresse() << '\n';
                    }
                    ausgabe.close();
                }
                break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default:
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    } while (abfrage != '0');

    return 0;
}