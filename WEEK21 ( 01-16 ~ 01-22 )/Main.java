package cordingTest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] str = br.readLine().split(" ");
		int N = Integer.valueOf(str[0]);
		int M = Integer.valueOf(str[1]);
		int D = Integer.valueOf(str[2]);
		int E = Integer.valueOf(str[3]);

		List<List<int[]>> graph = new ArrayList<>();
		int[] height = new int[N + 1];
		PriorityQueue<Line> pq = new PriorityQueue<>();
		// 각 노드의 방문 여부
		boolean[] visited = new boolean[N + 1];
		// 집에서 산으로 올라가는 길의 최단 경로
		long[] upDistance = new long[N + 1];
		// 산에서 학교로 내려가는 길의 최단 경로
		long[] downDistance = new long[N + 1];

		long answer = 0;
		boolean isPossible = false;

		for (int i = 0; i <= N; i++) {
			graph.add(new ArrayList<int[]>());
		}

		str = br.readLine().split(" ");

		Arrays.fill(upDistance, Long.MAX_VALUE);
		Arrays.fill(downDistance, Long.MAX_VALUE);
		Arrays.fill(visited, false);

		for (int i = 0; i < N; i++) {
			height[i + 1] = Integer.valueOf(str[i]);
		}

		// 각 노드의 그래프 생성
		for (int i = 0; i < M; i++) {
			str = br.readLine().split(" ");
			int a = Integer.valueOf(str[0]);
			int b = Integer.valueOf(str[1]);
			int n = Integer.valueOf(str[2]);

			// a 에서 b 까지 거리 n
			graph.get(a).add(new int[] { b, n });

			// b 에서 a 까지 거리 n
			graph.get(b).add(new int[] { a, n });
		}

		// 집에서 산으로 올라가는 경우의 다익스트라 최단 경로 구하기
		upDistance[1] = 0;
		pq.add(new Line(1, 0));

		while (!pq.isEmpty()) {
			Line line = pq.poll();
			int a = line.node;

			// 이미 방문한 노드이면 통과
			if (visited[a])
				continue;
			visited[a] = true;

			// 노드의 그래프 탐색
			for (int[] x : graph.get(a)) {
				int b = x[0];
				int n2 = x[1];

				// b 가 a 보다 높지않으면 통과
				if (!(height[b] > height[a]))
					continue;

				if (upDistance[b] > upDistance[a] + n2) {
					upDistance[b] = upDistance[a] + n2;
					pq.add(new Line(b, upDistance[a] + n2));
				}
			}
		}

		// 방문한 노드 표시 초기화
		Arrays.fill(visited, false);

		// 산에서 학교로 내려가는 경우의 다익스트라 최단 경로 구하기
		downDistance[N] = 0;
		pq.add(new Line(N, 0));

		while (!pq.isEmpty()) {
			Line line = pq.poll();
			int a = line.node;

			// 이미 방문한 노드이면 통과
			if (visited[a])
				continue;
			visited[a] = true;

			// 노드의 그래프 탐색
			for (int[] x : graph.get(a)) {
				int b = x[0];
				int n2 = x[1];

				// b 가 a 보다 높지않으면 통과
				if (!(height[b] > height[a]))
					continue;

				if (downDistance[b] > downDistance[a] + n2) {
					downDistance[b] = downDistance[a] + n2;
					pq.add(new Line(b, downDistance[a] + n2));
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			if (downDistance[i] != Long.MAX_VALUE && upDistance[i] != Long.MAX_VALUE) {
				long achi = (height[i] * E) - ((downDistance[i] + upDistance[i]) * D);

				if (!isPossible) {
					answer = achi;
					isPossible = true;
				} else {
					answer = Math.max(answer, achi);
				}

			}
		}

		if (isPossible) {
			System.out.println(answer);
		} else {
			System.out.println("Impossible");
		}
	}

	static class Line implements Comparable<Line> {
		int node;
		long distance;

		Line(int node, long distance) {
			this.node = node;
			this.distance = distance;
		}

		@Override
		public int compareTo(Line o) {
			return (int)(this.distance - o.distance);
		}

	}

}

