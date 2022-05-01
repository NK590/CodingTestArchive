import java.io.BufferedReader;

import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        dfs("",1,sb , n);
        System.out.println(sb);
    }

    private static void dfs(String curr , int idx , StringBuilder sb , int  n ){

        if(idx == n + 1){
            sb.append(curr+"\n");
            return;
        }
        for(int  i = 1 ; i < 10 ; i++){
            if(isPrime(Integer.parseInt(curr+i))){
                dfs(curr+i,idx+1,sb , n );
            }
        }
    }

    private static boolean isPrime(int num){
        if(num == 0 || num == 1){
            return false;
        }
        for(int i = 2 ; i < num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

}