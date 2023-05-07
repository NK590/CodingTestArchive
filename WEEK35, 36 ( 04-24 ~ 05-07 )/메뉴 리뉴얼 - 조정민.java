import java.util.*;

class Solution {
    public String[] solution(String[] orders, int[] course) {
        List<String> answer = new ArrayList<>();
        Map<String, Integer> comb = new HashMap<>();
        int[] cnt = new int[course.length];
        
        
		for(String order : orders) {
            String[] menu = order.split("");
            
            List<List<String>> list = new ArrayList<>();
            list.add(new ArrayList<>());
            
            // 각 주문 별로 모든 조합 만들기
            for(String x : menu) {
                int size = list.size();
                for(int i = 0; i < size; i++) {
                    List<String> temp = new ArrayList<>();
                    temp.addAll(list.get(i));
                    temp.add(x);
                    list.add(temp);                
                }
            }
            
            // 만든 조합 중 메뉴의 갯수가 course 에 포함되는 경우만 comb 에 저장
            for(List<String> x : list) {
                if(x.size() < 2)
                    continue;
                
                for(int i = 0; i < course.length; i++) {
                    if(x.size() == course[i]) {
                
                        StringBuilder sb = new StringBuilder();
                        Collections.sort(x);

                        for(String y : x) {
                            sb.append(y);
                        }

                        comb.put(sb.toString(), comb.getOrDefault(sb.toString(), 0) + 1);
                        
                        // 각 course 별로 가장 많이 나온 값을 cnt 에 저장
                        cnt[i] = Math.max(cnt[i], comb.get(sb.toString()));
                    }
                }
            }
			
		}
        
        // 저장된 comb 중 나온 횟수가 각 코스 별 cnt 에 저장된 값과 같으면서 그 값이 2 이상인 메뉴를 answer 에 저장
        for(String key : comb.keySet()) {
            int cnt2 = (int)comb.get(key);
            
            for(int i = 0; i < course.length; i++) {
                if(key.length() == course[i] && cnt2 == cnt[i] && cnt2 >= 2) {
                    answer.add(key);
                }
            }
        }
        
        // 정렬 후 리턴
        Collections.sort(answer);
        
        return answer.toArray(new String[answer.size()]);
    }
    
}
