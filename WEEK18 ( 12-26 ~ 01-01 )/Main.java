package cordingTest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	
	static int[] X = { 1, 0, -1, 0 };
	static int[] Y = { 0, 1, 0, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.valueOf(st.nextToken());
		int m = Integer.valueOf(st.nextToken());
		int min = -1;

		int[][] field = new int[n][m];
		List<int[][]> list = new ArrayList<>();
		int[][] temp = new int[n][m];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < m; j++) {
				field[i][j] = Integer.valueOf(st.nextToken());
			}
		}

		for (int i = 0; i < n; i++) {
			temp[i] = field[i].clone();
		}

		list.add(temp);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int num = field[i][j];

				if (num > 0 && num < 6) {
					list = fn(list, field, num, i, j);
				}
			}
		}

		for (int[][] l : list) {
			int c = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (l[i][j] == 0)
						c++;
				}
			}

			if (min == -1 || min > c)
				min = c;
		}

		System.out.println(min);
	}

	static List<int[][]> fn(List<int[][]> list, int[][] field, int n, int x, int y) {
		List<int[][]> resultList = new ArrayList<>();

		for (int[][] l : list) {
			int[][] p = null;
			
			// 감시카메라 번호별 감시 방향
			if (n == 1) {
				p = new int[][] { { 0 }, { 1 }, { 2 }, { 3 } };
			} else if (n == 2) {
				p = new int[][] { { 0, 2 }, { 1, 3 } };
			} else if (n == 3) {
				p = new int[][] { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 } };
			} else if (n == 4) {
				p = new int[][] { { 0, 1, 2 }, { 1, 2, 3 }, { 2, 3, 0 }, { 3, 0, 1 } };
			} else if (n == 5) {
				p = new int[][] { { 0, 1, 2, 3 } };
			}

			for (int[] a : p) {
				int[][] temp = copy(l);
				for (int b : a) {
					int c = 1;
					while (true) {
						int x2 = x + (X[b] * c);
						int y2 = y + (Y[b] * c);

						if (x2 < 0 || y2 < 0 || x2 >= field.length || y2 >= field[0].length)
							break;
						if (field[x2][y2] == 6)
							break;

						if (field[x2][y2] == 0)
							temp[x2][y2] = 7;
						c++;
					}
				}

				resultList.add(temp);
			}
		}

		return resultList;
	}

	static int[][] copy(int[][] list) {
		int[][] result = new int[list.length][list[0].length];

		for (int i = 0; i < list.length; i++) {
			result[i] = list[i].clone();
		}

		return result;
	}
}
