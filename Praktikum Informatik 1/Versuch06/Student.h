#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe() const; // inline tanım kaldırıldı
    void print(ostream& outStream) const; // İsim değiştirildi

    bool operator==(const Student& otherStudent) const;
    bool operator>(const Student& otherStudent) const;
    bool operator<(const Student& otherStudent) const;
    bool operator>=(const Student& otherStudent) const;
    bool operator<=(const Student& otherStudent) const;
private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

ostream& operator<<(ostream& outStream, const Student& student);

#endif
