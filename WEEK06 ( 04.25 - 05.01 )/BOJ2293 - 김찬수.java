import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        // i원을 통해 j원을 만들수 있는 경우의수
        int[] dp = new int[k+1];
        for (int i = 0; i < n; i++) {
            int coin = Integer.parseInt(br.readLine());
            for (int j = 1; j <= k; j++) {
                if (j - coin > 0) {
                    // j원-coin원 경우의수  + coin원 경우의수 합
                    dp[j]+= dp[j-coin];

                    // j원 해당 코인으로 만들 수 있으면 경우의 수 1 추가
                } else if (j - coin == 0) {
                    dp[j]++;
                }
            }
        }
        System.out.println(dp[k]);
    }
}