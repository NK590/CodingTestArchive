/*2580*/
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int sdoku[9][9]; // sdoku 보드
vector<pair<int, int>> points; // 빈 칸
int cnt = 0;
bool found = false; // 스도쿠 판 완성여부
bool check(pair<int, int> p)
{
	int sqx = p.first / 3; // 구역을 나눔
	int sqy = p.second / 3;
	for (int i = 0; i < 9; i++)
	{
		if (sdoku[p.first][i] == sdoku[p.first][p.second] && i != p.second)
			return false; // 같은 행에 같은 숫자가 있으면 false 반환
		if (sdoku[i][p.second] == sdoku[p.first][p.second] && i != p.first)
			return false; // 같은 열에 같은 숫자가 있으면 false 반환
	}
	for (int i = 3 * sqx; i < 3 * sqx + 3; i++)
		for (int j = 3 * sqy; j < 3 * sqy + 3; j++)
		{
			if (sdoku[i][j] == sdoku[p.first][p.second])
			{
				if (i != p.first && j != p.second)
					return false; // 같은 구역에 같은 숫자가 있으면 false 반환
			}
		}
	return true; // 모든 조건 만족시 통과
}
void game(int N) {
	if (N == cnt) // 빈칸의 개수만큼을 채워서 스도쿠 판이 완성
	{
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << sdoku[i][j] << ' ';
			cout << '\n';
		}
		found = true; // 
		return;
	}
	for (int j = 1; j <= 9; j++)
	{
		sdoku[points[N].first][points[N].second] = j;
		if (check(points[N])) // 결과가 유효하면 다음 빈칸을 채우러 감
			game(N + 1);
		if (found) // 스도쿠가 완성되면 함수 종료
			return;
	}
	sdoku[points[N].first][points[N].second] = 0;// 값 못찾으면 0 만듬
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	pair<int, int> point;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> sdoku[i][j];
			if (sdoku[i][j] == 0)
			{
				cnt++;
				point.first = i;
				point.second = j;
				points.push_back(point); // 빈칸의 좌표 저장
			}
		}
	game(0);
}