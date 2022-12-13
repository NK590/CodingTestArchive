#include <iostream>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

string gear[6];
bool visit[6];
queue<pair<int, int>> q;

void Print()
{
	cout << endl;
	for (int i = 1; i < 5; i++)
	{
		cout << gear[i] << endl;
	}
	cout << endl;
}

void Reset()
{
	for (int i = 1; i < 5; i++)
	{
		visit[i] = false;
	}
}

void Rotation(int index, int dir)
{
	if (index < 1 || index > 4)
		return;
	if (visit[index] == true)
		return;

	visit[index] = true;

	if (dir == 1)
	{
		gear[index] = gear[index][7] + gear[index].substr(0, 7);

		if(gear[index][7] != gear[index - 1][2])
			Rotation(index - 1, dir * -1);
		if (gear[index][3] != gear[index + 1][6])
			Rotation(index + 1, dir * -1);
	}		
	else
	{
		gear[index] = gear[index].substr(1, 7) + gear[index][0];

		if (gear[index][5] != gear[index - 1][2])
			Rotation(index - 1, dir * -1);
		if (gear[index][1] != gear[index + 1][6])
			Rotation(index + 1, dir * -1);
	}

}

void Solution()
{
	int result = 0;
	gear[0] = "11111111";
	gear[5] = "11111111";
	while (!q.empty())
	{
		int gearIndex = q.front().first;
		int dir = q.front().second;
		q.pop();

		Rotation(gearIndex, dir);
		Reset();
	}

	for (int i = 1; i < 5; i++)
	{
		if (gear[i][0] == '1')
		{
			result += pow(2, i - 1);
		}
	}
	cout << result << endl;
}

void Input()
{
	for (int i = 1; i < 5; i++)
	{
		cin >> gear[i];
	}

	int commandLenght;
	cin >> commandLenght;
	for (int i = 0; i < commandLenght; i++)
	{
		int gearIndex;
		int dir;
		cin >> gearIndex;
		cin >> dir;
		q.push({gearIndex, dir });
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Solution();

	return 0;
}