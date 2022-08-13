#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(string s1, string s2) 
{
    // ���̰� ���ٸ� ���� ������ ����
    if (s1.size() == s2.size())
    {
        return s1 < s2;
    }
    // ���� ����� �ٸ��ٸ� ���̰� ª���ͺ��� ����
    else
    {
        return s1.size() < s2.size();
    }
}

int main() 
{
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), compare);

    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 0; i < vec.size(); i++) 
    {
        cout << vec[i] << endl;
    }

    return 0;
}