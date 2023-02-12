package cordingTest2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] str = br.readLine().split(" ");
		int N = Integer.valueOf(str[0]); // 도시의 수
		int A = Integer.valueOf(str[1]); // 시작 도시
		int B = Integer.valueOf(str[2]); // 도착 도시
		int M = Integer.valueOf(str[3]); // 교통 수단의 개수

		boolean loop = false;
		long[] dist = new long[N];
		int[] money = new int[N];
		Arrays.fill(dist, Long.MIN_VALUE);

		List<int[]> graph = new ArrayList<>();

		for (int i = 0; i < M; i++) {
			str = br.readLine().split(" ");
			int a = Integer.valueOf(str[0]);
			int b = Integer.valueOf(str[1]);
			int c = Integer.valueOf(str[2]);

			graph.add(new int[] { a, b, c });
		}

		str = br.readLine().split(" ");
		for (int i = 0; i < N; i++) {
			money[i] = Integer.valueOf(str[i]);
		}

		dist[A] = money[A];

		for (int i = 0; i <= N; i++) {
			for (int[] x : graph) {
				int a = x[0];
				int b = x[1];
				int c = x[2];

				if (dist[a] != Long.MIN_VALUE && dist[b] < dist[a] + money[b] - c) {
					dist[b] = dist[a] + money[b] - c;

					if (i == N && availableRoute(graph, b, B, N)) {
						loop = true;
					}
				}
			}
		}

		System.out.println(loop ? "Gee" : dist[B] == Long.MIN_VALUE ? "gg" : dist[B]);
	}

	public static boolean availableRoute(List<int[]> graph, int from, int to, int N) {
		long[] dist = new long[N];
		Arrays.fill(dist, Long.MIN_VALUE);

		dist[from] = 0;

		for (int i = 0; i < N; i++) {
			for (int[] x : graph) {
				int a = x[0];
				int b = x[1];

				if(dist[a] != Long.MIN_VALUE)
					dist[b] = 0;
			}
		}

		return dist[to] == Long.MIN_VALUE ? false : true;
	}
}
