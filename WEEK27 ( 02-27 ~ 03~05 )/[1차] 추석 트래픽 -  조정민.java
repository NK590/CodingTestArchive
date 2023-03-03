import java.util.*;
import java.text.*;

class Solution {
    public int solution(String[] lines) {
        int answer = 0;
        
        List<Log> logList = new ArrayList<>();
        List<Log> logList2 = new ArrayList<>();
        PriorityQueue<Log> pq = new PriorityQueue<>();
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");                
        
        try {
            for(String line : lines) {
                String[] str = line.split(" ");           
                String time = str[2].replace("s", "");
                Date date = sdf.parse(line);
		
                logList.add(new Log(date.getTime() - (long)(Double.valueOf(time) * 1000) + 1, date.getTime()));
                logList2.add(new Log(date.getTime() - (long)(Double.valueOf(time) * 1000) + 1, date.getTime()));
            }
        } catch(Exception e) {
        }
        
        // 로그 리스트를 시작 시간의 오름차 순으로 정렬
        Collections.sort(logList, new Comparator<Log>() {
        	public int compare(Log l1, Log l2) {
        		if(l1.startTime > l2.startTime)
                    return 1;
                else if (l1.startTime == l2.startTime)
                    return 0;
                else
                    return -1;
        	}
        });
        
        // 로그리스트 종료 시간 오름차 순으로 정렬
        Collections.sort(logList2);
        
        for(Log x : logList) {
            System.out.println("start = " + x.startTime + " end = " + x.endTime);
        }
            
        // 우선순위큐로 끝나는 시간 오름차 순으로 현재 구간에 포함된 로그 저장
        int cnt = 0;        
        for(Log log : logList2) {
            for(int i = cnt; i < logList.size(); i++) {
                if(logList.get(i).startTime <= log.endTime + 999) {
                    pq.add(logList.get(i));
                    cnt++;
                } else {
                    break;
                }                
            }
            
            while(!pq.isEmpty()) {
                if(pq.peek().endTime < log.endTime) {
                    pq.poll();
                } else {
                    break;
                }
            }
            
            answer = Math.max(answer, pq.size());
        }
        
        return answer;
    }
    
    class Log implements Comparable<Log> {
        long startTime;
        long endTime;
        
        Log(long startTime, long endTime) {
            this.startTime = startTime;
            this.endTime = endTime;
        }
        
        @Override
        public int compareTo(Log o) {
            if(this.endTime > o.endTime)
                return 1;
            else if (this.endTime == o.endTime)
                return 0;
            else
                return -1;
        }
    }
}
