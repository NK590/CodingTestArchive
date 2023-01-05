#include <iostream>

using namespace std;

// 물건의 개수 N와 가방의 무게 한도 K
int N, K;

// 아이템의 무게를 저장, 아이템의 가치를 저장
int iW[101], iV[101];

// [i][j] 
// i => 물건의 순서 / j => 가방의 무게
int arr[101][100001];

void GetInput()
{
    // 물건의 개수와 가방의 무게 한도 입력 받기
    cin >> N >> K;

    int cnt = 1;
    while (cnt <= N) { // 물건의 무게와 가치를 입력받음
        cin >> iW[cnt] >> iV[cnt];
        cnt++;
    }
}

int main()
{
    GetInput();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - iW[i] >= 0) {  // 가방 한도 - 현재 물건의 무게 
                // 물건을 넣을 수 있는 경우 (위의 연산이 양수)
                
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - iW[i]] + iV[i]);
                // 둘중에서 최대 값을 찾는 함수 max
            }
            else { 
                // 물건을 넣을 수 없는 경우 (위의 연산이 음수)
                arr[i][j] = arr[i - 1][j];
            }
        }
    }

    // 마지막까지 연산한다면 arr[N][K] 값이 최대 가치가 된다.
    cout << arr[N][K];

    return 0;
}