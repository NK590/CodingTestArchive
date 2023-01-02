import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int num = 1000;
		int[] arr = new int[num+1];

		arr[1] = 1;
		arr[2] = 3;


		for(int i = 3; i <= 1000; i++) {
			arr[i] = (arr[i-1]  + arr[i-2] * 2) % 10007;
		}

		int cnt = Integer.valueOf(br.readLine());


		System.out.println(arr[cnt]);


	}
}
