#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

// 위 오른쪽 아래 왼쪽
int dir;

void Rotate(char command)
{
	if (command == 'L')
		dir--;
	else if (command == 'R')
		dir++;

	if (dir == -1)
		dir = 3;
	else if (dir == 4)
		dir = 0;
}

int Turtle(string command)
{
	dir = 0;
	int area = 0;
	int x = 0, y = 0;
	int minX= 0, minY = 0, maxX = 0, maxY = 0;

	for (int i = 0; i < command.size(); i++)
	{
		if (dir == 0)
		{
			if (command[i] == 'F')
				y++;
			else if (command[i] == 'B')
				y--;
			else
				Rotate(command[i]);
		}
		else if (dir == 1)
		{
			if (command[i] == 'F')
				x++;
			else if (command[i] == 'B')
				x--;
			else
				Rotate(command[i]);
		}
		else if (dir == 2)
		{
			if (command[i] == 'F')
				y--;
			else if (command[i] == 'B')
				y++;
			else
				Rotate(command[i]);
		}
		else if (dir == 3)
		{
			if (command[i] == 'F')
				x--;
			else if (command[i] == 'B')
				x++;
			else
				Rotate(command[i]);
		}

		minX = min(x, minX);
		minY = min(y, minY);
		maxX = max(x, maxX);
		maxY = max(y, maxY);
	}

	area = (maxX - minX) * (maxY - minY);

	return area;
}

int main()
{
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		string command;
		cin >> command;
		cout << Turtle(command) << endl;
	}
	return 0;
}