#include <vector>

using namespace std;

//������� ������ ��������������� �������.
void vivod2(int countStlb, string** array, int* arrayIndex, string* arrayStr, string fileName)
{
	//countStlb 	� ����� ������������ �������.
	//Array			- ����������� ������.
	//arrayIndex	� ������ �������� ��������������� ���������.
	//arrayStr		- ������ ��������������� �����.
	//filename 		- ��� ��������� �����.


	int str(0), stlb(0), i(0), j(0), a(0),b(0);												//�������.

	fileName = ifFileDetected(fileName);

	ofstream f2(fileName);																	//������� ���� ��� ����������.

	vector<string>localVec1(countStlb);														//��������� ������ ������/���� �����������.
	vector<string>localVec2(countStlb);														//��������� ������ ������/���� ��������.

	//����� � ���� �����.
	if (!fileName.find("Sea"))																//���� �������� ���� �����.
	{
		//����������� �� ��������� ������� � ��������� ������.
		for (i = 0; i < countStlb; i++)
		{
			localVec1[i] = array[3][i];
			localVec2[i] = array[6][i];
		}

		//����� � ���� ���������.
		{
			if (fileName.find("Up") != string::npos)										//���� ���������� �� �����������.
			{
				f2 << "  ������� ������������� �� ��������� <<����>> �� �����������.\n\n";
			}
			else																			//���� ���������� �� ��������.
			{
				f2 << "  ������� ������������� �� ��������� <<����>> �� ��������.\n\n";
			}

			f2 << " ����:\t\t|\t����:\t\t|\t����:\t\t|\t������:\n";							//������� 1-� ������� �����.
			f2 << "~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~\n";
		}

		//����� � ���� ����������.
		while (stlb < countStlb)
		{
			str = arrayIndex[stlb];															//������ ������� �� ������� ��������.

			if (arrayStr[stlb] == localVec1[str] && localVec1[str] != "----")				//���� ��������������� ����� ���������
																							//� ������� �����������.
			{
				f2 << " " << localVec1[str] << tab(localVec1[str]);							//������� ���� ����������� �����.
				f2 << array[0][str] << tab2(array[0][str]);									//������� ����.
				f2 << array[1][str] << tab2(array[1][str]);									//������� ���� ����������� �����.
				f2 << array[2][str] << "\n";												//������� ������ ����������� �����.
				f2 << "----------------|-----------------------|-----------------------|-----------------------\n";

				localVec1[str] = "0";														//"�������" ����� �� ������� �����������.
			}																				//���� ������������� ������ ������������ �������.

			if (localVec2[str] == arrayStr[stlb] && localVec2[str] != "----")
			{
				f2 << " " << localVec2[str] << tab(localVec2[str]);							//������� ���� �������� �����.
				f2 << array[0][str] << tab2(array[0][str]);									//������� ����.
				f2 << array[4][str] << tab2(array[4][str]);									//������� ���� �������� �����.
				f2 << array[5][str] << "\n";												//������� ������ �������� �����.
				f2 << "----------------|-----------------------|-----------------------|-----------------------\n";

				localVec2[str] = "0";														//"�������" ����� �� ������� ��������.
			}																				//���� ������������� ������ ������������ �������.
			
			stlb++;

		}
	}

	//����� � ���� �����.
	if (!fileName.find("Country"))															//���� �������� ���� �����.
	{
		for (i = 0; i < countStlb; i++)
		{
			localVec1[i] = array[2][i];
			localVec2[i] = array[5][i];
		}

		//����� � ���� ���������.
		{
			if (fileName.find("Up") != string::npos)										//���� ���������� �� �����������.
			{
				f2 << "  ������� ������������� �� ��������� <<������>> �� �����������.\n\n";
			}
			else 																			//���� ���������� �� ��������.
			{
				f2 << "  ������� ������������� �� ��������� <<������>> �� ��������.\n\n";
			}

			f2 << " ������:\t|\t�����:\t\t|\t����:\t\t|\t����:\n";							//������� 1-� ������� �����.
			f2 << "~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~\n";
		}

		//����� � ���� ����������.
		while (stlb < countStlb)
		{
			str = arrayIndex[stlb];															//������ ������� �� ������� ��������.

			a = 0; b = 0;

			if (arrayStr[stlb] == localVec1[str] && localVec1[str] != "----")				//���� ��������������� ����� ���������
			{																				//� ������� �����������.

				f2 << " " << localVec1[str] << tab(localVec1[str]);							//������� ������ ����������� �����.
				f2 << array[0][str] << tab2(array[0][str]);									//������� ����.
				f2 << array[1][str] << tab2(array[1][str]);									//������� ���� ����������� �����.
				f2 << array[3][str] << "\n";												//������� ���� ����������� �����.
				f2 << "----------------|-----------------------|-----------------------|-----------------------\n";
				
				localVec1[str] = "0";														//"�������" ����� �� ������� �����������.
			}

			if (localVec2[str] == arrayStr[stlb] && localVec2[str] != "----")				//���� ��������������� ����� ���������
			{																				//� ������� ��������.

				f2 << " " << localVec2[str] << tab(localVec2[str]);							//������� ������ �������� �����.
				f2 << array[0][str] << tab2(array[0][str]);									//������� ����.
				f2 << array[4][str] << tab2(array[4][str]);									//������� ���� �������� �����.
				f2 << array[6][str] << "\n";												//������� ���� �������� �����.
				f2 << "----------------|-----------------------|-----------------------|-----------------------\n";
				
				localVec2[str] = "0";														//"�������" ����� �� ������� ��������.
			}
			stlb++;
		}
	}

	cout << "\n ���������� ���������.\n ���� <<" << fileName << ">> �������� �� ����: ";

	f2.close();
}


