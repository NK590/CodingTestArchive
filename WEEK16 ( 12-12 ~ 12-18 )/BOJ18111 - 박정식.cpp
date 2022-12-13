#include <iostream>

using namespace std;


int map[500][500];
int col, row, ownBlocks;
int totalBlockAmount, maxHeight;
int t = 99999999, height;

void Solution()
{
	maxHeight = totalBlockAmount / (col * row);

	for (int h = 0; h <= maxHeight; h++)
	{
		int currentTime = 0;
		int currentOwnBlocks = ownBlocks;
		for (int y = 0; y < col; y++)
		{
			for (int x = 0; x < row; x++)
			{
				if (map[y][x] > h)
				{
					currentTime += ((map[y][x] - h) *2);
					currentOwnBlocks += (map[y][x] - h);
				}
				else if (map[y][x] < h)
				{
					currentTime += (h - map[y][x]);
					currentOwnBlocks += (h - map[y][x]);
				}
			}
		}

		if (currentTime < t)
		{
			t = currentTime;
			height = h;
		}
		if (currentTime == t)
		{
			if (height < h)
				height = h;
		}
	}

	cout << t << " " << height;
}

void Print()
{
	for (int y = 0; y < col; y++)
	{
		for (int x = 0; x < row; x++)
		{
			cout << map[y][x] << " ";
		}
		cout << endl;
	}
}

void Input()
{
	cin >> col >> row >> ownBlocks;
	totalBlockAmount += ownBlocks;

	for (int y = 0; y < col; y++)
	{
		for (int x = 0; x < row; x++)
		{
			cin >> map[y][x];
			totalBlockAmount += map[y][x];
		}
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