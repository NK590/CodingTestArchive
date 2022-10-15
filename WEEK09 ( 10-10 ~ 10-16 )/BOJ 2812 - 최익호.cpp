#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> myStack;
int n, k;
char c;
string number = "";
string result = "";

void Initalization()
{
	cin >> n >> k;

	int temp = n;
	while (temp > 0)
	{
		cin >> c;
		number.push_back(c);
		temp--;
	}
}


int main()
{
	Initalization();

	myStack.push(number[0]);

	for (int i = 1; i < number.length(); i++)
	{
		if (k == 0)
		{
			myStack.push(number[i]);
			continue;
		}
		

		if (myStack.top() < number[i])
		{

			while (myStack.top() < number[i] && !myStack.empty() && k > 0)
			{
				myStack.pop();
				k--;
				if (myStack.empty())
				{
					break;
				}
			}

			myStack.push(number[i]);
		}
		else if (myStack.top() >= number[i])
		{
			myStack.push(number[i]);
			continue;
		}
	}

	while (k > 0)
	{
		myStack.pop();
		k--;
	}


	while (!myStack.empty())
	{
		result.push_back(myStack.top());
		myStack.pop();
	}



	string resultReverse(result.rbegin(), result.rend());
	cout << resultReverse;
}