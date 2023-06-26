#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class testing
{
	int* arr_result;									//������ ����������� ������������ ��������� �� ���������� ���������
	string * arr_discipline;							//������ �������� ������� ���������
	int Size;											//���������� ������� ���������
	char name[20];										//��� ���������

public:
	void Set_name();									//������ ��� ������� ����� ���������

	void Set_Size();									//������ ��� ������� ����������� ������� ���������

	void Set_discipline_name();							//������ ��� ��������� � ������ �������� ������� ���������

	void Set_Score();									//������ ��� ��������� � ������ ����������� ������������ ���������� ������ score, ��������� �� ���� ���������

	int Average_Score();								//���������� �������� �����, ���������� ���������  �� ���� ���������

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

	char* Get_name();									//������ ��� �������� ����� ���������

	void Get_discipline_name();							//������ ��� �������� �������� ������� ����������

	void Del_discipline_name();							//������� ������������ ������, ���������� ��� ������ �������� ������� ���������

	string Get_discipline(int index);					//����� �������� ������� ���������� �� ������� � ������� ������� ���������	

	int Get_size();										//������ ��� �������� ����������� ������� ���������

	void Get_Score();									//������ ��� �������� ���������� ������ score ��������� �� ���� ��������� 

	void Del_Score();									//������� ������������ ������, ���������� ��� ������ ����������� ������������ �� ���� ���������
	
	int Get_Score_discipline(char * Discipline);		//������ ��� �������� ���������� ������ score, ��������� �� ���������� �������� 

	void Save_File();									//����� ���������� ������ � ����

	void operator += (const testing & other);			//���������� ��������� += 
};
