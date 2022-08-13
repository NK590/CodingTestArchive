import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine(), " ");
        int a = Integer.parseInt(stringTokenizer.nextToken());
        int b = Integer.parseInt(stringTokenizer.nextToken());
        int c = Integer.parseInt(stringTokenizer.nextToken());
        int sum = a+b+c;
        boolean[][] visited = new boolean[sum+1][sum+1];
        bfs(new Node(a,b),visited,sum);
    }

    private static void bfs(Node node, boolean[][] visited,int sum) {

        Queue<Node> queue = new LinkedList<>();
        queue.add(node);
        while (!queue.isEmpty()){
            Node curr = queue.poll();
            int a = curr.a ; int b = curr.b ; int c = sum - a - b;
            if(a == b && b == c){
                System.out.print(1);
                return;
            }
            if(a < b && !visited[a*2][b-a]){
                visited[a*2][b-a] = true;
                queue.add(new Node(a*2,b-a));
            }else if (a>b &&  !visited[a-b][b*2]){
                visited[a-b][b*2] = true;
                queue.add(new Node(a-b,b*2));
            }
            if(a<c && !visited[a*2][c-a]){
                visited[a*2][c-a] = true;
                queue.add(new Node(a*2,c-a));
            }else if (a>c && !visited[a-c][c*2] ){
                visited[a-c][c*2] = true;
                queue.add(new Node(a-c,c*2));
            }
            if(b < c &&  !visited[b*2][c-b]){
                visited[b*2][c-b] = true;
                queue.add(new Node(b*2,c-b));
            }else if ( b > c &&  !visited[b-c][c*2] ){
                visited[b-c][c*2] = true;
                queue.add(new Node(b-c,c*2));
            }
        }
        System.out.print(0);
    }

    private static class Node{
        int a;
        int b;
        public Node(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
}
