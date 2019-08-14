#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

string** map;

int main()
{
	int rows;
	int cols;
	cout << "행의 갯수와 열의 갯수를 입력 해 주세요\n";
	cin >> rows >> cols;
	if (rows <= 0 || cols <= 0)
	{
		cout << "잘못 된 입력입니다. ";
		return 0;
	}

	map = new string*[rows];
	for (int i = 0; i < rows; i++)
	{
		map[i] = new string[cols];
		for (int j = 0; j < cols; j++)
		{
			map[i][j] = "";
		}
	}
	int cursorR = rows / 2;
	int cursorC = cols / 2;
	while (true)
	{
		system("cls");
		// print
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (i == cursorR && j == cursorC)
				{
					cout << "◎";
					continue;
				}
				cout << (map[i][j] == "" ? "□" : "■") ;
			}
			cout << '\n';
		}
		char input = getch();
		cout << (int)input;
		switch (input)
		{
		case 'w':
		case 'W':
			cursorR--;
			break;
		case 's':
		case 'S':
			cursorR++;
			break;
		case 'd':
		case 'D':
			cursorC++;
			break;
		case 'a':
		case 'A':
			cursorC--;
			break;
		case 13: // enter key
			{
			cout << "write code\n";
			string read;
			cin >> read;
			map[cursorR][cursorC] = read;
			cout << "write another args num\n";
			int argsnum = 0;
			cin >> argsnum;
			map[cursorR][cursorC] += " " + to_string(argsnum);
			for (int i = 0; i < argsnum; i++)
			{
				cin >> read;
				map[cursorR][cursorC] += " " + read;
			}
			}
			break;
		case 27:
			goto end;
		case 8:
			map[cursorR][cursorC] = "";
		default :
			break;
		}

	}

end:
	// write to file
	system("cls");
	cout << "input your filename\n";
	string filename;
	cin >> filename;

	ofstream ofs(filename, ios_base::out);
	ofs << rows << " " << cols << '\n';
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (map[i][j] == "")
			{
				continue;
			}

			ofs <<i << ' '<< j << ' '<< map[i][j] << '\n';
		}
		delete[] map[i];
	}
	delete[] map;

	return 0;
}