#include "MySort.h"																			//Заголовочный файл функций вывода и сортировки по одному аргументу.
#include "MySort2xStr.h"																	//Заголовочный файл функций вывода и сортировки по двум аргументам.


using namespace std;

void massage();																				//Прототип функции.

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);																		//Русский язык в консоли.
	SetConsoleOutputCP(1251);																//Русский язык в файле.


	int i(0);																				//Счетчик.
	int j(0);																				//Счетчик по строкам таблицы.
	int ch1(0);																				//Буфер ввода.
	int ch(0);																				//Буфер ввода.

	int countStr(0);																		//Число строк в таблице.
	int countRase(0);																		//Число рейсов.
	int countPort(0);																		//Число портов.
	int nomberStr(0);																		//Номер строки в настоящий момент.

	bool Flag1 = true;                                                                      //Логическая переменная для перехода в главное меню программы.

	string str;
	string bufer;
	string InputFile("Input.txt");                                                          //Входной файл Рейсов до Сортировки.
	string FileName;																		//Имя выходного файла.

	WCHAR PathName[MAX_PATH];																//Путь к расположению программы.
	GetModuleFileName(NULL, PathName, sizeof(PathName));

	PathName[wcslen(PathName) - 10] = 0;													//Игнорировать вывод имени программы в пути.


	cout << " Программа сортировки таблицы Рейсов.\n\n";

	//Start();																				//Анимация запуска программы.

	ifstream f1(InputFile);																	//Открываем исходный файл.

	if (f1.is_open())																		//Проверка наличия исходного файла.
	{
		cout << "\n\n Исходный файл обнаружен.\n";

		//Подсчет колличества строк в таблице.
		while (!f1.eof())																	//Подсчет колличества строк в таблице.
		{
			getline(f1, str);
			countStr++;
		}
		cout << " Число строк в таблице: " << countStr << endl;


		//Объявления динамического массива.
		string** array = new string * [7];													//Объявления динамического массива для заполнения данными из входного файла.
		for (i = 0; i < 7; i++)
			array[i] = new string[countStr];

		f1.seekg(0);																		//Перевод маркера текущей позиции в начало файла.

		//Главное меню.
		while (Flag1 == true)																//Цикл главного меню.
		{
			cout << " Отсортировать таблицу по полю:\n";
			cout << " Рейс\t\t(1)\t|\tПорт отправления\t(4)\n Море\t\t(2)\t|\tПорт прибытия\t\t(5)\n Страна\t\t(3)\t|\n";
			cout << "\n Выйти из программы:\t\t(Esc)\n\n";

			//Диалог до сортировки.

			do
			{
				ch = _getch();
			} while (ch != 49 && ch != 51 && ch != 52 && ch != 53 && ch != 50 && ch != 27);

			i = 0;

			//Считывание из входного файла в массив.
			while (!f1.eof())															//Пока не достигнут конец файла.
			{																			//Сканировать каждую строку в таблице.
				i++;																	//Какая строка сейчас активна.

				if (i > 5)																//Пропуск первых Шести слов в таблице.
				{
					f1 >> bufer; 														//Считать имя рейса из файла.										//Наименование рейса.	[0]

					array[0][nomberStr] = bufer;

					if (bufer == "----")												//Если Рейса нет, а есть только порты.
					{
						f1 >> array[1][nomberStr];										//Порт отправления.
						f1 >> array[2][nomberStr];										//Страна отправления.
						f1 >> array[3][nomberStr];										//Море отправления.

						countPort++;
					}
					else																//Если же имя рейса существует.
					{
						f1 >> array[1][nomberStr];										//Порт отправления.		[1]
						f1 >> array[2][nomberStr];										//Страна отправления.	[2]
						f1 >> array[3][nomberStr];										//Море отправления.		[3]
						f1 >> array[4][nomberStr];										//Порт прибытия.		[4]
						f1 >> array[5][nomberStr];										//Страна прибытия.		[5]
						f1 >> array[6][nomberStr];										//Море порта.			[6]	

						countRase++;
					}

					nomberStr++;
				}
				else
				{
					f1 >> bufer;
				}
			}

			if (ch == '1')																//Сортировка по имени рейса.
			{
				cout << " Число рейсов обнаружено: " << countRase << endl;
				massage();

				do
				{
					ch1 = _getch();
				} while (ch1 != 49 && ch1 != 50 && ch1 != 27);

				if (ch1 == '1')															//Сортировка по возрастанию.
				{
					FileName = "Rase Sorted Up (1).txt";
					sortUp(nomberStr, 0, array, FileName);
					Flag1 = false;
				}
				if (ch1 == '2')															//Сортировка по убыванию.
				{
					FileName = "Rase Sorted Down (1).txt";
					sortDown(nomberStr, 0, array, FileName);
					Flag1 = false;
				}
				if (ch1 == 27)
				{
					system("cls");
				}

			}

			if (ch == '4')																//Сортировка по порту отправления.
			{
				cout << " Число Портов Отправления обнаружено: " << nomberStr << endl;
				massage();

				do
				{
					ch1 = _getch();
				} while (ch1 != 49 && ch1 != 50 && ch1 != 27);

				if (ch1 == '1')															//Сортировка по возрастанию.
				{
					FileName = "OutPort Sorted Up (1).txt";
					sortUp(nomberStr, 1, array, FileName);
					Flag1 = false;
				}
				if (ch1 == '2')															//Сортировка по убыванию.
				{
					FileName = "OutPort Sorted Down (1).txt";
					sortDown(nomberStr, 1, array, FileName);
					Flag1 = false;
				}
				if (ch1 == 27)
				{
					system("cls");
				}

			}

			if (ch == '2')																//Сортировка по морям.
			{
				cout << " Число Морей обнаружено: " << nomberStr + countRase << endl;
				massage();

				int countSea(0);

				do
				{
					ch1 = _getch();
				} while (ch1 != 49 && ch1 != 50 && ch1 != 27);

				countSea = countRase + nomberStr;

				if (ch1 == '1')															//Сортировка по возрастанию.
				{
					FileName = "Sea Sorted Up (1).txt";
					sortUp2(countSea, 3, array, FileName);
					Flag1 = false;
				}
				if (ch1 == '2')	 														//Сортировка по убыванию.
				{
					FileName = "Sea Sorted Down (1).txt";
					sortDown2(countSea, 3, array, FileName);
					Flag1 = false;
				}
				if (ch1 == 27)
				{
					system("cls");
				}

			}

			if (ch == '5')																//Сортировка по порту прибытиям.
			{
				cout << " Число Портов Прибытия обнаружено: " << countRase << endl;
				massage();

				do
				{
					ch1 = _getch();
				} while (ch1 != 49 && ch1 != 50 && ch1 != 27);

				if (ch1 == '1')															//Сортировка по возрастанию.
				{
					FileName = "InPort Sorted Up (1).txt";
					sortUp(nomberStr, 4, array, FileName);
					Flag1 = false;
				}
				if (ch1 == '2')	 														//Сортировка по убыванию.
				{
					FileName = "InPort Sorted Down (1).txt";
					sortDown(countRase, 4, array, FileName);
					Flag1 = false;
				}
				if (ch1 == 27)
				{
					system("cls");
				}

			}

			if (ch == '3')																//Сортировка по странам.
			{
				cout << " Число Стран обнаружено: " << nomberStr + countRase << endl;
				massage();

				int countCountry(0);

				do
				{
					ch1 = _getch();
				} while (ch1 != 49 && ch1 != 50 && ch1 != 27);

				countCountry = countRase + nomberStr;

				if (ch1 == '1')															//Сортировка по возрастанию.
				{
					FileName = "Country Sorted Up (1).txt";
					sortUp2(countCountry, 2, array, FileName);
					Flag1 = false;
				}
				if (ch1 == '2')	 														//Сортировка по убыванию.
				{
					FileName = "Country Sorted Down (1).txt";
					sortDown2(countCountry, 2, array, FileName);
					Flag1 = false;
				}
				if (ch1 == 27)
				{
					system("cls");
				}

			}

			if (ch == 27)
			{
				cout << "\n Завершение программы";

				//Loading(500, 4);															//Анимация загрузки.

				return 1;
			}


			//Диалог После сортировки.
			if (ch1 != 27)
			{
				printf("% ws\n", PathName);
				cout << "\n\n Перейти в главное меню:\t(Enter)\n Выйти из программы:\t\t(Esc)\n";

				do
				{
					ch = _getch();
				} while (ch != 13 && ch != 27);

				if (ch == 27)																//Выход из программы.
				{
					cout << "\n Завершение программы";

					//Loading(500, 4);														//Анимация завершения программы.
					return 1;
				}
				else
					if (ch == 13)															//Переход в главное меню.
					{
						system("cls");
						Flag1 = true;
					}
			}
		}

		//Освобождение памяти.
		for (i = 0; i < 7; i++)
		{
			delete[] array[i];
		}
		delete[] array;
	}
	else
	{
		cout << "\n Файл Input.txt не обнаружен.\n Расположите файл по пути: ";
		printf("% ws\n", PathName);
		cout << " Для завершения программы, нажмите любую клавишу.";
		_getch();
	}

	cout << "\n Завершение программы";

	Loading(500, 4);																		//Анимация Завершения программы.

	return 0;
}

void massage ()																				//Функция вывода сообщений.
{
	cout << " Отсортировать в порядке возрастания:\t\t(1)\n";
	cout << " Отсортировать в порядке убывания:	   \t(2)\n\n";
	cout << " Вернуться в главное меню:\t\t\t(Esc)\n\n";
}