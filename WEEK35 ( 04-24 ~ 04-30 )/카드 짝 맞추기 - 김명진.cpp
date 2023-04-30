#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<pair<int, int>>> OrganizePair(vector<pair<pair<int, int>, pair<int, int>>> &temp)
{
    vector<vector<pair<int, int>>> results;

    for (int i = 0; i < pow(2, temp.size()); ++i)
    {
        do
        {
            vector<pair<int, int>> tempA;
            for (int j = temp.size(); j > 0; --j)
            {
                if ((i >> j) & 1)
                {
                    tempA.push_back(temp[temp.size() - j].first);
                    tempA.push_back(temp[temp.size() - j].second);
                }
                else
                {
                    tempA.push_back(temp[temp.size() - j].second);
                    tempA.push_back(temp[temp.size() - j].first);
                }
            }
            results.push_back(tempA);
        } while (next_permutation(temp.begin(), temp.end()));
    }

    return results;
}

bool InRange(int x, int y)
{
    return (0 <= x && x < 4 && 0 <= y && y < 4);
}

pair<int, int> FindNext(int dir, int x, int y, vector<vector<int>> &board)
{
    vector<pair<int, int>> nextDir = { {1,0},{0,1},{-1,0},{0,-1} };

    if (dir < 4)
    {
        return { x + nextDir[dir].first, y + nextDir[dir].second };
    }
    else 
    {
        dir -= 4;
        while (InRange(x + nextDir[dir].first, y + nextDir[dir].second))
        {
            x += nextDir[dir].first;
            y += nextDir[dir].second;
            if (board[x][y])
            {
                break;
            }
        }
        return { x,y };
    }
}

int BFS(pair<int, int> start, pair<int, int> end, vector<vector<int>>& board)
{
    queue<pair<pair<int, int>, int>> que;
    vector<vector<bool>> visited(4, vector<bool>(4, false));

    que.push({ start, 0 });
    visited[start.first][start.second] = true;

    while (!que.empty())
    {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int level = que.front().second;
        que.pop();

        for (int i = 0; i < 8; ++i)
        {
            pair<int, int> nextCard = FindNext(i, x, y, board);
            int nextX = nextCard.first;
            int nextY = nextCard.second;
            if (InRange(nextX, nextY) && !visited[nextX][nextY])
            {
                visited[nextX][nextY] = true;
                if (nextX == end.first && nextY == end.second)
                {
                    return level + 1;
                }
                que.push({ { nextX,nextY }, level + 1 });
            }
        }
    }
    return 20000;
}

int solution(vector<vector<int>> board, int r, int c)
{
    int answer = 0;

    vector<pair<pair<int, int>, pair<int, int>>> cardInfo(7);
    vector<bool>duplicationCheck(7, false);

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j])
            {
                if (!duplicationCheck[board[i][j]])
                {
                    cardInfo[board[i][j]].first = make_pair(i, j);
                    duplicationCheck[board[i][j]] = true;
                }
                else
                {
                    cardInfo[board[i][j]].second = make_pair(i, j);
                }
            }
        }
    }

    vector<pair<pair<int, int>, pair<int, int>>> temp;
    for (int i = 0; i < 7; ++i)
    {
        if (duplicationCheck[i])
        {
            temp.push_back(cardInfo[i]);
        }
    }

    vector<vector<pair<int, int>>> organizedPair = OrganizePair(temp);

    vector<int> candidates;

    for (int i = 0; i < organizedPair.size(); ++i)
    {
        organizedPair[i].insert(organizedPair[i].begin(), make_pair(r,c));
        int tempI = 0;
        for (int j = 0; j < organizedPair[0].size() -1; ++j)
        {
            tempI += BFS(organizedPair[i][j], organizedPair[i][j + 1], board);
        }
        candidates.push_back(tempI);
    }

    answer = *min_element(candidates.begin(), candidates.end());

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}