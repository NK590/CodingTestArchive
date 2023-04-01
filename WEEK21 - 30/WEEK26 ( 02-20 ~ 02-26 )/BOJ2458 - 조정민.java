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
		int[][] graph = new int[N + 1][N + 1];
		int answer = 0;

		for (int i = 0; i < M; i++) {
			str = br.readLine().split(" ");
			int a = Integer.valueOf(str[0]);
			int b = Integer.valueOf(str[1]);

			graph[a][b] = 1;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)
					continue;

				for (int k = 1; k <= N; k++) {
					if (j == k)
						continue;

					if (graph[j][i] == 0 || graph[i][k] == 0)
						continue;

					graph[j][k] = 1;
				}
			}
		}


		Loop1 : for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i != j && graph[i][j] == 0 && graph[j][i] == 0)
					continue Loop1;
			}

			answer++;
		}

		System.out.println(answer);
	}
}
