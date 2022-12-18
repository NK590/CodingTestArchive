#include <iostream>

using namespace std;

int row;
int column;
int second;
int ground[201][201];

void spendTime()
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            if (ground[i][j] < 3)
            {
                ++ground[i][j];
            }
            else
            {
                int dx[3] = { -1, 0,0 };
                int dy[3] = { 0, -1,0 };
                for (int k = 0; k < 3; ++k)
                {
                    if (0 <= i + dx[k] && i + dx[k] <= row && 0 <= j + dy[k] && j + dy[k] <= column)
                    {
                        ground[i + dx[k]][j + dy[k]] = 0;
                    }
                }

                int dx2[2] = { 0,1 };
                int dy2[2] = { 1,0 };
                for (int k = 0; k < 2; ++k)
                {
                    if (0 <= i + dx2[k] && i + dx2[k] <= row && 0 <= j + dy2[k] && j + dy2[k] <= column && ground[i + dx2[k]][j + dy2[k]] != 3)
                    {
                        ground[i + dx2[k]][j + dy2[k]] = -1;
                    }
                }
            }
        }
    }
}

void printResult()
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            if (ground[i][j] == 0)
            {
                cout << '.';
            }
            else
            {
                cout << 'O';
            }
        }
        cout << '\n';
    }
}

int main()
{
    cin >> row >> column >> second;

    string temp;
    for (int i = 0; i < row; ++i)
    {
        cin >> temp;
        for (int j = 0; j < column; ++j)
        {
            if (temp[j] == '.')
            {
                ground[i][j] = 0;
            }
            else
            {
                ground[i][j] = 2;
            }
        }
        temp.clear();
    }

    for (int i = 0; i < second-1; ++i)
    {
        spendTime();
    }
    printResult();
}