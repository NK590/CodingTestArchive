#include <iostream>
#include <string>
#include <vector>

using namespace std;

int m, n;

void RotateKey(vector<vector<int>>& key)
{
    vector<vector<int>> tempKey(m, vector<int>(m,0));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            tempKey[j][m-i-1] = key[i][j];
        }
    }
    key = tempKey;
}

bool CheckBoard(int r, int c ,vector<vector<int>>& key, vector<vector<int>>& myBoard)
{
    bool result = true;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (key[i][j])
            {
                myBoard[r + i][c + j] += 1;
            }
        }
    }


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (myBoard[m-1 + i][m-1+ j] != 1)
            {
                result = false;
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (key[i][j])
            {
                myBoard[r + i][c + j] -= 1;
            }
        }
    }
    return result;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) 
{
    bool answer = true;

    m = key.size();
    n = lock.size();

    vector<vector<int>> myBoard(100, vector<int>(100, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
             myBoard[m - 1 + i][m - 1 + j] = lock[i][j];
        }
    }

    for (int k = 0; k < 4; ++k)
    {
        for (int i = 0; i < (2 * m) + n - 2; ++i)
        {
            for (int j = 0; j < (2 * m) + n - 2; ++j)
            {
                if (CheckBoard(i, j, key, myBoard))
                {
                    return true;
                }
            }
        }
        RotateKey(key);
    }
    return false;
}

int main()
{
}