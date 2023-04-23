#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 2e9;
bool selected[8];
vector<int> V;

int Min(int A, int B) { if (A < B) return A; return B; }

bool Cmp(int A, int B) { if (A > B) return true; return false; }

void Check(vector<int> weak, vector<int> dist, int N)
{
    for (int i = 0; i < weak.size() - 1; i++)
    {
        int weakIndex = 0;
        int cnt;
        bool flag = false;

        for (int j = 0; (j < V.size()) && (j + 1 < answer) && (flag == false); j++)
        {
            int end = weak[weakIndex] + dist[V[j]];
            while (end >= weak[weakIndex])
            {
                weakIndex++;
                if (weakIndex == weak.size())
                {
                    cnt = j + 1;
                    flag = true;
                    break;
                }
            }
        }
        if (flag == true) answer = Min(answer, cnt);

        int startValue = weak[0];
        for (int j = 1; j < weak.size(); j++) weak[j - 1] = weak[j];
        weak[weak.size() - 1] = startValue + N;
    }
}

void DFS(int cnt, vector<int> weak, vector<int> dist, int n)
{
    if (cnt == dist.size())
    {
        Check(weak, dist, n);
        return;
    }

    for (int i = 0; i < dist.size(); i++)
    {
        if (selected[i] == true) continue;
        selected[i] = true;
        V.push_back(i);
        DFS(cnt + 1, weak, dist, n);
        V.pop_back();
        selected[i] = false;
    }
}

int solution(int n, vector<int> weak, vector<int> dist)
{
    answer = 2e9;
    sort(dist.begin(), dist.end(), Cmp);
    vector<int> temp = weak;
    for (int i = 0; i < temp.size() - 1; i++)
    {
        int start = temp[0];
        int end = temp[temp.size() - 1];
        if (end - start <= dist[0]) return 1;

        int startValue = temp[0];
        for (int j = 1; j < temp.size(); j++) temp[j - 1] = temp[j];
        temp[temp.size() - 1] = startValue + n;
    }

    DFS(0, weak, dist, n);
    if (answer == 2e9) return -1;
    return answer;
}
