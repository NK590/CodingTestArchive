#include <iostream>
#include <vector>

using namespace std;

enum class eDirection
{
	N, W, S, E
};

eDirection dir = eDirection::N;

int top = 0;
int rightF = 0;
int bottom = 0;
int leftF = 0;

int testNum;
string input;

int Calculate(string input)
{
	pair<int, int> cur = { 0, 0 };

	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == 'F')
		{
			switch (dir)
			{
			case eDirection::N:
				cur.second += 1;
				if (cur.second > top)
				{
					top = cur.second;
				}
				break;
			case eDirection::W:
				cur.first -= 1;
				if (cur.first < leftF)
				{
					leftF = cur.first;
				}
				break;
			case eDirection::S:
				cur.second -= 1;
				if (cur.second < bottom)
				{
					bottom = cur.second;
				}
				break;
			case eDirection::E:
				cur.first += 1;
				if (cur.first > rightF)
				{
					rightF = cur.first;
				}
				break;
			default:
				break;
			}
		}

		else if (input[i] == 'B')
		{
			switch (dir)
			{
			case eDirection::N:
				cur.second -= 1;
				if (cur.second < bottom)
				{
					bottom = cur.second;
				}
				break;
			case eDirection::W:
				cur.first += 1;
				if (cur.first > rightF)
				{
					rightF = cur.first;
				}
				break;
			case eDirection::S:
				cur.second += 1;
				if (cur.second > top)
				{
					top = cur.second;
				}
				break;
			case eDirection::E:
				cur.first -= 1;
				if (cur.first < leftF)
				{
					leftF = cur.first;
				}
				break;
			default:
				break;
			}
		}

		else if (input[i] == 'L')
		{
			dir = (eDirection)(((int)dir + 1) % 4);
		}
		else if (input[i] == 'R')
		{
			dir = (eDirection)(((int)dir + 3) % 4);
		}
	}

	return ((top - bottom) * (rightF - leftF));
}


int main()
{
	cin >> testNum;
	vector<int> result;
	for (int i = 0; i < testNum; ++i)
	{
		cin >> input;
		result.push_back(Calculate(input));
		top = 0;
		bottom = 0;
		rightF = 0;
		leftF = 0;
	}
	
	for (int i = 0; i < testNum; ++i)
	{
		cout << result[i] << "\n";
	}
}