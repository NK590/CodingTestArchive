#define MAX 1000 + 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector<int> v;
int map[MAX];

// 입력 처리
void Input()
{
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		map[temp] = 1;
		v.push_back(temp);
	}
}

int Solution()
{
	// 테이프 사용 개수
	int result = 0;
	sort(v.begin(), v.end());

	//int vSize = v.size();
	for (int i = 0; i < MAX; i++)
	{
		if (map[i] == 1)
		{
			result++;
			for (int j = 0; j < L; j++)
			{
				map[i + j] = 0;
			}
		}
	}
	return result;
}

int main()
{
	Input();
	cout << Solution() << endl;

	return 0;
}