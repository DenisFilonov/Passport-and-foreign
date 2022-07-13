#pragma once
#include <iostream>
#include<ctime>

using namespace std;

class Date
{
	int year;
	int month;
	int day;

	bool isLeapYear() const; //Ïðîâåðêà íà âèñîêîñíûé ãîä
	int monthDays()const; //Êîëè÷åñòâî äíåé ïî ìåñÿöó
	void nextDate(); //Ñëåäóþùàÿ äàòà
	void prevDate(); //Ïðåäûäóùàÿ äàòà

public:
	//---------ÊÎÍÑÒÐÓÊÒÎÐÛ è ÄÅÑÒÐÓÊÒÎÐ---------
	Date(); // Ïî óìîë÷àíèþ  - òåêóùàÿ äàòà
	Date(int year, int month, int day); //Ñ ïàðàìåòðàìè - çàäàííàÿ äàòà
	Date(const Date& obj); //Êîïèðîâàíèÿ
	Date& operator = (const Date& obj);
	~Date();// Äåñòðóêòîð

	//---------ÀÊÑÅÑÑÎÐÛ---------
	void setYear(int year);
	int getYear()const;
	void setMonth(int month);
	int getMonth()const;
	void setDay(int day);
	int getDay()const;

	void showDate()const;
	bool isValidDate()const; //Ïðîâåðêà äàòû íà êîððåêòíîñòü

	//--------- ÎÏÅÐÀÒÎÐÛ ÑÐÀÂÍÅÍÈß ---------
	bool operator == (const Date& obj)const&;
	bool operator != (const Date& obj)const&;
	bool operator > (const Date& obj)const&;
	bool operator < (const Date& obj)const&;
	bool operator >= (const Date& obj)const&;
	bool operator <= (const Date& obj)const&;

	//--------- ÎÏÅÐÀÒÎÐÛ ÏÐÈÑÂÎÅÍÈß ---------	
	Date& operator += (int n);
	Date& operator -= (int n);

	//--------- ÀÐÈÔÌÅÒÈ×ÅÑÊÈÅ ÎÏÅÐÀÒÎÐÛ ---------
	Date operator + (int n)const&;
	Date operator - (int n)const&;
	Date operator -- ()const&;
	Date operator ++ ()const&;
	Date operator -- (int n)const&;
	Date operator ++ (int n)const&;

	friend ostream& operator << (ostream& os, const Date& d);
	friend istream& operator >> (istream& is, Date& d);
};

