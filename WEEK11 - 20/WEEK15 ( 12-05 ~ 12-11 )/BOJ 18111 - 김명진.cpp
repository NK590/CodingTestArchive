#include <iostream>

using namespace std;

int ground[500][500];

int main()
{
	int row, column, ownBlocks;
	cin >> row >> column >> ownBlocks;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			cin >> ground[i][j];
		}
	}

	int bestTime = 2100000000;
	int bestHeight = 0;;
	for (int k = 0; k <= 256; ++k)
	{
		int temp = 0;
		int blocks = ownBlocks;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				if (k > ground[i][j])
				{
					temp += k - ground[i][j];
					blocks -= k- ground[i][j];
				}
				else if (k < ground[i][j])
				{
					temp += 2 * (ground[i][j] - k);
					blocks += ground[i][j] - k;
				}
				else continue;
			}
		}
		if (blocks >= 0)
		{
			if (temp <= bestTime)
			{
				bestTime = temp;
				bestHeight = k;
			}
		}
	}

	cout << bestTime << " " << bestHeight;
}