import java.util.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        Map<String, Integer> map = new HashMap<>();
        Map<String, Integer> usageTimeMap = new HashMap<>();
        
        for(String record : records) {
            String[] str = record.split(" ");
            String time = str[0];
            String number = str[1];
            String type = str[2];
            
            if(type.equals("IN")) {
                map.put(number, parseTime(time));
            } else if(type.equals("OUT")) {
                usageTimeMap.put(number, usageTimeMap.getOrDefault(number, 0) + parseTime(time) - map.get(number));
                map.remove(number);
            }
        }
        
        for(String key : map.keySet()) {            
            usageTimeMap.put(key, usageTimeMap.getOrDefault(key, 0) + parseTime("23:59") - map.get(key));
        }
        
        List<String> keys = new ArrayList<>(usageTimeMap.keySet());
        Collections.sort(keys);        
        int[] answer = new int[keys.size()];
        
        int idx = 0;
        for(String key : keys) {            
            int usageTime = usageTimeMap.get(key);     
            int amount = fees[1];
            
            // System.out.println(key + " : " + usageTime);
            usageTime -= fees[0]; 
            
            if(usageTime > 0) {
                amount += (usageTime / fees[2]) * fees[3];
                
                if((usageTime % fees[2]) > 0) {
                    amount += fees[3];
                } 
            }
            
            answer[idx++] = amount;
        }
        
        
        return answer;
    }
    
    public int parseTime(String time) {
        String[] str = time.split(":");
        
        return 60 * Integer.valueOf(str[0]) + Integer.valueOf(str[1]);
    }
}
