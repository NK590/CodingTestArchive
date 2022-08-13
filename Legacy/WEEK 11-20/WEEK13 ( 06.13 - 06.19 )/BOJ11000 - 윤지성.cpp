#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<>> pq;
vector<pair<int, int>> v;


int main() {

    int N, s, t;
    cin >> N;

    v.assign(N, {0, 0});

    for (int i = 0; i < N; i++) {
        cin >> s >> t;
        v[i] = {s, t};
    }

    sort(v.begin(), v.end());

    int ans = 1; //최초는 넣어두기
    pq.push(v[0].second);

    for (int i = 1; i < N; i++) {

        if (pq.top() > v[i].first) {
            ans++;//새로운 교실이 필요
        } else {
            pq.pop();//새로운 교실 필요 x 
        }
        pq.push(v[i].second);//배치완료이므로 배치 완료된 집단에 넣어줘야함

    }

    cout << ans;


}
