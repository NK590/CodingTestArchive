import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = br.readLine().split(" ");

        int n = Integer.parseInt(inputs[0]);
        int k = Integer.parseInt(inputs[1]);

        int[][] item = new int[n + 1][2];

        for (int i = 1; i <= n; i++) {
            inputs = br.readLine().split(" ");
            item[i][0] = Integer.parseInt(inputs[0]); // 무게
            item[i][1] = Integer.parseInt(inputs[1]); // 가치
        }

        int[][] dp = new int[n + 1][k + 1]; // dp 테이블 [아이템][무게]

        for(int i=1;i<=n;i++) {
            // n 개의 아이템들에 대해서 dp 테이블 업데이트 수행
            for(int j=1;j<=k;j++) {
                dp[i][j] = dp[i-1][j]; // 이전 아이템의 가치로 초기화
                if(j - item[i][0]>=0) { // 현재 아이템의 무게에서 이전 아이템의 무게를 빼고 남는 다면
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-item[i][0]]+item[i][1]); // Math.max(이전 아이템의 가치, 남는 무게의 가치  + 현재 아이템의 가치)
                }
            }
        }
        System.out.println(dp[n][k]);
    }
}
