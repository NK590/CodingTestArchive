import java.util.*;

// https://velog.io/@kimdukbae/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%ED%8A%B8%EB%9D%BC%EC%9D%B4-Trie
// 트라이 자료구조 참고하여 풀었습니다.

class Solution {
    public int solution(String[] words) {
        int answer = 0;
        
        Node head = new Node(null, null);
        
        // 트라이 생성
        for(String word : words) {
            String[] str = word.split("");
            Node curNode = head;
                
            for(int i = 0; i < str.length; i++) {
                String x = str[i];
                
                if(curNode.child.containsKey(x)) {
                    curNode = curNode.child.get(x);
                } else {
                    Node temp = new Node(x, null);
                    curNode.child.put(x, temp);
                    curNode = temp;
                }
                
                if(i == str.length - 1) {
                    curNode.data = word;
                }
            }
        }
        
        // 검색
        for(String word : words) {
            int cnt = 0;
            String[] str = word.split("");
            Node curNode = head;
            
            for(int i = 0; i < str.length; i++) {
                String x = str[i];
                curNode = curNode.child.get(x);
                answer++;
                
                if(i == str.length - 1) {
                    if(curNode.child.size() != 0) {
                        cnt = 0;
                    }
                } else {
                    if(curNode.data == null && curNode.child.size() == 1) {
                        cnt++;
                    } else {
                        cnt = 0;
                    }
                }
            }
            
            answer -= cnt;
        }
        
        return answer;
    }
    
    class Node {
        String key;
        String data;
        Map<String, Node> child;
        
        Node(String key, String data) {
            this.key = key;
            this.data = data;
            this.child = new HashMap<>();
        }
        
    }
}
