import java.util.*;

class Solution {
    int[] X = { 0, 0, 1, 1 };
    int[] Y = { 0, 1, 0, 1 };
    
    public int solution(int m, int n, String[] board) {
        int answer = 0;
        
        String[][] board2 = new String[m][n];
        
        for(int i = 0; i < m; i++) {
            board2[i] = board[i].split("");
        }
        
        while(true) {
            List<int[]> list = new ArrayList<>();
            
            Loop1 : for(int i = 0; i < m - 1; i++) {
                Loop2 : for(int j = 0; j < n - 1; j++) {
                    for(int k = 1; k < 4; k++ ) {                    
                        if(board2[i][j].equals("") || !(board2[i][j].charAt(0) >= 'A' && board2[i][j].charAt(0) <= 'Z') || !board2[i][j].equals(board2[i + X[k]][j + Y[k]])) {
                            continue Loop2;
                        }
                    }
                    
                    list.add(new int[] { i, j });
                }
            }
            
            if(list.size() == 0)
                break;
            
            for(int[] x : list) {
                int x2 = x[0];
                int y2 = x[1];
                
                for(int i = 0; i < 4; i++) {
                    board2[x2 + X[i]][y2 + Y[i]] = "";
                }
                
            }
            
            for(int[] x : list) {
                int x2 = x[0];
                int y2 = x[1];
                
                for(int i = 0; i < 4; i++) {
                    board2[x2 + X[i]][y2 + Y[i]] = "";
                }                
            }
            
            // drop                        
            for(int i = 0; i < n; i++) {
                for(int j = m - 2; j >= 0; j--) {
                    for(int k = j + 1; k <= m - 1; k++) {
                        if(!board2[k-1][i].equals("") && board2[k][i].equals("")) {
                            board2[k][i] = board2[k-1][i];
                            board2[k-1][i] = "";                                
                        }  else {
                            break;
                        } 
                    } 
                }
            }
            
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board2[i][j].equals("")) {
                    answer++;
                }
            } 
        } 
        
        
        return answer;
    }
}
