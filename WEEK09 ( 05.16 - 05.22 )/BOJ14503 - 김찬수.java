
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
    static int y,x,count;
    static int map[][];
    static int dy[] = {-1,0,1,0};
    static int dx[] = {0,1,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine(), " ");
        y = Integer.parseInt(stringTokenizer.nextToken());
        x = Integer.parseInt(stringTokenizer.nextToken());
        map = new int[y][x];
        stringTokenizer = new StringTokenizer(br.readLine(), " ");
        int r = Integer.parseInt(stringTokenizer.nextToken());
        int c = Integer.parseInt(stringTokenizer.nextToken());
        int d = Integer.parseInt(stringTokenizer.nextToken()); // 방향 0북 , 1동, 2남, 3서
        count = 1;
        for(int i=0; i<y; i++) {
            stringTokenizer = new StringTokenizer(br.readLine(), " ");
            for(int j=0; j<x; j++) {
                map[i][j] = Integer.parseInt(stringTokenizer.nextToken());
            }
        }
        dfs(r,c,d);
        System.out.println(count);
    }
    public static void dfs(int r, int c, int dir) {
        //현재 위치 청소
        map[r][c] = -1;
        //현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
        for(int i=0; i<4; i++) {
            dir = (dir + 3) % 4; // 왼쪽 방향으로 변환 (북 -> 서 -> 남 -> 동)
            int ny = r + dy[dir];
            int nx = c + dx[dir];
            // 청소가 안된 곳이 있으면 count++, dfs
            if(ny >=0 && ny < y && nx >= 0 && nx < x && map[ny][nx] == 0) {
                count++;
                dfs(ny,nx, dir);
                return;
            }
        }
        // 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는 바라보는 방향을 유지한 채로 한 칸 후진.
        int back = (dir + 2) % 4;
        int by = r + dy[back];
        int bx = c + dx[back];
        if(by>=0 && by<y && bx>=0 && bx<x && map[by][bx] != 1) {
            dfs(by,bx,dir);
        }
    }
}
