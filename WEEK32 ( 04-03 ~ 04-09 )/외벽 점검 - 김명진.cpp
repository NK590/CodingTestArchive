#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) 
{
    int answer = 0;

    vector<int> answerSheet;
    int tempA = weak.size();
    for (int i = 0; i < tempA-1; ++i)
    {
        weak.push_back(weak[i] + n);
    }

    sort(dist.begin(), dist.end());
    do
    {
        for (int i = 0; i < tempA; ++i)
        {
            int tempB = 0;
            for (int j = 0; j < dist.size(); ++j)
            {
                int cur = weak[i+tempB];
                cur += dist[j];
                while (cur >= weak[i + tempB] && i+tempB< weak.size()-1)
                {
                    ++tempB;
                }
                if (tempB >= tempA)
                {
                    answerSheet.push_back(++j);
                }
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));

    if (answerSheet.size() > 0)
    {
        sort(answerSheet.begin(), answerSheet.end());
        answer = answerSheet[0];
    }
    else
    {
        return -1;
    }
    return answer;
}

int main()
{
}