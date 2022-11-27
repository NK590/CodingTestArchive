#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

queue<pair<int, int>> myqueue;
list<pair<int, int>> ::iterator iter;

char map[6][12];
bool check[6][12];
int result = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Initalization()
{
    // 초기화
    for (int j = 0; j <= 11; j++)
    { // 세로
        for (int i = 0; i <= 5; i++)
        { // 가로
            map[i][j] = '.';
            check[i][j] = false;
        }
    }

    for (int y = 0; y <= 11; y++)
    { // 세로
    
        for (int x = 0; x <= 5; x++)
        { // 가로

            cin >> map[x][y];
        }
    }
}

void BFS(int i , int j, char ch)
{
    myqueue.push(make_pair(i, j));
    list<pair<int, int>> mylist;

    while (!myqueue.empty())
    {
        pair<int, int> pair = myqueue.front();
        check[pair.first][pair.second] = true; // 방문 마킹
        mylist.push_back(pair); // 리스트에 넣음 나중에 카운트
        myqueue.pop();

        for (int k = 0; k < 4; k++)
        {
            // 상하 좌우로 검색
            int nx = pair.first + dx[k];
            int ny = pair.second + dy[k];

            // 맵의 범위를 넘어감 // 빈 공간 // 같은 문자가 아닐 경우 넘어감  
            if (nx < 0 || nx > 5 || ny < 0 || ny > 12 || check[nx][ny] == true || map[nx][ny] == '.' || map[nx][ny] != ch)
            {
                continue;
            }

            myqueue.push(make_pair(nx, ny));
        }
    }

    // 만약 연결된 뿌요가 4개 이상이라면 
    if (mylist.size() >= 4)
    {
        for (iter = mylist.begin(); iter != mylist.end(); iter++)
        {
            map[iter->first][iter->second] = '.';
        }

        result++;
    }
}


int main()
{
    Initalization();

    int tempResult = -1;

    while (result != tempResult)
    {
        tempResult = result;

        for (int j = 0; j <= 11; j++)
        { // 세로
            for (int i = 0; i <= 5; i++)
            { // 가로
                if (check[i][j] != true && map[i][j] != '.')
                {
                    BFS(i, j, map[i][j]);
                    // 방문 초기화
                }
            }
        }

        for (int x = 0; x <= 5; x++)
        {
            string tempStr = "";
            for (int y = 0; y <= 11; y++)
            {
                if (map[x][y] != '.')
                {
                    tempStr.push_back(map[x][y]);
                }
            }
            string temp2;
            for (int temp = 11 - tempStr.size(); temp >= 0; temp--)
            {
                temp2.push_back('.');
            }

            tempStr = temp2 + tempStr;

            for (int y = 0; y <= 11; y++)
            {
                map[x][y] = tempStr[y];
            }
        }

        for (int j = 0; j <= 11; j++)
        { // 세로
            for (int i = 0; i <= 5; i++)
            { // 가로
                check[i][j] = false;
            }
        }

        if (tempResult != result)
        {
            result = tempResult + 1;
        }

    }

    cout << result;

    return 0;
}