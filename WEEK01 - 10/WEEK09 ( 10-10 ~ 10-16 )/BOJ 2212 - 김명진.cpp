#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    K = min(K, N);
    vector<int> V(N), W(N - 1);

    for (int i = 0; i < N; i++)
    {
        cin >> V[i]; //각 센서의 좌표
    }

    sort(V.begin(), V.end());

    for (int i = 1; i < N; i++)
    {
        W[i - 1] = V[i] - V[i - 1]; //각 센서사이의 거리 값
    }

    sort(W.begin(), W.end(), greater<int>()); //센서 사이의 거리가 큰 순으로 정렬

    int sum = 0;

    for (int i = 0; i < K - 1; i++)
    {
        sum += W[i];    //K개의 집중국을 설치하면 K-1개의 빈공간을 만들 수 있음
    }

    cout << V.back() - V[0] - sum << "\n"; //처음부터 끝까지 거리에서 빈공간을 빼줌
}