import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int l = Integer.parseInt(input[1]);
        int r = Integer.parseInt(input[2]);
        int[][] graph = new int[n][n];
        for (int i = 0; i < n; i++) {
            String[] src = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                graph[i][j] = Integer.parseInt(src[j]);
            }
        }
        Queue<Node> queue = new LinkedList<>();
        int day = 0;
        while (true){
            boolean[][] isVisited = new boolean[n][n];
            boolean isPopulationChanged =false;
            for(int i = 0; i < n ; i++){
                for(int  j= 0; j < n ; j++){
                    if(isVisited[i][j]){ //이미 방문한 노드는 재방문하지 않음
                        continue;
                    }
                    Queue<Node> visitedNode = new LinkedList<>(); // 방문노드 큐 (한 연결성분)
                    queue.add(new Node(i,j));
                    isVisited[i][j] = true;
                    int sum = 0;
                    while (!queue.isEmpty()) { //  bfs
                        Node node = queue.poll();
                        sum += graph[node.x][node.y];
                        visitedNode.add(node);
                        for (int k = 0; k < 4; k++) { // 상하좌우 탐색
                            int posX = node.x + dx[k];
                            int posY = node.y + dy[k];
                            if (posX >= 0 && posX < n && posY >= 0 && posY < n && !isVisited[posX][posY]) {
                                int diff = Math.abs(graph[posX][posY] - graph[node.x][node.y]);
                                if (diff >= l && diff <= r) { // 문제의 조건과 일치하다면 방문노드 큐에넣고 방문
                                    isVisited[posX][posY] = true;
                                    queue.add(new Node(posX, posY));
                                }
                            }
                        }
                    }
                    int size = visitedNode.size();
                    if(size>1){ // 2개이상의 노드가 연합이라면 인구이동 시작
                        isPopulationChanged = true; // 인구 이동체크
                        while ( !visitedNode.isEmpty()) {
                            Node node = visitedNode.poll();
                            graph[node.x][node.y] = sum / size;
                        }
                    }
                }
            }
            if(!isPopulationChanged){
                System.out.println(day);
                return;
            }
            day++;
        }
    }
    private static class Node {
        int x;
        int y;
        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }


}
