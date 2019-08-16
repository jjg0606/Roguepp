#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

string** map;
void readmap(int& rows, int& cols);
int main()
{
	int read = 0;
	cout << "새로 시작하려면 1을, 기존 파일을 읽으시려면 2를 눌러주세요\n";
	cin >> read;
	int rows;
	int cols;
	if (read == 1)
	{
		cout << "행의 갯수와 열의 갯수를 입력 해 주세요\n";
		cin >> rows >> cols;
		map = new string*[rows];
		for (int i = 0; i < rows; i++)
		{
			map[i] = new string[cols];
			for (int j = 0; j < cols; j++)
			{
				map[i][j] = "";
			}
		}
	}
	else if (read == 2)
	{
		readmap(rows, cols);
	}
	else
	{
		cout << "잘못 된 입력입니다.\n";
	}


	if (rows <= 0 || cols <= 0)
	{
		cout << "잘못 된 입력입니다. ";
		return 0;
	}

	int cursorR = rows / 2;
	int cursorC = cols / 2;
	while (true)
	{
		system("cls");
		// print
		cout << map[cursorR][cursorC] << '\n';
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
		
		switch (input)
		{
		case 'w':
		case 'W':
			cursorR = cursorR - 1 >= 0 ? cursorR - 1 : 0;		
			break;
		case 's':
		case 'S':
			cursorR = cursorR + 1 < rows ? cursorR + 1 : rows - 1;
			break;
		case 'd':
		case 'D':
			cursorC = cursorC + 1 < cols ? cursorC + 1 : cols - 1;
			break;
		case 'a':
		case 'A':
			cursorC = cursorC - 1 >= 0 ? cursorC - 1 : 0;
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

void readmap(int& rows, int& cols)
{
	cout << "읽어 올 파일명을 입력해주세요\n";
	string readf = "";
	cin >> readf;
	ifstream ifs(readf, ios::in);
	ifs >> rows >> cols;

	map = new string*[rows];
	for (int r = 0; r < rows; r++)
	{
		map[r] = new string[cols];
		for (int c = 0; c < cols; c++)
		{
			map[r][c] = "";
		}
	}

	while (true)
	{
		int row = 0, col = 0;
		ifs >> row >> col;

		string objectText = "";
		ifs >> objectText;
		if (objectText == "")
		{
			break;
		}

		objectText += " ";
		int params = 0;
		ifs >> params;
		objectText.append(to_string(params));
		for (int i = 0; i < params; i++)
		{
			string read;
			ifs >> read;
			objectText.append(" " + read);
		}
		map[row][col] = objectText;
	}
	ifs.close();
}