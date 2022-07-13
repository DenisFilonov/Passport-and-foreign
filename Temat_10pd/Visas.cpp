#include "Visas.h"

Visas::Visas()
{
    this->country = "Germany";
    this->opened = Date();
    this->closed = Date() + 1;

    int64_t i = 1000, j = 9999;
    id = rand() % (i - j + 1) + j;
}

Visas::Visas(string country, Date opened, Date closed)
{
    this->country = country;
    this->opened = opened;
    this->closed = closed;

    int64_t i = 1000, j = 9999;
    id = rand() % (i - j + 1) + j;
}

Visas::~Visas()
{
}

void Visas::setCountry(string country)
{
    this->country = country;
}

void Visas::setDateOfOpen(Date opened)
{
    this->opened = opened;
}

void Visas::setDateOfClose(Date closed)
{
    this->closed = closed;
}

string Visas::getCountry() const
{
    return this->country;
}

Date Visas::getDateOfOpen() const
{
    return this->opened;
}

Date Visas::getDateOfClose() const
{
    return this->closed;
}

int64_t Visas::getIdOfVisa() const
{
    return this->id;
}

void Visas::showVisa() const
{
    cout << "\nКраина: " << this->country;
    cout << "\nДата видкрыття: " << this->opened;
    cout << "\nДата окончення: " << this->closed;
    cout << "\nСерийный номер: " << this->id << endl;
}
