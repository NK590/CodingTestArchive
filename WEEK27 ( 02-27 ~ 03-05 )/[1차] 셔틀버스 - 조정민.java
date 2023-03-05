import java.util.*;

class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";
        List<Time> timeList = new ArrayList<>();
        Time now = new Time(9, 0);
        
        for(String time : timetable) {
            String[] timeData = time.split(":");
            int h = Integer.valueOf(timeData[0]);
            int m2 = Integer.valueOf(timeData[1]);
            
            timeList.add(new Time(h, m2));
        }
        
        Collections.sort(timeList);
        
        int cnt2 = n;
        while(cnt2 > 1) {
            int cnt = m;
            
            while(cnt > 0) {
                if(timeList.size() == 0) 
                    break;
                
                Time targetTime = timeList.get(0);
                
                if(now.compareTo(targetTime) >= 0) {
                    timeList.remove(0);
                } else {
                    break;
                }
                
                cnt--;
            }
            
            
            now.add(t);
            cnt2--;
        }
        
        // for(Time x : timeList) {
        //     System.out.println(x.h + ":" + x.m);
        // }
        
        if(timeList.size() < m) {
            answer = now.getString();
        } else {
            Time targetTime = timeList.get(m - 1);
            
            if(now.compareTo(targetTime) < 0) {
                answer = now.getString();
            } else {
                targetTime.subtract(1);
                answer = targetTime.getString();
            }
        }
        
        return answer;
    }
    
    class Time implements Comparable<Time> {
        int h;
        int m;

        Time(int h, int m) {
            this.h = h;
            this.m = m;
        }

        @Override
        public int compareTo(Time o) {
            if(this.h == o.h) {
                return this.m - o.m;
            } else {
                return this.h - o.h;
            } 
        }

        public void add(int m) {
            if(this.m + m >= 60) {
                this.h += 1;
                this.m += m - 60;
            } else {
                this.m += m;
            }
        }        
        
        public void subtract(int m) {
            if(this.m < m) {
                this.h -= 1;
                this.m += 60 - m;
            } else {
                this.m -= m;
            }
        }
        
        public String getString() {
            return String.format("%02d", this.h) + ":" + String.format("%02d", this.m);
        }
        
    }
}
