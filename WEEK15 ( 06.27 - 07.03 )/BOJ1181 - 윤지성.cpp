#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp_length(string s1, string s2) {
    if (s1.size() == s2.size()) return s1 < s2;
    else return s1.size() < s2.size();
}

vector<string> v;;
int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    //문자 갯수 작은 순으로 sort
    sort(v.begin(), v.end(), comp_length);

    v.erase(unique(v.begin(), v.end()),v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}
