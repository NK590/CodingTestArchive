#include <iostream>

using namespace std;

int A;
int B;
int N;
int M;

int ground[100][100];

int main()
{
	cin >> B >> A >> N >> M;

	for (int i = 0; i < B; ++i)
	{
		ground[A][i] = -1;
	}

	for (int i = 0; i < A; ++i)
	{
		ground[i][B] = -1;
	}

	pair<pair<int, int>, int> robot[102];

	int temp1;
	int temp2;
	char temp3;
	for (int i = 1; i < N+1; ++i)
	{
		cin >> temp1 >> temp2 >> temp3;
		robot[i].first.first = A - temp2;
		robot[i].first.second = temp1 - 1;
		ground[A - temp2][temp1 - 1] = i;
		switch (temp3)
		{
		case 'N':
			robot[i].second = 0;
			break;
		case 'E':
			robot[i].second = 1;
			break;
		case 'S':
			robot[i].second = 2;
			break;
		case 'W':
			robot[i].second = 3;
			break;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int robotNum;
		char order;
		int repeat;

		cin >> robotNum >> order >> repeat;

		for (int j = 0; j < repeat; ++j)
		{
			switch (order)
			{
			case 'F':
				switch (robot[robotNum].second)
				{
				case 0:
					if (ground[robot[robotNum].first.first - 1][robot[robotNum].first.second] == 0)
					{
						robot[robotNum].first.first -= 1;
					}
					else if (ground[robot[robotNum].first.first - 1][robot[robotNum].first.second] == -1)
					{
						cout << "Robot " << robotNum << " crashes into the wall";
						return 0;
					}
					else
					{
						cout << "Robot " << robotNum << " crashes into robot " << ground[robot[robotNum].first.first - 1][robot[robotNum].first.second];
						return 0;
					}
					break;
				case 1:
					if (ground[robot[robotNum].first.first][robot[robotNum].first.second + 1] == 0)
					{
						robot[robotNum].first.second += 1;
					}
					else if (ground[robot[robotNum].first.first][robot[robotNum].first.second + 1] == -1)
					{
						cout << "Robot " << robotNum << " crashes into the wall";
						return 0;
					}
					else
					{
						cout << "Robot " << robotNum << " crashes into robot " << ground[robot[robotNum].first.first][robot[robotNum].first.second + 1];
						return 0;
					}
					break;
				case 2:
					if (ground[robot[robotNum].first.first + 1][robot[robotNum].first.second] == 0)
					{
						robot[robotNum].first.first += 1;
					}
					else if (ground[robot[robotNum].first.first + 1][robot[robotNum].first.second] == -1)
					{
						cout << "Robot " << robotNum << " crashes into the wall";
						return 0;
					}
					else
					{
						cout << "Robot " << robotNum << " crashes into robot " << ground[robot[robotNum].first.first + 1][robot[robotNum].first.second];
						return 0;
					}
					break;
				case 3:
					if (ground[robot[robotNum].first.first][robot[robotNum].first.second - 1] == 0)
					{
						robot[robotNum].first.second -= 1;
					}
					else if (ground[robot[robotNum].first.first][robot[robotNum].first.second - 1] == -1)
					{
						cout << "Robot " << robotNum << " crashes into the wall";
						return 0;
					}
					else
					{
						cout << "Robot " << robotNum << " crashes into robot " << ground[robot[robotNum].first.first][robot[robotNum].first.second - 1];
						return 0;
					}
					break;
				}
				break;
			case 'L':
				robot[robotNum].second = (robot[robotNum].second + 3) % 4;
				break;
			case 'R':
				robot[robotNum].second = (robot[robotNum].second + 1) % 4;
				break;
			}
		}
	}
	cout << "OK";
}