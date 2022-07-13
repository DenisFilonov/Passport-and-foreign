#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include"Date.h"

using namespace std;

class Passport
{
protected:
	string serial; //����� ��������
	int64_t number; //����� ��������
	string surname; //�������
	string name; //���

	Date birth; //���� ��������
	string placeofbirth; //����� ��������
	Date issueofpass; //���� ������ ��������
	string issuedby; //��� �����

private:
	string secondname; //��������
	string registrationplace; //��������

public:
	Passport();
	Passport(string surname, string name, string secondname, Date birth, string placeofbirth, string issuedby, string registrationplace);
	~Passport();

	//void setSerial(string serial);
	//void setNumber(int64_t number);
	void setSurname(string surname);
	void setName(string name)const;

	void setBirth(Date birth);
	void setPlaceOfBirth(string placeofbirth);
	//void setIssueOfPass(Date());
	void setIssuedBy(string issuedby);

	void setSecondName(string secondname); //private
	void setRegistrationPlace(string registrationplace); //private


	string getSerial()const;
	int64_t getNumber()const;
	string getSurname()const;
	string getName()const;

	Date getBirth()const;
	string getPlaceOfBirth()const;
	Date getIssueOfPass()const;
	string getIssuedBy()const;

	void showInfo()const;
};

