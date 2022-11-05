#include <iostream>

using namespace std;

void PrintEmpty(int s)
{
	for (int i = 0; i < s + 2; ++i)
	{
		cout << " ";
	}
}
void PrintHorizon(int s) 
{
    cout << " ";
    for (int i = 0; i < s; i++) 
    { 
        cout << "-";
    }
    cout << " ";;
}

void PrintVertRight(int s) 
{
    for (int i = 0; i < s + 1; i++) 
    { 
        cout << " "; 
    }
    cout << "|";
}
void PrintVertLeft(int s) 
{
    cout << "|";
    for (int i = 0; i < s + 1; i++) 
    { 
        cout << " "; 
    }
}
void PrintVertBoth(int s) 
{
    cout << "|";
    for (int i = 0; i < s; i++) 
    { 
        cout << " "; 
    }
    cout << "|";
}


void PrintOne(int s, int r) 
{
    if (r == 1 || r == s + 2 || r == 2 * s + 3) PrintEmpty(s);
    else PrintVertRight(s);
}
void PrintTwo(int s, int r)
{
    if (r == 1 || r == s + 2 || r == 2 * s + 3) PrintHorizon(s);
    else if (2 <= r && r <= s + 1) PrintVertRight(s);
    else PrintVertLeft(s);
}
void PrintThree(int s, int r) 
{
    if (r == 1 || r == s + 2 || r == 2 * s + 3) PrintHorizon(s);
    else PrintVertRight(s);
}
void PrintFour(int s, int r) 
{
    if (r == 1 || r == 2 * s + 3) PrintEmpty(s);
    else if (r == s + 2) PrintHorizon(s);
    else if (2 <= r && r <= s + 1) PrintVertBoth(s);
    else PrintVertRight(s);
}
void PrintFive(int s, int r) 
{
    if (r == 1 || r == s + 2 || r == 2 * s + 3) PrintHorizon(s);
    else if (2 <= r && r <= s + 1) PrintVertLeft(s);
    else PrintVertRight(s);
}
void PrintSix(int s, int r) 
{
    if (r == 1 || r == s + 2 || r == 2 * s + 3) PrintHorizon(s);
    else if (2 <= r && r <= s + 1) PrintVertLeft(s);
    else PrintVertBoth(s);
}
void PrintSeven(int s, int r) 
{
    if (r == 1) PrintHorizon(s);
    else if (r == s + 2 || r == 2 * s + 3) PrintEmpty(s);
    else PrintVertRight(s);
}
void PrintEight(int s, int r) 
{
    if (r == 1 || r == s + 2 || r == 2 * s + 3) PrintHorizon(s);
    else PrintVertBoth(s);
}
void PrintNine(int s, int r) 
{
    if (r == 1 || r == s + 2 || r == 2 * s + 3) PrintHorizon(s);
    else if (2 <= r && r <= s + 1) PrintVertBoth(s);
    else PrintVertRight(s);
}
void PrintZero(int s, int r) 
{
    if (r == 1 || r == 2 * s + 3) PrintHorizon(s);
    else if (r == s + 2) PrintEmpty(s);
    else PrintVertBoth(s);
}

int main()
{
	int s;
	string n;
	cin >> s >> n;

    for (int r = 1; r <= 2 * s + 3; ++r)
    {
        for (int i = 0; i < n.length();++i)
        {
            if (n[i] == '1') PrintOne(s, r); 
            else if (n[i] == '2')  PrintTwo(s, r); 
            else if (n[i] == '3')  PrintThree(s, r); 
            else if (n[i] == '4')  PrintFour(s, r); 
            else if (n[i] == '5')  PrintFive(s, r);
            else if (n[i] == '6')  PrintSix(s, r);
            else if (n[i] == '7')  PrintSeven(s, r); 
            else if (n[i] == '8')  PrintEight(s, r); 
            else if (n[i] == '9')  PrintNine(s, r); 
            else if (n[i] == '0')  PrintZero(s, r);

            cout << " ";
        }
        cout << "\n";
    }
}