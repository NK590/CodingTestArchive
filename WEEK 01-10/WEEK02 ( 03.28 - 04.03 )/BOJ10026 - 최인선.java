import java.util.*;

public class Main {

    static int[] dx = {0, -1, 0, 1};
    static int[] dy = {1, 0, -1, 0};
    static int n;
    static char board[][];
    static boolean normalvisited[][], rgvisited[][];
    static int normalCount = 0, redgreenCount = 0;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt();
        scan.nextLine();
        board = new char[n][n];
        for(int i = 0; i < n; i++) {
            String str = scan.nextLine();
            for(int j = 0; j < n; j++) {
                board[i][j] = str.charAt(j);
            }
        }

        normalvisited = new boolean[n][n];
        rgvisited = new boolean[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(normalvisited[i][j] == false) {
                    dfs(i, j);
                    normalCount++;
                }
                if(rgvisited[i][j] == false) {
                    redgreendfs(i, j);
                    redgreenCount++;
                }
            }
        }

        System.out.print(normalCount + " " + redgreenCount);
    }

    public static void dfs(int x, int y) {
        normalvisited[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if(normalvisited[nx][ny] == false && board[nx][ny] == board[x][y]) {
                    normalvisited[nx][ny] = true;
                    dfs(nx, ny);
                }
            }
        }
    }

    public static void redgreendfs(int x, int y) {
        rgvisited[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if(rgvisited[nx][ny] == false) {
                    if((board[x][y] == 'R' || board[x][y] == 'G') && (board[nx][ny] == 'R' || board[nx][ny] == 'G')) {
                        rgvisited[nx][ny] = true;
                        redgreendfs(nx, ny);
                    }
                    else if(board[x][y] == board[nx][ny]) {
                        rgvisited[nx][ny] = true;
                        redgreendfs(nx, ny);
                    }
                }
            }
        }
    }
}  