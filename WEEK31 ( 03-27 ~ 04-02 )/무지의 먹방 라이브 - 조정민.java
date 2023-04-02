import java.util.*;

class Solution {
    public int solution(int[] food_times, long k) {
        int answer = 0;
        long size = (long)food_times.length;
        long eat_cnt = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int x : food_times) {
            pq.add(x);
        }
        
        while(!pq.isEmpty()) {
            int n = pq.poll();
            
            long need_eat = n - eat_cnt;
            
            if(need_eat < 1) {
                size--;
                continue;
            } else if(need_eat * size <= k) {
                k -= need_eat * size;
                eat_cnt = n;
                size--;
            } else {
                k %= (long)size;
                pq.add(n);
                break;
            }
        }
        
        System.out.println(eat_cnt);
        
        if(pq.isEmpty()) {
            answer = -1;
        } else {
            answer = 1;
            
            for(int x : food_times) {
                if(x <= eat_cnt)  {
                    answer++;                    
                } else if(k > 0){
                    answer++;
                    k--;
                } else {
                    break;
                }
            }
        }
        
        return answer;
    }
}
