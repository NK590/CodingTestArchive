#include<iostream>
#include<queue>
#include<string>
#include<set>

using namespace std;

queue<pair<int, string>> myqueue;
bool checkset[10000];
queue<string> rstQ;

int A, B, T; // A에서 B로 변환 / T Test 케이스의 수

int OrderD(int number)
{
	int result = number * 2;
	if (result >= 10000)
	{
		result = result % 10000;
	}
	return result;
}

int OrderS(int number)
{
	int result = number - 1;
	if (result <= -1)
	{
		result = 9999;
	}
	return result;
}

int OrderL(int number)
{
	int d4 = number % 10;
	int d3 = ((number % 100) - d4) / 10;
	int d2 = ((number % 1000) - (d3 + d4)) / 100;
	int d1 = (number - (d2 + d3 + d4)) / 1000;
	int result = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
	return result;
}

int OrderR(int number)
{
	int d4 = number % 10;
	int d3 = ((number % 100) - d4) / 10;
	int d2 = ((number % 1000) - (d3 + d4)) / 100;
	int d1 = (number - (d2 + d3 + d4)) / 1000;
	int result = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
	return result;
}

string BFS()
{
	myqueue.push({ A, ""});

	while (!myqueue.empty())
	{
		int currentInt = myqueue.front().first;
		string currentStr = myqueue.front().second;
		myqueue.pop();

		if (currentInt == B)
		{
			return currentStr;
		}
		
		for (int i = 0; i < 4; i++)
		{
			int nextint;
			string nextStr = currentStr;

			switch (i)
			{
				case 0: 
					nextint = OrderD(currentInt);
					nextStr.push_back('D');
					break;

				case 1:
					nextint = OrderS(currentInt);
					nextStr.push_back('S');
					break;

				case 2:
					nextint = OrderL(currentInt);
					nextStr.push_back('L');
					break;

				case 3:
					nextint = OrderR(currentInt);
					nextStr.push_back('R');
					break;

				default:
					break;
			}

			if (checkset[nextint] == false)
			{
				myqueue.push({ nextint, nextStr});
				checkset[nextint] = true;
			}
		}
	}
}

int main()
{
	cin >> T;
	for (T <= 0; T--;)
	{
		cin >> A >> B;

		string result = BFS();
		rstQ.push(result);

		while (!myqueue.empty())
		{
			myqueue.pop();
		}
		for (int i = 0; i < 10000; i++)
		{
			checkset[i] = false;
		}
	}

	while (!rstQ.empty())
	{
		cout << rstQ.front() << "\n";
		rstQ.pop();
	}

	return 0;
}