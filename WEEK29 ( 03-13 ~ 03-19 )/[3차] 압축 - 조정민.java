import java.util.*;

class Solution {
    public int[] solution(String msg) {
        int[] answer = {};
        
        StringBuilder sb = new StringBuilder();
        List<String> list = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        list.add("");
        
        for(int i = 65; i <= 90; i++) {
            list.add("" + (char)i);
        }

        for(int i = 0; i < msg.length(); i++) {
            char c = msg.charAt(i);
            if(list.indexOf(sb.toString() + c) > -1) {
                sb.append(c);
            } else {
                list.add(sb.toString() + c);
                list2.add(list.indexOf(sb.toString()));
                sb = new StringBuilder();       
                sb.append(c);
            }
        }
        
        list2.add(list.indexOf(sb.toString()));
        
        answer = new int[list2.size()];     
        int cnt = 0;
        for(int x : list2) {
            answer[cnt] = x;
            cnt++;
        }
        
        return answer;
    }
}
