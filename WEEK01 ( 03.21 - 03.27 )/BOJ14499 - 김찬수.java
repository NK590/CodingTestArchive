import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] src = br.readLine().split(" ");
        int n = Integer.parseInt(src[0]); // 세로길이
        int m  = Integer.parseInt(src[1]); // 가로길이
        int x  = Integer.parseInt(src[2]); // 주사위 위치 (x)
        int y  = Integer.parseInt(src[3]); // 주사위 위치 (y)
        int k = Integer.parseInt(src[4]); // 명령의 개수
        Dice dice = new Dice(x, y); // 주사위 객체 초기화 (시작점 x,y )
        int[][] graph = new int[n][m];
        for (int i = 0 ; i < n ; i++){
            String[] input = br.readLine().split(" ");
            for(int j = 0; j < m ; j++){
                graph[i][j]= Integer.parseInt(input[j]);
            }
        }
        String[] cmdList = br.readLine().split(" ");
        for ( int i = 0 ; i < k ; i++){
            String cmd = cmdList[i];
            Direction direction = Direction.findDirection(cmd); // 명령을 Direction enum class와 매핑
            if(dice.isValidDirection(direction,graph)){ // 유효한 경로인경우에만 주사위 이동
                dice.move(direction, graph);
                System.out.println(dice.getTop());
            }
        }
    }

    // 명령어 방향
    private enum Direction{
        NORTH("4"),
        SOUTH("3"),
        WEST("2"),
        EAST("1");
        private final String value;
        Direction(String value) {
            this.value =value;
        }
        public static Direction findDirection(String value){
            for (Direction direction : Direction.values()) {
                if(direction.value.equals(value)){
                    return direction;
                }
            }
            throw new AssertionError();
        }
    }
    private static class Dice {
        // 주사위 전개도에 해당되는 각각의 면
        private static int TOP = 6;
        private static int BOTTOM = 1;
        private static int NORTH = 2;
        private static int SOUTH = 5;
        private static int WEST = 4;
        private static int EAST = 3;
        // 주사위 각 면의 값
        private int[] tmp = new int[7];
        // 주사위 현재위치
        private int posX;
        private int posY;

        public Dice(int posX, int posY) {
            this.posX = posX;
            this.posY = posY;
        }
        public int getTop(){
            return tmp[TOP];
        }

        public void move(Direction direction, int[][] graph) {
            int[] clone = tmp.clone();
            if (Direction.SOUTH.equals(direction)) {
                tmp[TOP] = clone[NORTH];
                tmp[SOUTH] = clone[TOP];
                tmp[BOTTOM] = clone[SOUTH];
                tmp[NORTH] = clone[BOTTOM];
                posY+=1;
            }
            else if (Direction.NORTH.equals(direction)) {
                tmp[TOP] = clone[SOUTH];
                tmp[SOUTH] = clone[BOTTOM];
                tmp[BOTTOM] = clone[NORTH];
                tmp[NORTH] = clone[TOP];
                posY-=1;
            }
            else if (Direction.EAST.equals(direction)) {
                tmp[TOP] = clone[WEST];
                tmp[EAST] = clone[TOP];
                tmp[BOTTOM] = clone[EAST];
                tmp[WEST] = clone[BOTTOM];
                posX+=1;
            }
            else{
                tmp[WEST] = clone[TOP];
                tmp[BOTTOM] = clone[WEST];
                tmp[EAST] = clone[BOTTOM];
                tmp[TOP] = clone[EAST];
                posX-=1;
            }
            if(graph[posY][posX] == 0){
                graph[posY][posX] = tmp[BOTTOM];
            }else{
                tmp[BOTTOM] = graph[posY][posX];
                graph[posY][posX] = 0;
            }
        }

        private boolean isValidDirection(Direction direction , int[][] graph) {
            if(direction.equals(Direction.WEST)){
                return posX  -1 >= 0;
            }if(direction.equals(Direction.EAST)){
                return posX + 1 < graph[0].length ;
            }if(direction.equals(Direction.NORTH)){
                return posY - 1 >= 0;
            }if(direction.equals(Direction.SOUTH)){
                return posY + 1 < graph.length;
            }
            throw new AssertionError();
        }
    }
}
