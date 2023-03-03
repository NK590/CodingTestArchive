import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        
        List<String> list = new ArrayList<>();
        
        for(String city : cities) {
            city = city.toUpperCase();
            
            int idx = list.indexOf(city);
            
            if(idx > -1) {
                answer += 1;
                list.remove(idx);
                list.add(city);
            } else {
                answer += 5;
                
                int size = list.size();
                
                if(size >= cacheSize && size > 0) {
                    list.remove(0);
                }
                
                if(list.size() < cacheSize) {
                    list.add(city);   
                }
                
            }
            
        }
        
        return answer;
    }
}
