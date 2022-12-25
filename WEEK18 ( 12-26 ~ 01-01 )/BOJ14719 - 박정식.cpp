#include <iostream>
#include <vector>

using namespace std;

// 세로 가로
int H, W;
// 맵
int map[501][501];
// 높이 저장 백터
vector<int> v;
// 정답 변수
int result;

void Marking(int selectX, int curX)
{
	int height;
	if (v[selectX] < v[curX])
		height = v[selectX];
	else
		height = v[curX];


	for (int x = selectX; x < curX; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (map[y][x] == 0)
			{
				result++;
				map[y][x] = 2;
			}
		}
	}
}

void Solution()
{
	int selectX = 0;
	for (int x = 1; x < W; x++)
	{
		Marking(selectX, x);

		// 현재 선택된 높이보다 더 높거나 같은 높이를 발견 했다면
		if (v[selectX] <= v[x])
			selectX = x;
	}
	cout << result << endl;
}

void Input()
{
	cin >> H >> W;

	for (int x = 0; x < W; x++)
	{
		int height;
		cin >> height;
		v.push_back(height);
		for (int y = 0; y < height; y++)
		{
			map[y][x] = 1;
		}
	}
}

int main()
{
	Input();
	Solution();
	return 0;
}