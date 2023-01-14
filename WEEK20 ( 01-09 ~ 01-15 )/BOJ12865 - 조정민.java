package cordingTest2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// 남은 무게가 0 이거나 물건이 없는 경우
		String[] str = br.readLine().split(" ");
		int n = Integer.valueOf(str[0]);
		int k = Integer.valueOf(str[1]);
		int[][] arr = new int[n][2];
		int[][] dp = new int[n][k + 1];

		for (int i = 0; i < n; i++) {
			str = br.readLine().split(" ");
			arr[i][0] = Integer.valueOf(str[0]);
			arr[i][1] = Integer.valueOf(str[1]);
		}

//		Arrays.sort(arr, (int[] o1, int[] o2) -> {return o1[0] - o2[0];});

		System.out.println(fn(n - 1, k, arr, dp));
	}

	static int fn(int n, int k, int[][] arr, int[][] dp) {
		if (k == 0 || n < 0)
			return 0;

		if (dp[n][k] != 0)
			return dp[n][k];

		if (arr[n][0] > k)
			return dp[n][k] = fn(n - 1, k, arr, dp);

		return dp[n][k] = Math.max(fn(n - 1, k, arr, dp), fn(n - 1, k - arr[n][0], arr, dp) + arr[n][1]);
	}
}
