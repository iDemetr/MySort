string ifFileDetected(string oldFileName)													//Функция увеличения номера файла в его названии.
{																							//oldFileName - Имя файла.
	int pos1(0);
	int pos2(0);
	int y(0);

	string str;
	while (1 > 0)
	{
		ifstream f4(oldFileName);
		if (f4.is_open())
		{
			pos1 = oldFileName.find("(", 0) + 1;											//Первая позиция номера файла.
			pos2 = oldFileName.find(")", 0);												//Последняя позиция номера файла.

			str = oldFileName.substr(pos1, pos2 - pos1);									//Считать номер файла.

			y = stoi(str.c_str()) + 1;														//Увеличить номер на 1.
			str = to_string(y);

			oldFileName.replace(pos1, pos2 - pos1, str);									//Заменить старый номер файла на новый.
		}
		else
		{
			return oldFileName;
		}
		f4.close();
	}
}