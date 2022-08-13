
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    private static int[] dx = {1,0,-1,0};
    private static int[] dy = {0,-1,0,1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[][] graph = new char[n][n];
        for(int i = 0; i < n ; i++){
           graph[i] = br.readLine().toCharArray();
        }
        boolean[][] isVisited = new boolean[n][n];
        boolean[][] isBlindVisited = new boolean[n][n];
        int normal = 0;
        int blindness = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                if(!isVisited[i][j]){
                    isVisited[i][j]=true;
                    bfs(new Node(i,j),graph,isVisited,false);
                    normal++;
                }
                if(!isBlindVisited[i][j]){
                    isBlindVisited[i][j] = true;
                    bfs(new Node(i,j),graph,isBlindVisited,true);
                    blindness++;
                }
            }
        }
        System.out.printf("%d %d",normal,blindness);
    }
    private static void bfs(Node startNode, char[][] graph , boolean[][] isVisited , boolean isBlindness){
        Queue<Node> queue = new LinkedList<>();
        queue.add(startNode);
        while (!queue.isEmpty()){
            Node curr = queue.poll();
            char color = graph[curr.x][curr.y];
            for(int i = 0; i < 4 ; i++){
                int posX = curr.x + dx[i];
                int posY = curr.y + dy[i];
                if(posX >= 0 && posX < graph.length && posY >=0 && posY < graph.length && !isVisited[posX][posY]){
                    if(isSameRegion(color,graph[posX][posY],isBlindness)){
                        isVisited[posX][posY] = true;
                        queue.add(new Node(posX,posY));
                    }
                }
            }
        }
    }
    private static boolean isSameRegion( char input , char target , boolean isBlindness){
        if(!isBlindness || input =='B' || target =='B'){
            return input == target;
        }
        return true;

    }

    private static class Node{
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

}
