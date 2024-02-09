#include "testing.h"

testing* Add_obj_class(testing *obj, int amount);					//объявление функции добавления нового объекта класса(студента)
void SetData(testing* obj, const int amount);						//объявление функции заполнения данных об учащемся
void Del_memory_obj(testing* obj, int amount);						//объявление функции очистки выделенной динамической памяти

int main()
{
	setlocale(LC_ALL, "ru");
	testing * ptesting = nullptr;									//указатель на объект класса testing, хранящий данные студента 
	testing * ptesting_discipline = nullptr;						//указатель на объект класса testing, хранящий данные студента, который сдал заданный предмет  
	char Answer = 'y';												//ответ пользователя
	int CountofStudents = 0;										//количество учащихся
	int counter = 0;												//счётчик итераций цыкла while
	int amountofstudents = 0;										//счётчик студентов, сдающих заданную дисциплину
	//int count_equal = 1;											//количество студентов с одинаковым средним баллом
	testing temp;													//объект класса для хранения промежуточных данных
	char discipline[20]="";											//название предмета для сортировки студентов по баллам
	int * pcount_equal = nullptr;									//указатель на массив размеров массивов индексов студентов с одинаковым средним баллом
	int ** pequal = nullptr;										//указатель на массив массивов индексов студентов с одинаковым средним баллом 
	//bool first_entrance = true;										//флаг, указывающий на первое совпадение средних баллов двух студентов
	bool fit = false;												//флаг, указывающий на совпадение элемента массива индексов текущего студента с элементом массива индексов предыдущего студента

	do
	{
		ptesting = Add_obj_class(ptesting, CountofStudents);		//выделение динамической памяти под объект класса testing
		SetData(ptesting, CountofStudents);							//заполнение данных об учащемся				
		cout << "Хотите внести данные ещё об одном учащемся\n";
		cin >> Answer;
		CountofStudents++;											//инкремент количества студентов

	}  while (Answer == 'y');

	for (int i = 0; i < CountofStudents; i++)						//отображение информации о студентах
	{
		cout << "\n\t\t\t\tРезультаты тестирования " << ptesting[i].Get_name() << endl;
		cout << "Учебная дисциплина\t\t";
		ptesting[i].Get_discipline_name();
		cout << "Количество набранных баллов\t";
		ptesting[i].Get_Score();
	}
	
	for (int i = 0; i < CountofStudents; i++)						//вывод информации о студентах в файл
	{
		ptesting[i].Save_File();
	}

	counter = CountofStudents;										//инициализация счётчика пузырьковой сортировки 
	while (counter > 0)
	{
		for (int i = 0; i < CountofStudents-1; i++)					//сортировка студентов по среднему баллу
		{
			if (ptesting[i+1].Average_Score() > ptesting[i].Average_Score())
			{
				temp = ptesting[i];
				ptesting[i] = ptesting[i+1];
				ptesting[i+1] = temp;
			}
		}
		counter--;													//декремент счётчика итераций цыкла while
	}
	
	/*for (int i = 0; i < CountofStudents - 1; i++)
	{
		if (ptesting[i].Average_Score() == ptesting[i + 1].Average_Score())
		{
			count_equal++;											//подсчитываем количество студентов с одинаковым средним баллом 
		}
	}*/
	pcount_equal = new int[CountofStudents];						//выделение динамической памяти под массив размеров массивов индексов студентов с одинаковым средним баллом
	
	for (int i = 0; i < CountofStudents; i++)						//i-итератор студентов, j-итератор студентов с одинаковым средним баллом  
	{
		pcount_equal[i] = 0;										//инициализируем элементы массива размеров

		for (int j = 0; j < CountofStudents; j++)
		{
			if (ptesting[i].Average_Score() == ptesting[j].Average_Score())	//находим совпадение средних баллов студентов
			{
				pcount_equal[i]++;									//и при совпадении увеличиваем на единицу элемент массива размеров
			}
		}
	}

	pequal = new int* [CountofStudents];							//выделение динамической памяти под массив массивов индексов студентов с одинаковым средним баллом 
	for (int i = 0; i < CountofStudents; i++)
	{
		pequal[i] = new int[pcount_equal[i]];						//выделяем динамическую память под массив индексов 
	}

	for (int i = 0; i < CountofStudents; i++)						//i-итератор индексов студентов, j-итератор индексов студентов с одинаковым средним баллом 
	{
		for (int j = 0, k = 0; j < CountofStudents, k < pcount_equal[i]; j++)	//k-итератор индексов массива индексов студентов с одинаковым средним баллом 
		{
			if (ptesting[i].Average_Score() == ptesting[j].Average_Score())	//находим совпадение средних баллов студентов
			{
				pequal[i][k] = j;									//и при совпадении записываем индекс в массив индексов студентов
				k++;
			}						
		}
	}

	cout << "\nCтуденты по среднему баллу в порядке убывания\n";
	for (int k = 0; k < pcount_equal[0]; k++)						//перебираем элементы первого массива индексов студентов с совпадающим средним баллом
	{
		cout << ptesting[pequal[0][k]].Get_name() << '\t';
	}
		cout << '\n';

	for (int i = 1; i < CountofStudents; i++)						//перебираем элементы массива студентов
	{
		for (int k = 0; k < pcount_equal[i]; k++)					//перебираем элементы массива индексов студентов с совпадающим средним баллом
		{
			if (pequal[i][k] != pequal[i - 1][k])					//если элемент массива индексов текущего студента не совпадает с элементом массива индексов предыдущего студента
			{
				cout << ptesting[pequal[i][k]].Get_name() << '\t';	//выводим имена студентов через табуляцию
				fit = true;
			}
		}
		if (fit)
		{
			cout << '\n';
			fit = false;
		}
	}		
	
	for (int i = 0; i < CountofStudents; i++)						//чистим динамическую память
	{
		delete[] pequal[i];											//чистим память массива индексов i-го студента с одинаковым средним баллом 
	}
	delete[] pequal;												//чистим память массивов индексов всех студентов с одинаковым срелним баллом
	pequal = nullptr;

	delete[] pcount_equal;											//чистим память размеров массивов индексов студентов с одинаковым средним баллом
	pcount_equal = nullptr;

	do
	{
		cout << "\nХотите сделать сортировку студентов по баллам за определённый предмет\n";
		cin >> Answer;
		if (Answer == 'y')
		{
			cout << "Введите название предмета, по набранным баллам за который нужно сделать сортировку студентов" << endl;
			cin >> discipline;
			amountofstudents = 0;
			for (int i = 0; i < CountofStudents; i++)
			{
				for (int j = 0; j < ptesting[i].Get_size(); j++)	//определяем количество студентов, которые сдают заданную дисциплину
				{
					if (discipline == ptesting[i].Get_discipline(j))	//j-ая дисциплина, которую сдаёт i-ый студент
					{
						amountofstudents++;
					}
				}
			}
			ptesting_discipline = new testing[amountofstudents];	//создание динамического массива студентов, которые сдают заданную дисциплину

			for (int i = 0, j = 0; i < CountofStudents, j < amountofstudents; i++)	//i-перебор объектов класса(судентов), j-перебор студентов, сдающих заданную дисциплину  
			{
				for (int k = 0; k < ptesting[i].Get_size(); k++)	//k-перебор учебных дисциплин, которые сдаёт данный студент 
				{
					if (discipline == ptesting[i].Get_discipline(k))
					{
						ptesting_discipline[j] += ptesting[i];	    //заполнение массива студентов, сдающих заданную дисциплину, из общего массива с использованием перегрузки оператора +=
						j++;
					}
				}
			}

			counter = amountofstudents;								//инициализация счётчика пузырьковой сортировки
			while (counter > 0)
			{
				for (int i = 0; i < amountofstudents - 1; i++)		//сортировка студентов по набранным баллам за данную дисциплину 
				{
					if (ptesting_discipline[i + 1].Get_Score_discipline(discipline) > ptesting_discipline[i].Get_Score_discipline(discipline))
					{
						temp = ptesting_discipline[i];
						ptesting_discipline[i] = ptesting_discipline[i + 1];
						ptesting_discipline[i + 1] = temp;
					}
				}
				counter--;
			}
			switch (amountofstudents)								 //вывод результата сортировки студентов по набранным баллам за заданный предмет
			{
			case 0:
				cout << discipline << " не сдавал ни один студент\n";
				break;
			case 1:
				cout << discipline << " сдавал только один студент\n";
				break;
			default:
				cout << "Cтуденты по набранным баллам за " << discipline << " в порядке убывания\n";
			}

			for (int i = 0; i < amountofstudents - 1; i++)
			{
				if (ptesting_discipline[i].Get_Score_discipline(discipline) != ptesting_discipline[i + 1].Get_Score_discipline(discipline))	//если баллы по заданному предмету текущего и следующего объектов класса не равны
				{
					cout << ptesting_discipline[i].Get_name() << endl;		//отображение имён студентов по набранному баллу по выбранному предмету в порядке убывания
					if (i == amountofstudents - 2)
						cout << ptesting_discipline[i + 1].Get_name() << endl;	//отображение имени последнего объекта класса
				}
				else                                                            //если средние баллы текущего и следующего объектов класса равны выводим 2 имени в одну строку
				{
					cout << ptesting_discipline[i].Get_name() << '\t' << ptesting_discipline[i + 1].Get_name() << endl;
					i++;														//увеличиваем счёчик итераций чтоб не выводить 2 раза имя одного и того же студента
					if (i == amountofstudents - 2)
						cout << ptesting_discipline[i + 1].Get_name() << endl;	//отображение имени последнего объекта класса
				}
			}
		Del_memory_obj(ptesting_discipline, amountofstudents);			//очистка выделенной динамической памяти под массив студентов, сдающих заданную дисциплину
		}
	} while (Answer == 'y');
	
	Del_memory_obj(ptesting, CountofStudents);						//очистка выделенной динамической памяти под основной массив студентов
	return 0;
}

