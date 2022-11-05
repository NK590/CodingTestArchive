#include <iostream>
#include <vector>

using namespace std;

bool board[5][20000];

int main()
{
	int n;
	string signal;
	vector<int> result;

	cin >> n >> signal;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < signal.length() / 5; ++j)
		{
			if (signal[(i * signal.length() / 5) + j] == '#')
			{
				board[i][j] = 1;
			}
		}
	}

	string check;
	for (int j = 0; j < signal.length() / 5; ++j)
	{
		check.clear();
		if (board[0][j] == 1)
		{
			if ( j == 19999 ||(board[0][j + 1] == 0 && board[1][j + 1] == 0 && board[2][j + 1] == 0 && board[3][j + 1] == 0 && board[4][j + 1] == 0))
			{
				result.push_back(1);
				continue;
			}
			else
			{
				for (int k = 0; k < 3; ++k)
				{
					for (int l = 0; l < 5; ++l)
					{
						if (board[0 + l][j + k] == 1)
						{
							check += "1";
						}
						else
						{
							check += "0";
						}
					}
				}
				if (check == "111111000111111")
				{
					result.push_back(0);
					j += 2;
					continue;
				}
				else if (check == "101111010111101")
				{
					result.push_back(2);
					j += 2;
					continue;
				}
				else if (check == "101011010111111")
				{
					result.push_back(3);
					j += 2;
					continue;
				}
				else if (check == "111000010011111")
				{
					result.push_back(4);
					j += 2;
					continue;
				}
				else if (check == "111011010110111")
				{
					result.push_back(5);
					j += 2;
					continue;
				}
				else if (check == "111111010110111")
				{
					result.push_back(6);
					j += 2;
					continue;
				}
				else if (check == "100001000011111")
				{
					result.push_back(7);
					j += 2;
					continue;
				}
				else if (check == "111111010111111")
				{
					result.push_back(8);
					j += 2;
					continue;
				}
				else if (check == "111011010111111")
				{
					result.push_back(9);
					j += 2;
					continue;
				}
			}
		}
	}
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i];
	}
}