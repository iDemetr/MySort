string ifFileDetected(string oldFileName)													//������� ���������� ������ ����� � ��� ��������.
{																							//oldFileName - ��� �����.
	int pos1(0);
	int pos2(0);
	int y(0);

	string str;
	while (1 > 0)
	{
		ifstream f4(oldFileName);
		if (f4.is_open())
		{
			pos1 = oldFileName.find("(", 0) + 1;											//������ ������� ������ �����.
			pos2 = oldFileName.find(")", 0);												//��������� ������� ������ �����.

			str = oldFileName.substr(pos1, pos2 - pos1);									//������� ����� �����.

			y = stoi(str.c_str()) + 1;														//��������� ����� �� 1.
			str = to_string(y);

			oldFileName.replace(pos1, pos2 - pos1, str);									//�������� ������ ����� ����� �� �����.
		}
		else
		{
			return oldFileName;
		}
		f4.close();
	}
}