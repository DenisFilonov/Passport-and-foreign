#include "Passport.h"

Passport::Passport()
{
    int64_t i = 10000, j = 99999;
    char a, b; // 65 - A, 90 - Z
    a = rand() % 24 + 65;
    b = rand() % ('Z' - 'A' + 1) + 'A';

    //this->serial= a + b; - это переменные символы, а не строки, и сложение двух чаров даёт третий какой-то
    this->serial.insert(0, 1, a);
    this->serial.insert(1, 1, b);
    this->number = rand() % (i - j + 1) + j;
    this->issueofpass = Date();

    //================================================== Выше элементы по умолчанию
    this->surname = "-Шевченко-";
    this->name = "-ИМ'Я-";
    this->birth = Date();
    this->placeofbirth = "-Харькiв-";
    this->issuedby = "МВС Укр";
    this->secondname = "-Батьковi-";
    this->registrationplace = "вул. Сумська 63";
}

Passport::Passport(string surname, string name, string secondname, Date birth, string placeofbirth, string issuedby, string registrationplace)
{
    int64_t i = 10000, j = 99999;
    char a, b;
    a = rand() % 24 + 65;
    b = rand() % ('Z' - 'A' + 1) + 'A';

    this->serial.insert(0, 1, a);
    this->serial.insert(1, 1, b);

    this->number = rand() % (i - j + 1) + j;
    this->issueofpass = Date();

    //================================================== Выше элементы по умолчанию
    this->surname = surname;
    this->name = name;
    this->birth = birth;
    this->secondname = secondname;
    this->placeofbirth = placeofbirth;
    this->issuedby = issuedby;
    this->registrationplace = registrationplace;
}

Passport::~Passport()
{
    //void
}

void Passport::setSurname(string surname)
{
    this->surname = surname;
}

void Passport::setName(string name)const
{
    string* tmp;
    tmp = const_cast<string*>(&this->name);
    *tmp = name;
}

void Passport::setBirth(Date birth)
{
    this->birth = birth;
}

void Passport::setPlaceOfBirth(string placeofbirth)
{
    this->placeofbirth = placeofbirth;
}

void Passport::setIssuedBy(string issuedby)
{
    this->issuedby = issuedby;
}

void Passport::setSecondName(string secondname)
{
    this->secondname = secondname;
}

void Passport::setRegistrationPlace(string registrationplace)
{
    this->registrationplace = registrationplace;
}

string Passport::getSerial() const
{
    return this->serial;
}

int64_t Passport::getNumber() const
{
    return number;
}

string Passport::getSurname() const
{
    return this->surname;
}

string Passport::getName() const
{
    return this->name;
}

Date Passport::getBirth() const
{
    return this->birth;
}

string Passport::getPlaceOfBirth() const
{
    return this->placeofbirth;
}

Date Passport::getIssueOfPass() const
{
    return this->issueofpass;
}

string Passport::getIssuedBy() const
{
    return this->issuedby;
}

void Passport::showInfo() const
{
    //Я ехрово знаю украиский, поэтому извиняюсь за ошибки
    cout << "\t====== Паспорт громадянина Украины =======";
    cout << "\nСерия паспорту: " << this->serial;
    cout << "\nНомер паспорту: " << this->number;
    cout << "\nФамилия: " << this->surname;
    cout << "\nИм'я: " << this->name;
    cout << "\nПо батькови: " << this->secondname;
    cout << "\nДень нарождення: " << this->birth;
    cout << "\nМисце нарождення: " << this->placeofbirth;
    cout << "\nДата видачи паспорту: " << this->issueofpass;
    cout << "\nКим выдан паспорт: " << this->issuedby;
    cout << "\nПрописка: " << this->registrationplace;
    cout << "\n=================================================\n";

}
