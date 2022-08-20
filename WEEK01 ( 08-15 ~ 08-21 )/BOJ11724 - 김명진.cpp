#include <vector>;
#include <stack>;
#include <iostream>;

using namespace std;

int v, e; //v: 정점의 갯수 e: 간선의 갯수

vector<int> adj[1000]; //adj는 1차원 배열로 요소로는 int가 들어가는 vector 데이터 형식.
int vis[1000]; //vis는 int가 들어가는 1차원 배열

int dfs()
{
    int ret = 0;
    stack<int> s;

    for (int i = 1; i <= v; i++) //v : 정점의 갯수(이미 6으로 입력 받음), 6만큼 반복
    {
        if (vis[i]) continue; //int는 기본값으로 null이 아닌 0값을 갖고 vis[i]가 비어있지 않으면( vis[i]가 true면 ) for문을 한턴 넘김

        ret++; //component의 갯수

        s.push(i); //1을 집어넣음

        vis[i] = true; //정점1을 방문했다고 vis에 표시함

        while (!s.empty()) //스택이 비어있지 않다면 -> 스택에 요소가 있다면
        {
            int cur = s.top(); //1을 cur에 넣음

            s.pop(); //1을 스택에서 꺼냄

            for (int j = 0; j < adj[cur].size(); j++) //정점1의 vector.size 만큼 반복함 1의 경우는 2번(2와연결, 5와연결) 반복함
            {
                int nxt = adj[cur][j]; //정점[1]의[0] 즉 2가 nxt에 들어감
                if (vis[nxt]) continue; //vis[2]는 false이므로 메서드가 계속 진행됨

                s.push(nxt); //스택에 2를 넣고

                vis[nxt] = true; // 2를 방문했다고 vis[2] 값에 남김
            }

        }

    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); //c입력스트림과 c++입력 스트림을 끊는 메서드, 사용하는 버퍼수를 줄여 더 빠른 cin cout를 실행하기 위한 설정 printf,scanf 사용불가
    cin.tie(0); //cin과 cout의 묶음을 풀어주는 메서드, 기본적으로 cout와 cin은 서로의 스트림이 작업을 진행하기전 버퍼를 비워줌을 보장하는데 그것을 해제함.
    //cin과 cout의 실행속도는 빨라지지만 cout와 cin메서드를 이어서 작성할 경우 cout가 버퍼에 추가된상태로 cin이 실행되면서 출력이 되지않는 경우가 생길 수 있다.

    cin >> v >> e; //cin은 공백단위로 입력받기에 v에는 6 e에는 5가 들어간다.

    int x, y;

    while (e--) //vector[] => adj를 이용하여 그래프를 만드는 반복문 e는 int 5기때문에 5,4,3,2,1 (0은 false) 총 5번 실행된다
    {
        cin >> x >> y;  //공백단위로 입력을 받기때문에 처음엔 1과 2가 x와 y에 각각 들어간다
        adj[x].push_back(y); //vector 데이터 형식에 1인 x의 뒤에 2인 y가 들어가고
        adj[y].push_back(x); //vector 데이터 형식인 2인 y의 뒤에 1인 x가 들어간다 방향성이 없는 그래프라 두번 작성해주는 모습
    }
    cout << dfs(); //다 만들어진 그래프를 통해 dfs를 실행한다.

    return 0;
}