import java.util.*;

class Solution {
    
    public int solution(int[][] board) {
        int answer = -1;
        int length = board.length;
        int[][][][] visited = new int[101][101][101][101];
        Queue<int[]> queue = new LinkedList<>();
        
        queue.add(new int[] {0, 0, 0, 1});
        
        while(!queue.isEmpty()) {
            int size = queue.size();
            answer++;
            
            // System.out.println(answer);
            
            while(size > 0) {
                size--;
                
                int[] temp = queue.poll();
                int x1 = temp[0];
                int y1 = temp[1];
                int x2 = temp[2];
                int y2 = temp[3];
                
               if(visited[x1][y1][x2][y2] == 1 || visited[x2][y2][x1][y1] == 1)
                    continue;
                
                visited[x1][y1][x2][y2] = 1;
                visited[x2][y2][x1][y1] = 1;
                
                // System.out.println(x1 + ", " + y1 + " : " + x2 + ", " + y2);
                
                // for(int i = 0; i < length; i++) {
                //     for(int j = 0; j < length; j++) {
                //         if((i == x1 && j == y1) || (i == x2 && j == y2)) {
                //             System.out.print("x");
                //         }
                //         else {
                //             System.out.print(board[i][j]);
                //         }
                //     }   
                //     System.out.println();
                // }
                // System.out.println();
                
                if((x1 == length - 1 && y1 == length - 1) || (x2 == length - 1 && y2 == length -1))
                    return answer;
                
                // 앞 뒤로 움직인다.
                // if(y1 == y2) {
                    if(x1 > 0 && x2 > 0) {
                        if(board[x1 - 1][y1] == 0 && board[x2 - 1][y2] == 0) {
                            queue.add(new int[] {x1 - 1, y1, x2 - 1, y2});   
                        }
                    }
                    
                    if(x1 < length - 1 && x2 < length - 1) {
                        if(board[x1 + 1][y1] == 0 && board[x2 + 1][y2] == 0) {
                            queue.add(new int[] {x1 + 1, y1, x2 + 1, y2});
                        }
                    }
                // } else if(x1 == x2) {
                    if(y1 > 0 && y2 > 0) {
                        if(board[x1][y1 - 1] == 0 && board[x2][y2 - 1] == 0) {
                            queue.add(new int[] {x1, y1 - 1, x2, y2 - 1});   
                        }
                    }
                    
                    if(y1 < length - 1 && y2 < length - 1) {
                        if(board[x1][y1 + 1] == 0 && board[x2][y2 + 1] == 0) {
                            queue.add(new int[] {x1, y1 + 1, x2, y2 + 1});
                        }
                    }
                // }
                
                // 회전한다.
                if(y1 == y2) {
                    if(y1 > 0 && y2 > 0) {
                        if(board[x1][y1 - 1] == 0 && board[x2][y2 - 1] == 0) {
                            int max = Math.max(x1, x2);
                            int min = Math.min(x1, x2);
                            queue.add(new int[] {min, y1, min, y1 -1});
                            queue.add(new int[] {max, y1, max, y1 -1});
                        }
                    }
                        
                    if(y1 < length - 1 && y2 < length - 1) {
                        if(board[x1][y1 + 1] == 0 && board[x2][y2 + 1] == 0) {
                            int max = Math.max(x1, x2);
                            int min = Math.min(x1, x2);
                            queue.add(new int[] {min, y1, min, y1 +1});
                            queue.add(new int[] {max, y1, max, y1 +1});
                        }
                    }
                } else if(x1 == x2) {
                    if(x1 > 0 && x2 > 0) {
                        if(board[x1 - 1][y1] == 0 && board[x2 - 1][y2] == 0) {
                            int max = Math.max(y1, y2);
                            int min = Math.min(y1, y2);
                            queue.add(new int[] {x1, min, x1 - 1, min});
                            queue.add(new int[] {x1, max, x1 - 1, max});
                        }
                    }
                        
                    if(x1 < length - 1 && x2 < length - 1) {
                        if(board[x1 + 1][y1] == 0 && board[x2 + 1][y2] == 0) {
                            int max = Math.max(y1, y2);
                            int min = Math.min(y1, y2);
                            queue.add(new int[] {x1, min, x1 + 1, min});
                            queue.add(new int[] {x1, max, x1 + 1, max});
                        }
                    }
                }
                
            }
        }
        
        return answer;
    }
}
