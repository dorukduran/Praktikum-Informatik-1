//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr);

    if (front == nullptr) /// Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
       back->setNext(neuesElement);
       neuesElement->setPrev(back);
       back = neuesElement;

    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, front);

    if (front == nullptr) /// Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        front->setPrev(neuesElement);
        front = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back) /// Liste enthält nur ein Listenelement
    {
        delete front; /// Listenelement löschen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        cursor->getNext()->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element in umgekehrter Reihenfolge.
 *
 * @return void
 */
void Liste::ausgabeUmkehren() const
{
    ListenElement* cursor = back;
    while (cursor != nullptr)
    {
      cursor->getData().ausgabe();
      cursor = cursor->getPrev();
    }
}

/**
 * @brief Loeschen eines Listenelements anhand der Matrikelnummer.
 *
 * @param matrikelnummer Die Matrikelnummer des zu loeschenden Listenelements.
 * @return void
 */
void Liste::deleteByMatrikelnummer(int matrikelnummer)
{
    if (front == nullptr) /// Liste leer?
    {
        std::cout << "Liste ist leer." << std::endl;
        return;
    }

    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
        if (cursor->getMatrikelnummer() == matrikelnummer) /// Student mit gegebener Matrikelnummer gefunden
        {
            Student foundStudent = cursor->getData();

            if (cursor == front && cursor == back) /// Liste enthält nur ein Listenelement
            {
                front = nullptr;
                back = nullptr;
            }
            else if (cursor == front) /// Erstes Element wird gelöscht
            {
                front = cursor->getNext();
                if (front != nullptr) front->setPrev(nullptr);
            }
            else if (cursor == back) /// Letztes Element wird gelöscht
            {
                back = cursor->getPrev();
                if (back != nullptr) back->setNext(nullptr);
            }
            else /// Mittleres Element wird gelöscht
            {
                cursor->getPrev()->setNext(cursor->getNext());
                cursor->getNext()->setPrev(cursor->getPrev());
            }

            delete cursor;
            std::cout << "Student entfernt: ";
            foundStudent.ausgabe();
            return;
        }
        cursor = cursor->getNext();
    }

    std::cout << "Student mit Matrikelnummer " << matrikelnummer << " nicht gefunden." << std::endl;
}
