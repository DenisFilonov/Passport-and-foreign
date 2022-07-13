#include "Passport.h"

Passport::Passport()
{
    int64_t i = 10000, j = 99999;
    char a, b; // 65 - A, 90 - Z
    a = rand() % 24 + 65;
    b = rand() % ('Z' - 'A' + 1) + 'A';

    //this->serial= a + b; - ��� ���������� �������, � �� ������, � �������� ���� ����� ��� ������ �����-��
    this->serial.insert(0, 1, a);
    this->serial.insert(1, 1, b);
    this->number = rand() % (i - j + 1) + j;
    this->issueofpass = Date();

    //================================================== ���� �������� �� ���������
    this->surname = "-��������-";
    this->name = "-��'�-";
    this->birth = Date();
    this->placeofbirth = "-�����i�-";
    this->issuedby = "��� ���";
    this->secondname = "-�������i-";
    this->registrationplace = "���. ������� 63";
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

    //================================================== ���� �������� �� ���������
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
    //� ������ ���� ���������, ������� ��������� �� ������
    cout << "\t====== ������� ����������� ������� =======";
    cout << "\n����� ��������: " << this->serial;
    cout << "\n����� ��������: " << this->number;
    cout << "\n�������: " << this->surname;
    cout << "\n��'�: " << this->name;
    cout << "\n�� ��������: " << this->secondname;
    cout << "\n���� ����������: " << this->birth;
    cout << "\n����� ����������: " << this->placeofbirth;
    cout << "\n���� ������ ��������: " << this->issueofpass;
    cout << "\n��� ����� �������: " << this->issuedby;
    cout << "\n��������: " << this->registrationplace;
    cout << "\n=================================================\n";

}
