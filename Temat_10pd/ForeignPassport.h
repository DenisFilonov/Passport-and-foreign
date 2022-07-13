#pragma once
#include "Passport.h"
#include "Visas.h"

class ForeignPassport :
    private Passport
{
protected:
    Visas* arr;
    int amountVisas;

public:
    ForeignPassport();
    ForeignPassport(string surname, string name, string secondname, Date birth, string placeofbirth, string issuedby, string registrationplace);
    ~ForeignPassport();
    Visas& operator[](int id);
    Visas operator[](string country);

    int getAmountOfVisas()const;

    void addVisa(Visas visa);
    void cancelVisa(int64_t id);
    int findVisaByItsID(int64_t id);
    void showForeignPass()const;
};

