import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		/**
		 * BOJ1699 제곱수의 합
		 * 어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다. ex) 11 = 3^2+1^2+1^2 => 3 개의 제곱수로 이루어져있다.
		 *
		 * 제곱수의 개수는
		 * 최소 1개부터 '라그라그랑주 네 제곱수 정리' 에 의해 최대 4개까지 있다.
		 *
		 * 1개의 제곱수로 이루어진 경우는 그 수가 어떤 수의 제곱일 경우 밖에 없다. ex) 1^1 = 1, 2^2 = 4, 3^3 = 9, 4^4 = 16
		 *  == 그 수 자체가 제곱수이다.
		 *
		 * 제곱수가 아닌 수는 다른 수들을 더해서 만들어야한다.
		 *
		 * 만약 N 이 7 일 경우
		 * 1 + 6, 2 + 5, 3 + 4 총 3가지 식이 있는데
		 *
		 * 이 때
		 * 제곱수의 합은 최대 4이기 때문에
		 * 식에 제곱수를 포함한 경우
		 * 1 + 1 = 2
		 * 1 + 2 = 3
		 * 1 + 3 = 4
		 *
		 * 식에 제곱수를 포함하지 않은 경우
		 * 2 + 2 = 4
		 *
		 * 식에 제곱수를 포함한 경우 최소 값이 보장된다.
		 *
		 */


		int n = Integer.valueOf(br.readLine());
		int[] arr = new int[100001];

		// 10만 이하의 제곱수는 제곱수의 최소 개수가 1
		{
			int cnt = 1;
			while (cnt * cnt <= 100000) {
				arr[cnt * cnt] = 1;
				cnt++;
			}
		}

		for (int i = 1; i <= 100000; i++) {
			// 제곱수의 최소 개수가 입력되지 않은 경우에만 == 제곱수가 아니 경우
			if (arr[i] == 0) {
				int cnt = 1;

				arr[i] = i;

				while (cnt * cnt < i) {
					// i 보다 작은 제곱수 + (i - i 보다 작은 제곱수)
					arr[i] = Math.min(arr[i], arr[cnt * cnt] + arr[i - cnt * cnt]);
					cnt++;
				}
			}
		}

		System.out.println(arr[n]);
	}
}
