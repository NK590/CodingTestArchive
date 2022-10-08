#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int L, W, H, N, a, b, cnt, fail;
int cube[20];
vector <pair<int, int>> v; //2의 a승과 그 개수를 저장
void divide(int l, int w, int h, int idx) 
{
	if (l == 0 || w == 0 || h == 0) return;
	for (int i = idx; i < v.size(); i++) 
	{
		if (v[i].second != 0 && l >= v[i].first && w >= v[i].first && h >= v[i].first) 
		{
			v[i].second--;
			cnt++;
			divide(l - v[i].first, w, h, i);
			divide(v[i].first, w - v[i].first, h, i);
			divide(v[i].first, v[i].first, h - v[i].first, i);
			return;
		}
	}
	fail = 1;
}
int main() 
{
	cin >> L >> W >> H >> N;
	for (int i = 0; i < N; i++) 
	{
		cin >> i >> b;
		cube[i] += b;
	}
	for (int i = 19; i >= 0; i--) 
	{
		if (cube[i] != 0) 
		{
			v.push_back(make_pair(pow(2, i), cube[i]));
		}
	}
	divide(L, W, H, 0);
	if (fail) cout << -1;
	else cout << cnt << endl;
	return 0;
}