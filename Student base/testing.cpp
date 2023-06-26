#include "testing.h"

void testing::Set_name()									//сеттер для задания имени учащегося
{
	char name[20];
	cout << "Введите имя учащегося\n";
	cin >> name;
	strcpy_s(this->name, name);
}

void testing::Set_Size()									//сеттер для задания колличества учебных дисциплин
{
	cout << "Введите количество учебных предметов\n";
	cin >> Size;
}

void testing::Set_discipline_name()							//сеттер для занесения в массив названий учебных дисциплин
{
	string discipline_name;
	arr_discipline = new string[Size];						//выделение динамической памяти для массива названий учебных дисциплин
	for (int i = 0; i < Size; i++)
	{
		cout << "Введите название учебной дисциплины\n";
		cin >> discipline_name;
		arr_discipline[i]= discipline_name;
	}
}

void testing::Set_Score()									//сеттер для занесения в массив результатов тестирования количества баллов score, набранных по всем предметам
{
	int score;
	arr_result = new int[Size];								//выделение динамической памяти для массива с набранными баллами score по всем предметам
	for (int i = 0; i < Size; i++)
	{		
		cout << "Ведите количество баллов полученных " << name << " по " << i + 1 << "-му предмету\n";
		cin >> score;
		arr_result[i] = score;
	}
}

int testing::Average_Score()								//вычисление среднего балла, набранного студентом  по всем предметам
{
	int summ = 0;
	for (int i = 0; i < Size; i++)
	{
		summ += arr_result[i];
	}
	return (summ/Size);
}

char* testing::Get_name()									//геттер для возврата имени учащегося
{
	return name;
}

void testing::Get_discipline_name()							//геттер для возврата названия учебной дисциплины
{
	for (int i = 0; i < Size; i++)
	{
		cout << setw(11)<<left <<arr_discipline[i]<<' ';
	}	
	cout << endl;
}

void testing::Del_discipline_name()							//очистка динамической памяти, выделенной под массив названий учебных дисциплин
{
	delete[] arr_discipline;
}

string testing::Get_discipline(int index)					//выбор названия учебной дисциплины по индексу в массиве учебных дисциплин
{
	return arr_discipline[index];
}

int testing::Get_size()										//геттер для возврата колличества учебных дисциплин
{
	return Size;
}

void testing::Get_Score()									//геттер для возврата количества баллов score набранных по всем предметам 
{
	for (int i = 0; i < Size; i++)
	{
		cout << setw(11)<<left<< arr_result[i]<<' ';
	}
	cout << endl;
}

void testing::Del_Score()									//очистка динамической памяти, выделенной под массив результатов тестирования по всем предметам
{
	delete[] arr_result;
}

int testing::Get_Score_discipline(char * Discipline)		//геттер для возврата количества баллов score, набранных по выбранному предмету 
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

void testing::Save_File()									//метод сохранения данных в файл 
{
	ofstream f;												//объявляем объект класса ofstream
	string namefile= "D:\\Students.txt";					//объявляем переменную класса string
	f.open(namefile, ofstream::app);						//вызываем метод open() объекта f класса ofstream 
	if (!f.is_open())										//проверка на открытие файла с помощью метода  is_open() 
		cout << "Ошибка открытия файла";
	else
	{
		f << "\n\t\t\t\tРезультаты тестирования " << name << endl << endl<<"Учебная дисциплина\t\t";
		for (int i = 0; i < Size; i++)
		{
			f << setw(11) << left << arr_discipline[i] << ' ';
		}
		f << endl << "Количество набранных баллов\t";
		for (int i = 0; i < Size; i++)
		{
			f << setw(11) << left << arr_result[i] << ' ';
		}
		f << endl;		
	}
	f.close();												//вызываем метод close() объекта f класса ofstream 
}

void testing::operator += (const testing & other)			//перегрузка оператора +=
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
	// TODO: вставьте здесь оператор return
}

