#include <iostream>

using namespace std;

int table[14];
int N,ans;

bool Check(int y)
{
    for (int i = 0; i < y; i++)
    {                                   //table[y], table[i] = x좌표를 의미   //y,i는 y좌표를 의미  //y의 증가량과 x의 증가량이 같다는 소리는 => 기울기가 -1 또는 1 (대각선)
        if (table[i] == table[y] || abs(table[y] - table[i]) == y - i)
            return false;
    }
    return true;
}

void NQueen(int y)
{
    if (y == N)
    {
        ans++;
    }
    else
    {
        for (int x = 0; x < N; x++)
        {
            table[y] = x; //Y번째줄(Y번째퀸을 해당x좌표에 배치)
            if (Check(y))
            { 
                NQueen(y + 1);
            }
        }
    }
}
int main() {
    cin >> N;
    NQueen(0);
    cout << ans;
}