// 백준 1759 - 암호 만들기

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
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
        int L = Integer.valueOf(str[0]);
        int C = Integer.valueOf(str[1]);
        str = br.readLine().split(" ");
        boolean[] gather = new boolean[C];
        boolean[] contains = new boolean[C];
        List<String> gatherList = Arrays.asList("a", "e", "u", "i", "o");

        Arrays.fill(gather, false);
        Arrays.sort(str);

        for(int i = 0; i < C; i++) {
            if(gatherList.contains(str[i]))
                gather[i] = true;
        }

        fn(L, 0, 0, 0, str, gather, contains, bw);

        bw.flush();
        bw.close();
    }

    public static void fn(int L, int cnt, int a, int idx, String[] str, boolean[] gather, boolean[] contains, BufferedWriter bw) throws IOException {
        if(L == cnt) {
            if(a == 0 || cnt - a < 2)
                return;

            for(int i = 0; i < str.length; i++) {
                if(contains[i])
                    bw.append(str[i]);
            }

            bw.append("\n");
            return;
        }

        if(idx == str.length)
            return;

        contains[idx] = true;
        fn(L, cnt+1, gather[idx] ? a+1 : a, idx+1, str, gather, contains, bw);
        contains[idx] = false;

        fn(L, cnt, a, idx+1, str, gather, contains, bw);
    }
}
