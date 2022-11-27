#include <iostream>

using namespace std;

int R, C;
int board[20][20];
string inputTemp;
bool visited[91];
int dirX[] = { 0,0,-1,1 };
int dirY[] = { -1,1,0,0 };
int ans;

void Reset()
{
	for (int i = 65; i < 91; i++)
	{
		visited[i] = false;
	}
}

void Alphabet(int Y, int X, int cnt)
{
	visited[board[Y][X]] = true;
	for (int i = 0; i < 4; i++)
	{
		if (Y + dirY[i] >= 0 && Y + dirY[i] <= R-1 && X + dirX[i] >= 0 && X + dirX[i] <= C-1)
		{
			if (!visited[board[Y + dirY[i]][X + dirX[i]]])
			{
				Alphabet(Y + dirY[i], X + dirX[i], cnt + 1);
			}
		}
	}
	visited[board[Y][X]] = false;

	if (cnt > ans)
	{
		ans = cnt;
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		cin >> inputTemp;
		for (int j = 0; j < C; j++)
		{
			board[i][j] = (int)inputTemp[j];
		}
	}
	Reset();
	Alphabet(0, 0, 1);
	cout << ans;
}