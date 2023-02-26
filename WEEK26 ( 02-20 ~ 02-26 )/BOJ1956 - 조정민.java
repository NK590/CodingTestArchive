import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] str = br.readLine().split(" ");
		int N = Integer.valueOf(str[0]);
		int M = Integer.valueOf(str[1]);
		long[][] dist = new long[N + 1][N + 1];
		int[][] graph = new int[N + 1][N + 1];

		for (int i = 0; i < M; i++) {
			str = br.readLine().split(" ");
			int a = Integer.valueOf(str[0]);
			int b = Integer.valueOf(str[1]);
			int c = Integer.valueOf(str[2]);

			graph[a][b] = c;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] == 0) {
					dist[i][j] = Long.MAX_VALUE;
				} else {
					dist[i][j] = graph[i][j];
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {

					if (dist[j][i] == Long.MAX_VALUE || dist[i][k] == Long.MAX_VALUE)
						continue;

					if (dist[j][k] > dist[j][i] + dist[i][k]) {
						dist[j][k] = dist[j][i] + dist[i][k];
					}
				}
			}
		}

		long min = Long.MAX_VALUE;

		for (int i = 1; i <= N; i++) {
			min = Math.min(dist[i][i], min);
		}

		System.out.println(min == Long.MAX_VALUE ? -1 : min);
	}
}
