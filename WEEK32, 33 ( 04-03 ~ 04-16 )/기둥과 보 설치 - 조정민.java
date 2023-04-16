import java.util.*;

class Solution {
    public int[][] solution(int n, int[][] build_frame) {
        // 설치 또는 제거
        // 설치[1]할 경우
        //  [x, y, 1] 보를 설치할 경우
        //      한쪽 끝 부분이 기둥의 위에 있거나, 양쪽 끝 부분이 동시에 다른 보와 연결되어 있어야 한다.
        //      [x, y - 1, 0] || [x + 1, y - 1, 0] || ([x - 1, y, 1] && [x + 1, y, 1])
        //  [x, y, 0] 기둥을 설치할 경우
        //      바닥 위에 있거나 다른 기둥 위에 위에 있거나 보의 한 쪽 끝 위에 있어야 한다.
        //      y == 0 || [x, y - 1, 0] || [x, y, 1] || [x - 1, y, 1]
        // 삭제[0]할 경우 => 전수조사
        //  [x, y, 1] 보를 삭제할 경우
        //      한쪽 끝 부분에 기둥이나 보가 있는 경우 그 아래에 기둥이 있어야 한다.
        //          ==> 한쪽 끝 부분에 기둥이나 보가 있는데 그 아래에 기둥이 없으면 안된다.
        //      !(([x - 1, y, 1] || [x, y, 0]) && [x][y-1][0]) && !(([x + 1, y, 1] || [x + 1, y, 0]) && [x + 1][y-1][0])
        //  [x, y, 0] 기둥을 삭제할 경우
        //      기둥 위에 양 쪽으로 보가 있거나 아무것도 없어야 한다.
        //      ([x, y + 1, 1]  && [x - 1, y + 1, 1]) || (![x, y + 1, 1]  && ![x - 1, y + 1, 1] && ![x, y + 1, 0]);
        
        
        List<int[]> list = new ArrayList<>();
        boolean[][][] map = new boolean[n + 3][n + 3][2];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                Arrays.fill(map[i][j], false);
            }
        }
        
        for(int[] frame : build_frame) {
            int x = frame[0];
            int y = frame[1];
            int type = frame[2];
            int work = frame[3];
            
            // System.out.println(x + " " + y + " " + type);
            
            // 설치
            if(work == 1) {                
                // 기둥 
                if(type == 0) {
                    if(y == 0 || map[x][y - 1][0] || map[x][y][1] || (x > 0 && map[x - 1][y][1])) {
                        map[x][y][type] = true;
                    }
                } 
                // 보
                else if(type == 1) {
                    if((y > 0 && map[x][y - 1][0])
                       || (y > 0 && map[x + 1][y - 1][0])
                       || ((x > 0 && map[x - 1][y][1]) && map[x + 1][y][1])) {
                        map[x][y][type] = true;
                    }
                }
            }
            // 삭제
            else if(work == 0) {
//                 // 기둥 
//                 if(type == 0) {
//                     // 기둥 오른쪽에 보가 있는데 연결된 기둥이 없으면서 왼쪽에 보가 없는 경우
//                     if(map[x][y + 1][1] && (!(x > 0 && map[x - 1][y + 1][1] || !map[x + 1][y + 1][1]) && !map[x + 1][y][0]))
//                         continue;
                    
//                     // 기둥 왼쪽에 보가 있는데 연결된 기둥이 없으면서 오른쪽에 보가 없는 경우
//                     if(x > 0 && map[x - 1][y + 1][1] && (!map[x][y + 1][1] || !(x > 1 && map[x - 2][y + 1][1])) && !map[x - 1][y][0])
//                         continue;
                    
//                     // 기둥 위쪽에 기둥이 있는데 양쪽에 전부 보가 없는 경우
//                     if(map[x][y + 1][0] && (!map[x][y + 1][1] && !(x > 0 && map[x - 1][y][1])))
//                         continue;
                    
//                     map[x][y][type] = false;
//                 } 
//                 // 보
//                 else if(type == 1) {
//                     // 왼쪽에 보가 있는데 그 양쪽 전부 기둥이 없는 경우
//                     if(x > 0 && map[x - 1][y][1] && !map[x - 1][y - 1][0] && map[x][y - 1][0])
//                         continue;
                    
//                     // 왼쪽에 기둥이 있는데 그 아래 기둥과 보 모두 없는 경우
//                     if(map[x][y][0] && !map[x][y - 1][0] && !(x > 0 && map[x - 1][y][1]))
//                         continue;
                    
//                     // 오른쪽에 보가 있는데 그 양쪽 전부 기둥이 없는 경우
//                     if(map[x + 1][y][1] && !map[x + 1][y - 1][0] && !map[x + 2][y - 1][0])
//                         continue;
                    
//                     // 오른쪽에 기둥이 있는데 그 아래 기둥과 보 모두 없는 경우
//                     if(map[x + 1][y][0] && !map[x + 1][y - 1][0] && !map[x + 1][y][1])
//                         continue;
                    
//                     map[x][y][type] = false;
//                 }
                // 전수 조사
                map[x][y][type] = false;
                boolean flag = true;
                
                Loop1 : for(int i = 0; i <= n; i++) {
                    for(int j = 0; j <= n; j++) {
                        // 기둥이 존재하는 경우
                        if(map[i][j][0]) {
                            // 기둥이 지면에 이어져있거나 | 기둥 아래에 기둥이 있거나 | 왼쪽에 보가 있거나 | 오른쪽에 보가 있어야 한다.
                            if(!(j == 0 || (j > 0 && map[i][j - 1][0]) || (i > 0 && map[i - 1][j][1]) || map[i][j][1])) {
                                flag = false;
                                break Loop1;
                            }
                        }
                             
                        // 보가 존재하는 경우
                        if(map[i][j][1]) {
                            // 보의 왼쪽 아래에 기둥이 있거나 | 보의 오른쪽 아래에 기둥이 있거나 | 보의 양쪽에 보가 있어야 한다.
                            if(!(map[i][j - 1][0] || map[i + 1][j - 1][0] || (i > 0 && map[i - 1][j][1] && map[i + 1][j][1]))) {
                                flag = false;
                                break Loop1;
                            }
                        }   
                    }
                }
                
                if(!flag) {
                    map[x][y][type] = true;
                }
                
            }
        }
        
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                for(int z = 0; z < 2; z++) {
                    if(map[i][j][z])
                        list.add(new int[] {i, j, z});
                }
            }
        }
        
        Collections.sort(list, (a, b) -> {
            if(a[0] != b[0])
                return a[0] - b[0];
            else if(a[1] != b[1]) 
                return a[1] - b[1];
            else
                return a[2] - b[2];
        });
        
        return list.toArray(new int[list.size()][3]);
    }
}
