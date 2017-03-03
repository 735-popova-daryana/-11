#include <stdlib.h> 
#include <iostream> 
#include <windows.h> 
#include <fstream> 

using namespace std;
int main()
{
	int nomer = 1, nach = 0, end, j, N = 0; char s[1000];
	setlocale(LC_ALL, "Russian");
	ifstream fin("C:\\Users\\Дарьяна\\Documents\\Visual Studio 2008\\Projects\\laba1.1\\text.txt");
	if (!fin.is_open()) cout << "Файл не может быть открыт" << endl;
	while (!fin.eof()) (fin.getline(s, 1000));
	cout << "Текст разбитый на предложения:" << endl;
	for (int i = 0; i <= 1000; i++)
	{

		if ((s[i] == '.') && (s[i + 1] == ' ') && ((int)s[i+2] >= -64) && ((int)s[i+2] <= -33))
				{	N == 1; end = i; } // . Р
		if (s[i] == '"')
		{ while (s[i]== '"') 
			N==0; end = i}
				 //pryamaya rech'
			
		if ((s[i] == '.') || (s[i] == '!') || (s[i] == '?') || ((s[i] == '.') && (s[i + 1] == '.') && (s[i + 2] == '.')))

			{
				if ((s[i + 1] == ' ') && (s[i - 3] != '.') && (s[i - 3] != ','))
					{	N = 1; end = i; }
			}
		if (((s[i] == ':') && (s[i + 1] == ')')) || ((s[i] == ':') && ((s[i + 1] == '(')) || ((s[i] == ';') && (s[i + 1] == ')'))
			|| ((s[i] == ';') && (s[i + 1] == '(')) || ((s[i] == '?') && (s[i] == '!'))))
			{ N = 1; end = i+1; } //смайлы

		if (N == 1) 
			{
				cout<<nomer;
				if (nomer == 1)
				{ cout << ") "; }
				else cout << ")";
				nomer = nomer + 1;
				for (j = nach; j <= end; j++)
					{
						cout<<s[j];
					}
				cout<<endl;
				nach = end + 1;
				N = 0;
			}
		}
return 0;
}