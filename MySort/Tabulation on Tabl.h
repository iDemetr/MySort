string tab(string word)										//Функция табуляции 1-го столбца.
{
	if (word.size() > strlen("      "))					//Корректировка вывода по столбцу Портов. 
	{
		return ("\t|\t");
	}
	else
	{
		return ("\t\t|\t");
	}
}

string tab2(string word)									//Функция табуляции 2+ столбцов.
{
	if (word.size() > strlen("       "))					//Корректировка вывода по столбцу Портов. 
	{
		return ("\t|\t");
	}
	else
	{
		return ("\t\t|\t");
	}
}

string tab3(string word)									//Функция табуляции 2+ столбцов.
{
	if (word.size() < strlen(" "))					//Корректировка вывода по столбцу Портов. 
	{
		return ("\t\t\t|\t");
	}
	else
	{
		if (word.size() < strlen("           "))
		{
			return ("\t\t|\t");
		}
		else
			return ("\t|\t");
	}
}