#include <iostream>
#include <string>
#include <vector>

using namespace std;

char table[30][30];
bool checkTable[30][30];
int countB = 0;

//void ScreenShot(int m, int n)
//{
//    cout << '\n';
//    for (int i = 0; i < m; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            cout << table[i][j];
//        }
//        cout << '\n';
//    }
//}

void Gravity(int m, int n)
{
    for (int j = 0; j < n ; ++j)
    {
        int countX = 0;
        for (int i = 0; i < m; ++i)
        {
            if (table[m-1-i][j] != 'X' && table[m-1-i][j] != 0)
            {
                table[m-1 - countX][j] = table[m-1 - i][j];
                if (countX != i)
                {
                    table[m - 1 - i][j] = 'X';
                }
                ++countX;
            }
        }
    }
}

void Explosion(int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (checkTable[i][j])
            {
                ++countB;
                table[i][j] = 'X';
                checkTable[i][j] = false;
            }
        }
    }
}

void Check(int a, int b)
{
    if (table[a][b] == table[a + 1][b] && table[a][b] == table[a][b + 1] && table[a][b] == table[a + 1][b + 1]&& table[a][b] != 'X' && table[a][b] != 0)
    {
        checkTable[a][b] = true;
        checkTable[a+1][b] = true;
        checkTable[a][b+1] = true;
        checkTable[a+1][b+1] = true;
    }
}

int main(int m, int n, vector<string> board)
{
    /*int m;
    int n;
    vector<string> board;
    string temp;
    cin >> m >> n;

    for (int i = 0; i < m; ++i)
    {
        cin >> temp;
        board.push_back(temp);
    }*/

    /*
    6
    6
    TTTANT
    RRFACC
    RRRFCC
    TRRRAA
    TTMMMF
    TMMTTJ
    */

    int answer = 0;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            table[i][j] = board[i][j];
        }
    }

    bool proceeding = true;

    while (proceeding)
    {
        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                Check(i, j);
            }
        }

        proceeding = false;

        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                if (checkTable[i][j])
                {
                    proceeding = true;
                }
            }
        }
        Explosion(m, n);
        //ScreenShot(m, n);
        Gravity(m, n);
        //ScreenShot(m, n);
    }

    answer = countB;
    return answer;
}