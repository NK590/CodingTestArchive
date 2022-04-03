package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Boj16639 {
    static int N;
    static int dpMax[][];
    static int dpMin[][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        String str = br.readLine();

        dpMax = new int[N][N];
        dpMin = new int[N][N];
        for (int i = 0; i < N; i += 2) {
            for (int j = 0; j < N; j += 2) {
                dpMax[i][j] = Integer.MIN_VALUE;
                dpMin[i][j] = Integer.MAX_VALUE;
            }
        }

        for (int i = 0; i < N; i += 2) {
            dpMax[i][i] = dpMin[i][i] = str.charAt(i) - '0';
        }

        for (int k = 2; k < N; k += 2) {
            for (int i = 0; i < N - k; i += 2) {

                int candidates[] = new int[4];
                for (int j = i + 1; j < i + k; j += 2) {
                    char ch = str.charAt(j);
                    candidates[0] = Calculate(dpMax[i][j - 1], dpMax[j + 1][i + k], ch);
                    candidates[1] = Calculate(dpMax[i][j - 1], dpMin[j + 1][i + k], ch);
                    candidates[2] = Calculate(dpMin[i][j - 1], dpMax[j + 1][i + k], ch);
                    candidates[3] = Calculate(dpMin[i][j - 1], dpMin[j + 1][i + k], ch);

                    Arrays.sort(candidates);
                    dpMax[i][i + k] = Math.max(dpMax[i][i + k], candidates[3]);
                    dpMin[i][i + k] = Math.min(dpMin[i][i + k], candidates[0]);
                }
            }
        }
        System.out.println(dpMax[0][N - 1]);
    }

    static int Calculate(int a, int b, char c) {
        if (c == '+') {
            return a + b;
        } else if (c == '-') {
            return a - b;
        } else if (c == '*') {
            return a * b;
        }
        return 0;
    }
}