#pragma once
#include <iostream>
#include<ctime>

using namespace std;

class Date
{
	int year;
	int month;
	int day;

	bool isLeapYear() const; //�������� �� ���������� ���
	int monthDays()const; //���������� ���� �� ������
	void nextDate(); //��������� ����
	void prevDate(); //���������� ����

public:
	//---------������������ � ����������---------
	Date(); // �� ���������  - ������� ����
	Date(int year, int month, int day); //� ����������� - �������� ����
	Date(const Date& obj); //�����������
	Date& operator = (const Date& obj);
	~Date();// ����������

	//---------���������---------
	void setYear(int year);
	int getYear()const;
	void setMonth(int month);
	int getMonth()const;
	void setDay(int day);
	int getDay()const;

	void showDate()const;
	bool isValidDate()const; //�������� ���� �� ������������

	//--------- ��������� ��������� ---------
	bool operator == (const Date& obj)const&;
	bool operator != (const Date& obj)const&;
	bool operator > (const Date& obj)const&;
	bool operator < (const Date& obj)const&;
	bool operator >= (const Date& obj)const&;
	bool operator <= (const Date& obj)const&;

	//--------- ��������� ���������� ---------	
	Date& operator += (int n);
	Date& operator -= (int n);

	//--------- �������������� ��������� ---------
	Date operator + (int n)const&;
	Date operator - (int n)const&;
	Date operator -- ()const&;
	Date operator ++ ()const&;
	Date operator -- (int n)const&;
	Date operator ++ (int n)const&;

	friend ostream& operator << (ostream& os, const Date& d);
	friend istream& operator >> (istream& is, Date& d);
};

