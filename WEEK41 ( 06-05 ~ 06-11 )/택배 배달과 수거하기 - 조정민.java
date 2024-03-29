import java.util.*;

class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        int lastDel = -1;
        int lastPick = -1;        
        
        for(int i = n - 1; i >= 0; i--) {
            if(deliveries[i] != 0) {
                lastDel = i;
                break;
            }
        }
        
        for(int i = n - 1; i >= 0; i--) {
            if(pickups[i] != 0) {
                lastPick = i;
                break;
            }
        }
        
        while(lastDel > -1 || lastPick > -1) {
            answer += Math.max(lastDel + 1, lastPick + 1) * 2;
            
            int c = cap;
            
            for(int i = lastDel; i >= 0; i--) {
                if(c >= deliveries[i]) {
                    c -= deliveries[i];
                    deliveries[i] = 0;
                } else {
                    deliveries[i] -= c;
                    break;
                }
                
                lastDel--;
            }
            
            c = cap;
            
            for(int i = lastPick; i >= 0; i--) {
                if(c >= pickups[i]) {
                    c -= pickups[i];
                    pickups[i] = 0;
                } else {
                    pickups[i] -= c;
                    break;
                }
                
                lastPick--;
            }
            
        }
            
        return answer;
    }
}
