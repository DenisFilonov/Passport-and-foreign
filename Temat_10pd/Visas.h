#pragma once
#include"Passport.h"
#include"Date.h"

class Visas
{
	string country; //Название страны
	Date opened; //Дата открытия визы
	Date closed; //Дата закрытия визы
	int64_t id; //ИД визы = плюшка, я получал визы :)

public:
	Visas();
	Visas(string country, Date opened, Date closed);
	~Visas();

	void setCountry(string country);
	void setDateOfOpen(Date opened);
	void setDateOfClose(Date closed);


	string getCountry()const;
	Date getDateOfOpen()const;
	Date getDateOfClose()const;
	int64_t getIdOfVisa()const;

	void showVisa()const;
};

