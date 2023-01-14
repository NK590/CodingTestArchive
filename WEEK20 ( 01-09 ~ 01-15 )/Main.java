package cordingTest2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// 이항계수는 조합 ==> nCr
		// n 개 중 순서에 상관없이 r 개를 고르는 경우의 수
		// ex) 5 개중 2개를 고르는 경우의 수
		// 		1 2 3 4 5
		// 		경우의 수는 1 을 고른다 or 안 고른다.
		// 		고를 경우 2 3 4 5 중 2 개를 고른다. == 4C2
		// 		고르지 않은 경우 == 4C3
		// 		n == r 인 경우 무조건 1, r 이 0 인 경우 무조건 1
		// 		nCr = n-1Cr-1 + n-1Cr
		// 		top-down

		String[] str = br.readLine().split(" ");
		int n = Integer.valueOf(str[0]);
		int r = Integer.valueOf(str[1]);
		int[][] dp = new int[n + 1][r + 1];	// int[n][r]

		System.out.println(fn(n, r, dp));
	}

	static int fn(int n, int r, int[][] dp) {
		if(n == r || r == 0)	return 1;
		if(dp[n][r] != 0) return dp[n][r];

		return dp[n][r] = (fn(n - 1, r - 1, dp) % 10007 + fn(n - 1, r, dp) % 10007) % 10007;
	}
}
