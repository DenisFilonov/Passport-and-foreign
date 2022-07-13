#pragma once
#include"Passport.h"
#include"Date.h"

class Visas
{
	string country; //�������� ������
	Date opened; //���� �������� ����
	Date closed; //���� �������� ����
	int64_t id; //�� ���� = ������, � ������� ���� :)

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