//���������� �� ����������� ���� ����� ��� �����. (��������� �������� ������� � ������������ ������������ ��������(������ ������))
void sortUp2(int countStlb, int nomberStlb, string** array, string fileName)
{
	int i(0), j(0), k(0), j1(0), count(0);													//�������.

	string* arrayStr = new string[countStlb];												//������ ����������� ����������.
	int* arrayIndex = new int[countStlb];													//������ �������� ����������.

	//������ � ��������� ������.
	while (i < countStlb)
	{
		arrayStr[i] = array[nomberStlb][j];													//������ 1 ��������� ���� ��� ������ � ������.
		arrayIndex[i] = j;																	//������ ������� 1-�� ���������.

		string strr("");

		if (array[nomberStlb + 3][j] != strr)
		{
			arrayStr[i + 1] = array[nomberStlb + 3][j1];									//������ 2-�� ��������� ���� ��� ������ � ������.
			arrayIndex[i + 1] = j;															//������ ������� 2-�� ��������� � ������.
			i++; j1++;
		}
		i++; j++;
	}

	//���������� � ���������� �������.
	for (i = 0; i < countStlb; i++)															//���� �������� ���������� ��������.
	{
		j = i;
		for (k = i + 1; k < countStlb; k++)													//���� �������� ��������� ��������.
		{
			if (arrayStr[k] < arrayStr[j])													//���� ��������� ��-� �����e �����������.
			{
				j = k;
			}
		}
		if (j != i)
			count++;

		swap(arrayStr[j], arrayStr[i]);														//������ ������� ���������.
		swap(arrayIndex[j], arrayIndex[i]);													//������ ������� ������� ����������.
	}

	vivod2(countStlb, array, arrayIndex, arrayStr, fileName);

	cout << count << "!!\n";
	delete[] arrayStr;																		//������������ ������.
	delete[] arrayIndex;																	//������������ ������.
}

//���������� �� �������� ���� ����� ��� �����. (��������� �������� ������� � ������������ ������������ ��������(������ ������))
void sortDown2(int countStlb, int nomberStlb, string** array, string fileName)
{
	int i(0), j(0), k(0), j1(0), count(0);													//�������.

	string* arrayStr = new string[countStlb];												//������ ����������� ����������.
	int* arrayIndex = new int[countStlb];													//������ �������� ����������.

	//������ � ��������� ������.
	while (i < countStlb)
	{
		arrayStr[i] = array[nomberStlb][j];													//������ 1 ��������� ���� ��� ������ � ������.
		arrayIndex[i] = j;																	//������ ������� 1-�� ���������.

		string strr("");

		if (array[nomberStlb + 3][j] != strr)
		{
			arrayStr[i + 1] = array[nomberStlb + 3][j1];									//������ 2-�� ��������� ���� ��� ������ � ������.
			arrayIndex[i + 1] = j;															//������ ������� 2-�� ��������� � ������.
			i++; j1++;
		}
		i++; j++;
	}

	//���������� ���������� �������.
	for (i = 0; i < countStlb; i++)															//���� �������� ���������� ��������.
	{
		j = i;
		for (k = i + 1; k < countStlb; k++)													//���� �������� ��������� ��������.
		{
			if (arrayStr[k] > arrayStr[j])													//���� ��������� ��-� ������ �����������.
			{
				j = k;
			}
		}
		if (j != i)
			count++;

		swap(arrayStr[j], arrayStr[i]);														//������ ������� ���������.
		swap(arrayIndex[j], arrayIndex[i]);													//������ ������� ������� ����������.
	}
	vivod2(countStlb, array, arrayIndex, arrayStr, fileName);

	cout << count << "!!\n";
	delete[] arrayStr;																		//������������ ������.
	delete[] arrayIndex;																	//������������ ������.
}