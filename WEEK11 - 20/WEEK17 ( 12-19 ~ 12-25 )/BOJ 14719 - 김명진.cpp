#include <iostream>

using namespace std;

int H, W;
bool board[501][501];


int main(void)
{
    cin >> H >> W;
    for (int i = 0; i < W; ++i)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; ++j)
        {
            board[i][j] = true;
        }
    }

    int Answer = 0;
    for (int i = 0; i < H; ++i)
    {
        int left = -1;
        int right = -1;
        int count = 0;
        for (int j = 0; j < W; ++j)
        {
            if (board[j][i])
            {
                ++count;
                if (left == -1)
                {
                    left = j;
                }
                else
                {
                    right = j;
                }
            }
        }

        if (left != -1 && right != -1)
        {
            Answer += right - left - (count - 1);
        }
    }

    cout << Answer;
}