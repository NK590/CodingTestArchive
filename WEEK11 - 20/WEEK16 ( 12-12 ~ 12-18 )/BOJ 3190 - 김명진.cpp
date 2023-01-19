#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[102][102];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() 
{
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < K; i++) 
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 4;
    }

    int L;
    cin >> L;
    vector<pair<int, char>> turnInfo;

    for (int i = 0; i < L; i++) 
    {
        int sec;
        char dir;
        cin >> sec >> dir;
        turnInfo.push_back({ sec, dir });
    }


    int time = 0;
    int dir = 0;
    int index = 0;
    pair<int, int> head = { 1,1 };
    queue<pair<int, int>> snake;
    arr[1][1] = 2;
    snake.push(head);

    while (1) 
    {
        time++;

        head.first += dx[dir];
        head.second += dy[dir];
        int nx = head.first;
        int ny = head.second;

        if (nx > N || ny > N || nx < 1 || ny < 1 || arr[nx][ny] == 2) 
        {
            cout << time;
            return 0;
        }
        else if (arr[nx][ny] == 0) 
        {
            pair<int, int> cur = snake.front();
            snake.pop();
            arr[cur.first][cur.second] = 0;
        }

        
        arr[nx][ny] = 2;
        snake.push({ nx, ny });

        if (time == turnInfo[index].first) 
        {
            if (turnInfo[index].second == 'D') 
            {
                dir = (dir + 1) % 4;
                index++;
            }
            else if (turnInfo[index].second == 'L') 
            {
                dir = (dir + 3) % 4;
                index++;
            }
        }
    }
}