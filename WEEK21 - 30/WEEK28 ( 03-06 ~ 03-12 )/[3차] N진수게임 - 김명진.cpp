#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n, int t, int m, int p)
{
    string answer = "";

    string board = "0123456789ABCDEF";
    int standardNum = 0; //10진수로 표시하는 기준숫자
    int numLength = 1;   //기준숫자를 N진수로 변환했을때 자릿수
    int orderNum = 0;    //현재 누구의 차례인지 확인하는 숫자
    int foundNum = 0;    //찾아낸 숫자 갯수
    
    while (foundNum < t)
    {
        if (standardNum >= pow(n, numLength))
        {
            ++numLength;
        }
        int recentNum = standardNum;
        for (int i = 0; i < numLength; ++i)
        {
            int temp = pow(n, numLength - 1 - i);
            if (orderNum % m == p - 1)
            {
                ++foundNum;
                if (foundNum > t) break;
                answer += board[recentNum / temp];
            }
            ++orderNum;
            recentNum = recentNum % temp;
        }
        ++standardNum;
    }
    return answer;
}


int main()
{
    int n, t, m, p;
    cin >> n >> t >> m >> p;
    cout << solution(n, t, m, p);
}