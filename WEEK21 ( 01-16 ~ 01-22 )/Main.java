package cordingTest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] str = br.readLine().split(" ");
		int N = Integer.valueOf(str[0]);
		int M = Integer.valueOf(str[1]);

		List<List<int[]>> graph = new ArrayList<>();

		// 각 노드 까지 걸리는 최소 값 => MAX_VALUE 로 초기화
		int[] cost = new int[N + 1];
		Arrays.fill(cost, Integer.MAX_VALUE);
		// 각 노드 까지 걸리는 최단 경로
		List<List<Integer>> route = new ArrayList<>();
		// 방문 여부 => false 로 초기화
		boolean[] visited = new boolean[N + 1];
		Arrays.fill(visited, false);
		// 방문 하지 않은 노드 중 가장 코스트가 낮은 노드를 찾기 위한 우선순위 큐
		PriorityQueue<Line> pq = new PriorityQueue<>();

		List<int[]> answer = new ArrayList<>();
		int[][] map = new int[N + 1][N + 1];

		// 그래프 생성
		for (int i = 0; i <= N; i++) {
			graph.add(new ArrayList<>());
			route.add(new ArrayList<>());
		}

		// 네트워크 정보 입력
		for (int i = 0; i < M; i++) {
			str = br.readLine().split(" ");
			int A = Integer.valueOf(str[0]);
			int B = Integer.valueOf(str[1]);
			int C = Integer.valueOf(str[2]);

			// A 번 노드에서 B 번 노드까지 걸리는 시간 C
			graph.get(A).add(new int[] { B, C });
			// B 번 노드에서 A 번 노드까지 걸리는 시간 C
			graph.get(B).add(new int[] { A, C });
		}

		// 루트 로드 초기화 => 1번 노드의 그래프를 우선순위 큐에 삽입
		cost[1] = 0;
		route.get(1).add(1);
		pq.add(new Line(1, 0));

		while (!pq.isEmpty()) {
			Line line = pq.poll();
			int A = line.node;

			// 이미 방문한 노드 일 경우 통과
			if (visited[A])
				continue;

			// 현재 노드 방문 처
			visited[A] = true;

			// 노드의 모든 간선 조사
			for (int[] x : graph.get(A)) {
				int B = x[0];
				int toCost = x[1];

				// 현재 저장된 B 노드 까지 가는 비용이 A 노드에서 B 노드 까지 가는 비용보다 큰 경우 갱
				if (cost[B] > cost[A] + toCost) {
					cost[B] = cost[A] + toCost;
					pq.add(new Line(B, cost[A] + toCost));

					route.get(B).clear();
					for (int y : route.get(A)) {
						route.get(B).add(y);
					}
					route.get(B).add(B);

				}
			}

		}

		for (List<Integer> x : route) {
			for (int i = 1; i < x.size(); i++) {
				if (map[x.get(i)][x.get(i - 1)] == 0 && map[x.get(i - 1)][x.get(i)] == 0) {
					answer.add(new int[] { x.get(i - 1), x.get(i) });
					map[x.get(i)][x.get(i - 1)] = 1;
					map[x.get(i - 1)][x.get(i)] = 1;
				}
			}
		}

		bw.write(answer.size() + "\n");
		for (int[] x : answer) {
			bw.write(x[0] + " " + x[1] + "\n");
		}

		bw.flush();
		bw.close();

	}

	static class Line implements Comparable<Line> {
		int node;
		int cost;

		Line(int node, int cost) {
			this.node = node;
			this.cost = cost;
		}

		@Override
		public int compareTo(Line o) {
			return this.cost - o.cost;
		}

	}

}