testing * Add_obj_class(testing* obj, int amount)					//определение функции добавления нового объекта класса(студента)
{
	if (amount == 0)
	{
		obj = new testing;											//выделяем динамическую память под один объект класса testing
	}
	else
	{
		testing * tempobj = new testing[amount + 1];				//выделяем дин. память под временное массив объектов, с размером на один больше чем количество учащихся

		for (int i = 0; i < amount; i++)
		{
			tempobj[i] = obj[i];									//копируем данные с основного масива объектов класса(студента) во временный
		}
		delete[] obj;												//очищаем динамическую память, выделенную под основной массив объектов класса testing
		obj = tempobj;												//в указатель основного массива присваиваем адрес временного массива
		tempobj = nullptr;											//обнуляем указатель на временный массив объектов 
	}
	return obj;														//возращаем указатель на массив объектов класса
}

void SetData (testing* obj, const int amount)						//определение функции заполнения данных об учащемся
{
	obj[amount].Set_Size();											//вызов метода задания колличества учебных дисциплин
	obj[amount].Set_name();											//вызов метода задания имени учащегося 
	obj[amount].Set_discipline_name();								//вызов метода занесения в массив названий учебных дисциплин
	obj[amount].Set_Score();										//вызов метода занесения в массив количества баллов, набранных по разным предметам
}

void Del_memory_obj(testing* obj, int amount)						//определение функции очистки выделенной динамической памяти
{
	for (int i = 0; i < amount; i++)	
	{
		obj[i].Del_discipline_name();
	}

	for (int i = 0; i < amount; i++)
	{
		obj[i].Del_Score();
	}
	delete[] obj;													//очистка динамической памяти, выделенной под массив объектов класса testing
    obj = nullptr; 
}