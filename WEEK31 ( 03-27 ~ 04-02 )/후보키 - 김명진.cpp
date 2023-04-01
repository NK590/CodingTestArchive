#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string sArray[20][8];
int myRow;
int myColumn;

int DuplicationCompare(int a)
{
    vector<int> c;
    for (int i = 0; i < myColumn; ++i)
    {
        if (a % 2 == 1)
        {
            c.push_back(i);
        }
        a /= 2;
    }

    for (int i = 0; i < myRow; ++i)
    {
        for (int j = 0; j < myRow - 1 - i; ++j)
        {
            string target = "";
            string controlG = "";
            for (int k = 0; k < c.size(); ++k)
            { 
                target += sArray[i][c[k]];
                controlG += sArray[i + j + 1][c[k]];
            }
            if (target.compare(controlG) == 0)
            {
                return -1;
            }
        }
    }
    return 0;
}

int CountNumOfOne(int a)
{
    int result = 0;
    for (int i = 0; i < myColumn; ++i)
    {
        if (a & (1 << i))
        {
            ++result;
        }
    }
    return result;
}

//vector<int> a에 관하여 a의 모든 요소의 조합을 찾는 메서드
vector<vector<int>> myCombinations(vector<int>& a)
{
    int n = a.size();
    int numOfCom = (1 << n);
    //모든 조합의 갯수가 2^n인 이유는 예를 들어 n이 3이라고 했을 때
    //a[0], a[1], a[2]라는 요소개 세개 있을 테고 각각의 요소를 선택하거나 선택안하거나
    //2가지 경우에 대해 n번 씩 곱으로 적용됨으로 2^n이다.
    //001은 a[2], a[1]은 선택하지 않고 a[0]은 선택한 경우이고
    //010, 011, 100, 101, 110, 111 도 모두 같다.

    vector<vector<int>> result;
    for (int i = 0; i < numOfCom; ++i) 
    {
        vector<int> temp;
        for (int j = 0; j < n; ++j)
        {
            //이게 무슨 뜻이냐면 j는 0,1,2에서 돌아다님(a의 인덱스를 의미)
            //if문은 ()내의 값이 숫자 0 이 아니면 true로 판단하기 때문에 
            //i는 001, 010, 011 이런식으로 각 자리의 요소마다 하나씩 선택을 할 것이고
            //j가 만약 해당 요소에 해당된다면, a[j]를 temp라는 vector에 넣는 것이다.
            //예시로, a가 [{1}, {2}, {3}]이고, i가 3, 즉 011이라면, j가 0인경우, 1인경우
            //두경우 모두 true로 해당되어 a[0] = 1, a[1] = 2 가 temp vector에 들어갈 것이다.
            if (i & (1 << j)) 
            {
                temp.push_back(a[j]);
            }
        }
        result.push_back(temp);
    }
    return result;
}

int solution(vector<vector<string>> relation)
{
    int answer = 0;

    myRow = relation.size();
    myColumn = relation.front().size();

    for (int i = 0; i < myRow; ++i)
    {
        for (int j = 0; j < myColumn; ++j)
        {
            sArray[i][j] = relation[i][j];
        }
    }

    vector<int> candidate;
    for (int i = 1; i < (1 << myColumn); ++i)
    {
        if (DuplicationCompare(i) == 0)
        {
            candidate.push_back(i);
        }
    }

    vector<int> answerSheet;
    for (int i = 0; i < myColumn; ++i)
    {
        for (int j = 0; j < candidate.size(); ++j)
        {
            if (CountNumOfOne(candidate[j]) == i + 1)
            {
                answerSheet.push_back(candidate[j]);
            }
        }
    }

    for (int i = 0; i < answerSheet.size(); ++i)
    {
        for (int j = i + 1; j < answerSheet.size(); ++j)
        {
            if ((answerSheet[i] & answerSheet[j]) == answerSheet[i])
            {
                answerSheet.erase(answerSheet.begin() + j);
                --j;
            }
        }
    }

    answer = answerSheet.size();

    return answer;
}

int main()
{
    vector<vector<string>> relation;
    solution(relation);
}