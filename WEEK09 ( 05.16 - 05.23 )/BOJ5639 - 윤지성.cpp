#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void postOrder(int start, int end) {
	if (start >= end) //범위 벗어날 경우
		return;
	if (start == end - 1) { //요소 한개만 검사할 경우 출력
		cout << v[start] << '\n';
		return;
	}

	int idx = start + 1; //start 루트노드 다음부터 검사
	while (idx < end) {
		if (v[start] < v[idx]) //오른쪽 노드 나오는 시점을 idx 저장
			break;
		idx++;
	}
	postOrder(start + 1, idx); //좌측 노드 재귀
	postOrder(idx, end); //우측 노드 재귀
	cout << v[start] << '\n'; //루트노드 출력
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tmp;
	while (cin >> tmp) 
		v.push_back(tmp);

	postOrder(0, v.size());

	return 0;
}
