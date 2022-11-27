#include <iostream>;
#include <stack>;

using namespace std;

int t,m,n,k,ans;
int adj[51][51];
int vis[51][51];
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           adj[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            vis[i][j] = 0;
        }
    }
}

void dfs(int y, int x)
{
    vis[y][x] = 1; //방문기록을 남김

    for (int i = 0; i < 4; i++) //4번반복 순서대로 (0,-1)(0,1)(-1,0)(1,0)이 더해짐
    {
        int nx = x + dx[i];
        int ny = y + dy[i]; //결국 상하좌우 전부

        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue; //만약 배열의 사이즈를 넘어가면 그냥 다음 for문 경우로 넘김

        if (adj[ny][nx] == 1 && vis[ny][nx] == 0) //방문한기록이 없는 배추가 나타나면 dfs재귀로 실행
        {
            dfs(ny, nx);
        }
    }
    //처음 y,x 좌표를 받은 배추에서 dfs로 모든 인접한 배추를 다 찾아서 vis에 기록되면 메서드가 종료됨
}

int main()
{
    ios::sync_with_stdio(0); //c입력스트림과 c++입력 스트림을 끊는 메서드, 사용하는 버퍼수를 줄여 더 빠른 cin cout를 실행하기 위한 설정 printf,scanf 사용불가
    cin.tie(0); //cin과 cout의 묶음을 풀어주는 메서드, 기본적으로 cout와 cin은 서로의 스트림이 작업을 진행하기전 버퍼를 비워줌을 보장하는데 그것을 해제함.
    //cin과 cout의 실행속도는 빨라지지만 cout와 cin메서드를 이어서 작성할 경우 cout가 버퍼에 추가된상태로 cin이 실행되면서 출력이 되지않는 경우가 생길 수 있다.
    
    cin >> t; //테스트케이스 T가 입력되어 들어오고 T는 2차원 배열의 갯수를 정해준다

    for (int i = 0; i < t; i++) //1번째 2차원 배열을 만들기 시작
    {
        ans = 0;    //실제 도출해낼 답 for문 한번당 한번 cout
        cin >> m >> n >> k; //배열의 가로크기, 세로크기, 배추갯수

        reset(); //몇번째 2차원 배열인지 모르니 일단 무조건 초기화

        while (k--) //k:배추갯수가 0이 될때까지 반복
        {
            int x, y;
            cin >> x >> y;
            adj[y][x] = 1; //입력받은 x y로 배추위치에 1값을 넣음
        }

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (adj[i][j] == 1 && vis[i][j] == 0)
                {
                    dfs(i, j); //모든 칸을 체크하면서 방문한적 없는 배추를 하나하나 찾아서 dfs를 진행함
                    ans++; //dfs가 한번 실행될때마다 ans를 증가시킴
                }
            }
        }
        cout << ans << endl;
    }
}