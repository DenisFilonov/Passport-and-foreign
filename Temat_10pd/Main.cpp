#include<Windows.h>
#include"ForeignPassport.h"


int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Passport T("Лапшун", "Тетяна", "Степановна", Date(1990, 8, 1), "м.Харкiв", "МВС", "Харкiвська");
	T.setName("Не Тетяна");
	T.showInfo();

	//int64_t check;
	//string scheck;

	//ForeignPassport TT("Лапшун", "Тетяна", Date(1990, 8, 1), "м.Харкiв", "МВС", "Харкiвська");
	/*ForeignPassport TT;
	TT.addVisa(Visas("Canada", Date(2022, 8, 10), Date(2022, 9, 10)));
	TT.showForeignPass();*/

	return 0;
}