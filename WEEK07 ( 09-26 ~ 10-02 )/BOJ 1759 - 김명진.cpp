#include <iostream>
#include <list>

using namespace std;

int L, C;
list<char> lInput;
char sortInput[15];
int password[15];

void Password(int n, int usableIdx, int cnt)
{
	int temp;
	if (n == L)
	{
		if (password[L - 1] >= L - 1)
		{
			if (cnt >= 1 && L - cnt >= 2)
			{
				for (int i = 0; i < L; i++)
				{
					temp = password[i];
					cout << sortInput[temp];
				}
				cout << "\n";
			}
		}
	}
	else
	{
		for (int i = usableIdx; i < C; i++)
		{
			password[n] = i;
			if (sortInput[i] == 'a' || sortInput[i] == 'e' || sortInput[i] == 'i' || sortInput[i] == 'o' || sortInput[i] == 'u')
			{
				Password(n + 1, i + 1, cnt+1);
			}
			else
			{
				Password(n + 1, i + 1, cnt);
			}
		}
	}
}

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char temp;
		cin >> temp;
		lInput.push_back(temp);
	}
	lInput.sort();
	for (int i = 0; i < C; i++)
	{
		char temp;
		temp = lInput.front();
		sortInput[i] = temp;
		lInput.pop_front();
	}
	Password(0, 0, 0);
}