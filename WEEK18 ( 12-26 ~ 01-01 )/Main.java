package cordingTest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {

	static int[] x = { 0, 1, 0, -1 }; // 동, 남, 서, 북
	static int[] y = { 1, 0, -1, 0 }; // 동, 남, 서, 북

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] str;
		int n = Integer.valueOf(br.readLine());
		int[][] field = new int[n][n]; // 0 빈칸, 1 뱀, 2 사과
		int k = Integer.valueOf(br.readLine());

		Deque<int[]> deque = new ArrayDeque<>();
		int[] head = { 0, 0 };
		field[0][0] = 1;
		{
			int[] temp = { 0, 0 };
			deque.addFirst(temp);
		}

		for (int i = 0; i < k; i++) {
			str = br.readLine().split(" ");
			int a = Integer.valueOf(str[0]) - 1;
			int b = Integer.valueOf(str[1]) - 1;
			field[a][b] = 2;
		}

		int l = Integer.valueOf(br.readLine());
		int p = 0;
		int cnt = 0;
		str = br.readLine().split(" ");
		int X = Integer.valueOf(str[0]);
		String C = str[1];

		while (true) {
			cnt++;
			if (!(head[0] + x[p] >= 0 && head[0] + x[p] < n && head[1] + y[p] >= 0 && head[1] + y[p] < n))
				break;

			int type = field[head[0] + x[p]][head[1] + y[p]];
			if (type == 1) {
				break;
			} else {
				head[0] = head[0] + x[p];
				head[1] = head[1] + y[p];
				int[] temp = { head[0], head[1] };
				field[head[0]][head[1]] = 1;
				deque.addFirst(temp);
				if (type == 0) {
					temp = deque.pollLast();
					field[temp[0]][temp[1]] = 0;
				}
			}

			if (cnt == X) {
				if ("L".equals(C)) {
					p = (p - 1 + 4) % 4;
				} else if ("D".equals(C)) {
					p = (p + 1) % 4;
				}

				if (l > 1) {
					str = br.readLine().split(" ");
					X = Integer.valueOf(str[0]);
					C = str[1];
					l--;
				}
			}
		}

		System.out.println(cnt);
	}
}
