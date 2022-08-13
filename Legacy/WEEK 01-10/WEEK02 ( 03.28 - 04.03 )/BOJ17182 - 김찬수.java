import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        int[][] graph = new int[n][n];

        for(int i = 0; i < n ; i++){
            String[] src = br.readLine().split(" ");
            for(int j = 0; j < n ; j ++){
                graph[i][j] = Integer.parseInt(src[j]);
            }
        }

        // i 출발노드
        for(int i = 0; i < n ; i++){
            // j 경유노드
            for(int j= 0; j<n ; j++){
                // m 도착노드
                for(int m = 0; m < n ;m++){
                    graph[i][m] = Math.min(graph[i][j] + graph[j][m], graph[i][m]);
                }
            }
        }

        boolean[] visited = new boolean[n];
        dfs(graph,k,0,visited);
        System.out.println(min);
    }

    private static void dfs(int[][] graph , int k , int dis,boolean[] visited){

        if(allVisited(visited)){
            if(min > dis){
                min = dis;
            }
            return;
        }

        for(int i = 0 ; i < graph.length ; i++){
            if(!visited[i]){ //  방문하지 않았다면
                visited[i] = true; 
                dfs(graph,i,dis+graph[k][i],visited); //방문
                visited[i] = false;
            }
        }
    }

    private static boolean allVisited(boolean[] visited) {
        for(int i = 0 ; i < visited.length ; i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
}
