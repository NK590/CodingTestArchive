#include <iostream>
using namespace std;

int s = 0;
string n = "";
int numbers[10][7] = 
{
    {1,1,1,0,1,1,1}, //0
    {0,0,1,0,0,1,0}, //1
    {1,0,1,1,1,0,1}, //2
    {1,0,1,1,0,1,1}, //3
    {0,1,1,1,0,1,0}, //4
    {1,1,0,1,0,1,1}, //5
    {1,1,0,1,1,1,1}, //6
    {1,0,1,0,0,1,0}, //7
    {1,1,1,1,1,1,1}, //8
    {1,1,1,1,0,1,1}, //9
};

void monitor(char c, int idx) 
{
    int x = c - '0';
    if (idx % 3 == 0) 
    {
        cout << " ";
        if (numbers[x][idx] == 1) 
        { 
            for (int i = 0; i < s; i++) 
                cout << "-"; 
        }
        else 
        { 
            for (int i = 0; i < s; i++) 
                cout << " "; 
        }
        cout << "  ";
    }
    else 
    {
        if (numbers[x][idx] == 1) 
        { 
            cout << "|"; 
        }
        else 
            cout << " ";
        if (idx % 3 == 1) 
        { 
            for (int i = 0; i < s; i++)
                cout << " "; 
        }
        else 
            cout << " ";
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> n;
    // 1번쨰 라인
    for (int j = 0; j < n.size(); j++) 
    { 
        monitor(n[j], 0); 
    }
    cout << "\n";
    // 2번째 라인
    for (int a = 0; a < s; a++) 
    {
        for (int j = 0; j < n.size(); j++) 
        { 
            for (int i = 1; i < 3; i++) 
            {
                monitor(n[j], i); 
            }
        }
        cout << "\n";
    }
    // 3번째 라인
    for (int j = 0; j < n.size(); j++) 
    {
        monitor(n[j], 3); 
    }
    cout << "\n";
    // 4번째 라인
    for (int a = 0; a < s; a++) 
    {
        for (int j = 0; j < n.size(); j++) 
        {
            for (int i = 4; i < 6; i++) 
            {
                monitor(n[j], i); 
            }
        }
        cout << "\n";
    }
    // 5번째 라인
    for (int j = 0; j < n.size(); j++) 
    {
        monitor(n[j], 6); 
    }
    return 0;
}