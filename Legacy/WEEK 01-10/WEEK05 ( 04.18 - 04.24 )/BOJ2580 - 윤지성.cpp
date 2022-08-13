/*2580*/
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int sdoku[9][9]; // sdoku ����
vector<pair<int, int>> points; // �� ĭ
int cnt = 0;
bool found = false; // ������ �� �ϼ�����
bool check(pair<int, int> p)
{
	int sqx = p.first / 3; // ������ ����
	int sqy = p.second / 3;
	for (int i = 0; i < 9; i++)
	{
		if (sdoku[p.first][i] == sdoku[p.first][p.second] && i != p.second)
			return false; // ���� �࿡ ���� ���ڰ� ������ false ��ȯ
		if (sdoku[i][p.second] == sdoku[p.first][p.second] && i != p.first)
			return false; // ���� ���� ���� ���ڰ� ������ false ��ȯ
	}
	for (int i = 3 * sqx; i < 3 * sqx + 3; i++)
		for (int j = 3 * sqy; j < 3 * sqy + 3; j++)
		{
			if (sdoku[i][j] == sdoku[p.first][p.second])
			{
				if (i != p.first && j != p.second)
					return false; // ���� ������ ���� ���ڰ� ������ false ��ȯ
			}
		}
	return true; // ��� ���� ������ ���
}
void game(int N) {
	if (N == cnt) // ��ĭ�� ������ŭ�� ä���� ������ ���� �ϼ�
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
		if (check(points[N])) // ����� ��ȿ�ϸ� ���� ��ĭ�� ä�췯 ��
			game(N + 1);
		if (found) // ������ �ϼ��Ǹ� �Լ� ����
			return;
	}
	sdoku[points[N].first][points[N].second] = 0;// �� ��ã���� 0 ����
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
				points.push_back(point); // ��ĭ�� ��ǥ ����
			}
		}
	game(0);
}