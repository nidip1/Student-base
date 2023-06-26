#include "testing.h"

void testing::Set_name()									//������ ��� ������� ����� ���������
{
	char name[20];
	cout << "������� ��� ���������\n";
	cin >> name;
	strcpy_s(this->name, name);
}

void testing::Set_Size()									//������ ��� ������� ����������� ������� ���������
{
	cout << "������� ���������� ������� ���������\n";
	cin >> Size;
}

void testing::Set_discipline_name()							//������ ��� ��������� � ������ �������� ������� ���������
{
	string discipline_name;
	arr_discipline = new string[Size];						//��������� ������������ ������ ��� ������� �������� ������� ���������
	for (int i = 0; i < Size; i++)
	{
		cout << "������� �������� ������� ����������\n";
		cin >> discipline_name;
		arr_discipline[i]= discipline_name;
	}
}

void testing::Set_Score()									//������ ��� ��������� � ������ ����������� ������������ ���������� ������ score, ��������� �� ���� ���������
{
	int score;
	arr_result = new int[Size];								//��������� ������������ ������ ��� ������� � ���������� ������� score �� ���� ���������
	for (int i = 0; i < Size; i++)
	{		
		cout << "������ ���������� ������ ���������� " << name << " �� " << i + 1 << "-�� ��������\n";
		cin >> score;
		arr_result[i] = score;
	}
}

int testing::Average_Score()								//���������� �������� �����, ���������� ���������  �� ���� ���������
{
	int summ = 0;
	for (int i = 0; i < Size; i++)
	{
		summ += arr_result[i];
	}
	return (summ/Size);
}

char* testing::Get_name()									//������ ��� �������� ����� ���������
{
	return name;
}

void testing::Get_discipline_name()							//������ ��� �������� �������� ������� ����������
{
	for (int i = 0; i < Size; i++)
	{
		cout << setw(11)<<left <<arr_discipline[i]<<' ';
	}	
	cout << endl;
}

void testing::Del_discipline_name()							//������� ������������ ������, ���������� ��� ������ �������� ������� ���������
{
	delete[] arr_discipline;
}

string testing::Get_discipline(int index)					//����� �������� ������� ���������� �� ������� � ������� ������� ���������
{
	return arr_discipline[index];
}

int testing::Get_size()										//������ ��� �������� ����������� ������� ���������
{
	return Size;
}

void testing::Get_Score()									//������ ��� �������� ���������� ������ score ��������� �� ���� ��������� 
{
	for (int i = 0; i < Size; i++)
	{
		cout << setw(11)<<left<< arr_result[i]<<' ';
	}
	cout << endl;
}

void testing::Del_Score()									//������� ������������ ������, ���������� ��� ������ ����������� ������������ �� ���� ���������
{
	delete[] arr_result;
}

int testing::Get_Score_discipline(char * Discipline)		//������ ��� �������� ���������� ������ score, ��������� �� ���������� �������� 
{
	int score=0;
	for (int i = 0; i < Size; i++)
	{
		if (Discipline == arr_discipline[i])
		{
			score = arr_result[i];
		}
	}
	return score;
}

void testing::Save_File()									//����� ���������� ������ � ���� 
{
	ofstream f;												//��������� ������ ������ ofstream
	string namefile= "D:\\Students.txt";					//��������� ���������� ������ string
	f.open(namefile, ofstream::app);						//�������� ����� open() ������� f ������ ofstream 
	if (!f.is_open())										//�������� �� �������� ����� � ������� ������  is_open() 
		cout << "������ �������� �����";
	else
	{
		f << "\n\t\t\t\t���������� ������������ " << name << endl << endl<<"������� ����������\t\t";
		for (int i = 0; i < Size; i++)
		{
			f << setw(11) << left << arr_discipline[i] << ' ';
		}
		f << endl << "���������� ��������� ������\t";
		for (int i = 0; i < Size; i++)
		{
			f << setw(11) << left << arr_result[i] << ' ';
		}
		f << endl;		
	}
	f.close();												//�������� ����� close() ������� f ������ ofstream 
}

void testing::operator += (const testing & other)			//���������� ��������� +=
{
	strcpy_s(this->name, other.name);
	this->Size = other.Size;
	this->arr_discipline = new  string[Size];
	for (int i = 0; i < Size; i++)
	{
		this->arr_discipline[i] = other.arr_discipline[i];
	}

	this->arr_result = new  int[Size];
	for (int i = 0; i < Size; i++)
	{
		this->arr_result[i] = other.arr_result[i];
	}
	//return *this;
	// TODO: �������� ����� �������� return
}

