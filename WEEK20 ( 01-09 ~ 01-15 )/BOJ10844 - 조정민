package cordingTest2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.valueOf(br.readLine());
		int[][] dp = new int[n + 1][10];
		int a = 1000000000;
		int answer = 0;
		Arrays.fill(dp[1], 1);

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				if (j == 0) {
					dp[i + 1][j + 1] = (dp[i][j] + dp[i + 1][j + 1]) % a;
				} else if (j == 9) {
					dp[i + 1][j - 1] = (dp[i][j] + dp[i + 1][j - 1]) % a;
				} else {
					dp[i + 1][j + 1] = (dp[i][j] + dp[i + 1][j + 1]) % a;
					dp[i + 1][j - 1] = (dp[i][j] + dp[i + 1][j - 1]) % a;
				}
			}
		}

		for (int i = 1; i < 10; i++) {
			answer = (answer + dp[n][i]) % a;
		}

		System.out.println(answer);
	}
}
