import java.util.*;

class Solution {
    public int solution(String[][] relation) {
        int answer = 0;
        
        int row = relation.length;
        int column = relation[0].length;
        
        // 가능한 모든 조합 생성
        List<List<Integer>> comb = new ArrayList<>();
        
        {
            List<Integer> temp = new ArrayList<>();
            comb.add(temp);
            
            for(int i = 0; i < column; i++) {
                int list_size = comb.size();
                
                for(int j = 0; j < list_size; j++) {
                    temp = new ArrayList<>();
                    temp.addAll(comb.get(j));
                    temp.add(i);
                    comb.add(temp);
                }
            }
        }
        
        // 길이 오름차순으로 정렬
        Collections.sort(comb, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> l1, List<Integer> l2) {
                return l1.size() - l2.size();
            }
        });
        
        for(int i = 0; i < comb.size(); i++) {
            List<List<String>> temp = new ArrayList<>();
            List<Integer> temp2 = comb.get(i);
            
            if(temp2.size() == 0) continue;            
            
            for(String[] x : relation) {
                List<String> temp3 = new ArrayList<>();
                
                for(Integer y : temp2) {
                    temp3.add(x[y]);
                }                
                
                if(temp.contains(temp3)) {
                    // 중복이 있는 경우 break;
                    break;
                } else {
                    // 중복이 없는 경우 리스트에 삽입
                    temp.add(temp3);
                }
                
                // 리스트의 길이가 로우의 길이와 같을 경우 후보키
                // 조합에서 후보키를 포함하는 속성의 집합 삭제
                if(temp.size() == row) {
//                     for(Integer y : temp2) {
//                         System.out.print(y + " ");
//                     }
                    
//                     System.out.println();
                    
                    Loop1 : for(int j = i + 1; j < comb.size(); j++) {
                        List<Integer> temp4 = comb.get(j);
                        
                        for(Integer y : temp2) {
                            if(!temp4.contains(y))
                               continue Loop1;
                        }
                        
                        // System.out.print("contains = ");
                        // for(Integer y : temp4) {
                        //     System.out.print(y + " ");
                        // }
                        // System.out.println();
                                                
                        temp4.clear();
                    }                    
                    
                    answer++;
                }
            }
        }
        
        return answer;
    }
}
