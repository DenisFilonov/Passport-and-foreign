#include "ForeignPassport.h"

ForeignPassport::ForeignPassport()
{
    this->amountVisas = 0;
    arr = nullptr;
}

ForeignPassport::ForeignPassport(string surname, string name, string secondname, Date birth, string placeofbirth, string issuedby, string registrationplace)
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
    this->placeofbirth = placeofbirth;
}

ForeignPassport::~ForeignPassport()
{
    if (amountVisas > 0) delete[] arr;
}

Visas& ForeignPassport::operator[](int id)
{	
	return arr[id];
}

Visas ForeignPassport::operator[](string country)
{
	for (int i = 0; i < amountVisas; i++)
	{
		if (country == arr[i].getCountry())
		{
			return arr[i];
		}
	}
	return Visas("NoCountry", Date(2000, 1, 1), Date(2000, 1, 2));
}

int ForeignPassport::getAmountOfVisas() const
{
    return this->amountVisas;
}

void ForeignPassport::addVisa(Visas visa)
{
    if (amountVisas < 50)
    {
        Visas* tmp = new Visas[++amountVisas];
        for (int i = 0; i < amountVisas - 1; i++)
        {
            tmp[i] = arr[i];
        }
        tmp[amountVisas - 1] = visa;
        if (arr != NULL) delete[] arr;
        arr = tmp;
        cout << "\n���� ������� ���������!\n";
    }
    else
    {
        cout << "\n������. ���������� ����������, �.�. � �������� ��� ���������� �����!\n";
    }
}

void ForeignPassport::cancelVisa(int64_t id)
{
    int buf = findVisaByItsID(id);
    if (buf == -1)
    {
        cout << "\n���� �� �������, ��� ���� � ���� ��������. ��������� �������� ������.\n\n";
    }
    else
    {
        Visas* tmp = new Visas[--amountVisas];
        for (int i = 0; i < amountVisas; i++)
        {
            if (i < buf)
            {
                tmp[i] = arr[i];
            }
            else if (i >= buf)
            {
                tmp[i] = arr[i + 1];
            }
        }
        if (arr != NULL) delete[] arr;
        arr = tmp;
        cout << "\n���� ������� ������������!\n\n";
    }
}

int ForeignPassport::findVisaByItsID(int64_t id)
{
    for (int i = 0; i < amountVisas; i++)
    {
        if (id == arr[i].getIdOfVisa())
        {
            return i;
        }
    }
    return -1;
}

void ForeignPassport::showForeignPass() const
{
    cout << "\n����� ��������: " << serial;
    cout << "\n����� ��������: " << number;
    cout << "\n�������: " << surname;
    cout << "\n��'�: " << name;
    cout << "\n���� ����������: " << birth;
    cout << "\n����� ����������: " << placeofbirth;
    cout << "\n���� ������ ��������: " << issueofpass;
    cout << "\n��� ����� �������: " << issuedby;

    if (this->amountVisas == 0)
    {
        cout << "��������� ���: 0\n\n";
    }
    else
    {
        cout << "=================================================\n";
        cout << "\t��������� ���: " << this->amountVisas << endl << endl;
        for (int i = 0; i < amountVisas; i++)
        {
            cout << "\t���� �" << i + 1;
            arr[i].showVisa();
        }
        cout << "=================================================\n\n";
    }
}
