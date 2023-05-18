// 프로그래머스 - 양궁대회

import java.util.*;

class Solution {
    int gap = 0;
    int[] answer = new int[11];

    public int[] solution(int n, int[] info) {
        // 과녁은 10개
        // 과녁에 어피치보다 많이 맞춰야지만 의미가 있기 때문에 각 과녁마다 (어피치가 맞춘 수 + 1 or 0) 두 가지 경우의 수
        // int[] answer = {};
        int[] info2 = new int[11];

        fn(n, 0, info, info2);

        return gap == 0 ? new int[] {-1} : answer;
    }

    public void fn(int n, int idx, int[] info, int[] info2) {
        // 남은 화살이 0인 경우 또는 남은 과녁이 없는 경우 점수 계산
        if(n == 0 || idx > 10) {
            int point = 0;
            int point2 = 0;

            for(int i = 0; i < 11; i++) {
                if(info[i] > info2[i]) {
                    point += 10 - i;
                } else if(info[i] < info2[i]) {
                    point2 += 10 - i;
                }
            }

            if(point2 - point < gap) {
                return;
            }

            // 남은 화살이 있는 경우 가장 낮은 점수인 0점에 맞춘 것으로 처리
            info2[10] = n;

            if(point2 - point == gap) {


                for(int i = 0; i < 11; i++) {
                    if(answer[10 - i] > info2[10 - i]) {
                        return;
                    }

                    if(answer[10 - i] < info2[10 - i]) {
                        break;
                    }
                }
            }

            for(int i = 0; i < 11; i++) {
                answer[i] = info2[i];
            }

            gap = point2 - point;
            return;
        }

        // 현재 과녁에서 점수를 얻는 경우 (남아있는 화살의 수가 어피치가 맞춘 화살의 수보다 많은 경우에만)
        if(n > info[idx]) {
            info2[idx] = info[idx] + 1;
            fn(n - info2[idx], idx + 1, info, info2);
            info2[idx] = 0;
        }

        // 현재 과녁에서 점수를 얻지 않는 경우
        fn(n, idx + 1, info, info2);
    }
}