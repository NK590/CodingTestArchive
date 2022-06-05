#include <vector>
#include <iostream>

using namespace std;

vector<int> prime(4000001);
vector<int> rprime;
void makePrime(int n) {//에라토스테네스 체
	for (int i = 2; i <= n/2; i++) 
		for (int j = 2; i * j <= n; j++) 
			prime[i * j] = 1;
		
	for (int i = 2; i <= n; i++) 
		if (!prime[i])
			rprime.push_back(i);	
}

int st, en, sum = 2, cnt, n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;

	makePrime(n);
	while (st <= en && en < rprime.size()) {
		if (sum < n){ //목표값보다 작을 때
            if (en == rprime.size() - 1) //끝인덱스가 마지막 인덱스면 종료
				break;
            sum += rprime[++en]; //마지막 아니면 인덱스 증가해서 부분합 추가
        }			
		else if (sum > n) //목표값보다 클 때
			sum -= rprime[st++]; //시작인덱스 증가
		else {
			cnt++; //같으면 횟수 증가
			sum += rprime[++en]; //끝인덱스 증가 처리
			sum -= rprime[st++]; //시작인덱스 증가 처리
		}		
	}
	cout << cnt;

	return 0;
}
