#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*1744*/
int n, tmp, minu, sum;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);

		if (tmp <= 0)
			minu++; //0 ������ �� ���� ����
	}

	sort(v.begin(), v.end()); //�������� ����


	for (int i = 0; i < v.size(); i += 2) {
		if (i + 1 == minu || (v.size() - minu) % 2 == 1 && i == minu) { //0 �����μ� or ����� Ȧ���� �� ó��
			sum += v[i];
			i--;
		}
		else
			sum += (v[i] * v[i + 1] > v[i] + v[i + 1] ? v[i] * v[i + 1] : v[i] + v[i + 1]); //���� vs �ȹ��� ���� ���ϱ�
	}

	cout << sum;

	return 0;
}



