import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // 3 * n
        int[] dp = new int[n+1]; // i 번쨰 인덱스의 값은 i번째의 경우의 수
        dp[0] = 1;
        for(int i  = 2; i < dp.length ; i+=2){
            dp[i] = dp[i-2]*3;
            for(int  j = 0 ; j < i-2; j=j+2){
                dp[i] += dp[j]*2;
            }
        }
        System.out.println(dp[n]);
    }
}