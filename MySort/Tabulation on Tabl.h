string tab(string word)										//������� ��������� 1-�� �������.
{
	if (word.size() > strlen("      "))					//������������� ������ �� ������� ������. 
	{
		return ("\t|\t");
	}
	else
	{
		return ("\t\t|\t");
	}
}

string tab2(string word)									//������� ��������� 2+ ��������.
{
	if (word.size() > strlen("       "))					//������������� ������ �� ������� ������. 
	{
		return ("\t|\t");
	}
	else
	{
		return ("\t\t|\t");
	}
}

string tab3(string word)									//������� ��������� 2+ ��������.
{
	if (word.size() < strlen(" "))					//������������� ������ �� ������� ������. 
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