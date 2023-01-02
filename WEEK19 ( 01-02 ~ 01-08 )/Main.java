package cordingTest2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		/** 가장 큰 증가 부분 수열

		부분 수열 : 주어진 수열의 일부 항을 원래 순서대로 나열하여 얻을 수 있는 수열

		첫번째 수 (부분 수열이 비어있을 경우)
			부분 수열에 수를 넣는다 or 안 넣는다.

		두번째 수 부터 (부분 수열에 수가 있을 경우)
			마지막에 넣은 수 보다 클 경우 부분 수열에 수를 넣는다 or 안 넣는다.
			마지막에 넣은 수 보다 작을 경우 넣는다 or 안 넣는다.

		마지막에 넣은 수 보다 큰 경우 (n > maxNum)
			f(n) = Max(f(n + 1) + n, f(n + 1))
		마지막에 넣은 수 보다 작거나 같은 경우 (n <= maxNum)
			f(n) = f(n + 1)

		*/

		int n = Integer.valueOf(br.readLine());
		int[] arr = new int[n + 1];
		int[][] dp = new int[n + 1][n + 1];
		String[] str = br.readLine().split(" ");

		for (int i = 0; i < n; i++) {
			arr[i + 1] = Integer.valueOf(str[i]);
		}

		System.out.println(dp(arr, dp, 0, 0));

	}

	static int dp(int[] arr, int[][] dp, int depth, int maxNum) {
		if (depth == arr.length)
			return 0;

		if (dp[depth][maxNum] != 0)
			return dp[depth][maxNum];

		int num = arr[depth];

		if (num > arr[maxNum])
			return dp[depth][maxNum] = Math.max(dp(arr, dp, depth + 1, depth) + num, dp(arr, dp, depth + 1, maxNum));

		return dp[depth][maxNum] = dp(arr, dp, depth + 1, maxNum);
	}
}
