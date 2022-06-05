import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;

public class Main {

    /***
     * https://www.acmicpc.net/problem/1759
     */

    private static char[] vowels = {'a','e','i','o','u'}; // 모음 리스트

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int l = Integer.parseInt(input[0]); //  길이
        int c = Integer.parseInt(input[1]); // 문자 개수
        String[] src = br.readLine().split(" ");
        char[] tmp = new char[c];
        Stack<Character> result= new Stack<>();
        for(int i = 0 ; i < c ; i++){
            tmp[i] = src[i].charAt(0);
        }
        Arrays.sort(tmp);
        dfs(tmp,result,l,0,0);
    }


    private static void dfs(char[] tmp , Stack<Character> result , int l , int idx , int vowelNum ){
        if( l == 0 && vowelNum >= 1  && result.size()-vowelNum >=2 ){ // 문제조건이 모음의 개수 1이상 , 자음의 개수는 2이상
            printResult(result);
            return;
        }
        if(idx >= tmp.length){
            return;
        }
        char x = tmp[idx]; // idx 위치의 문자를 포함시킬건지 여부
        result.push(x); // 포함시키고,
        if(isVowel(x)){ // 모음이라면 모음의 개수를 증가시켜서 파라미터로 넘김
            dfs(tmp,result,l-1,idx+1,vowelNum+1); // 다음인덱스로 이동
        }else{
            dfs(tmp,result,l-1,idx+1,vowelNum);
        }
        result.pop(); // 포함시키지않고,
        dfs(tmp,result,l,idx+1, vowelNum); // 다음인덱스로이동
    }

    // 모음인지 판단하는 method
    private static boolean isVowel(char x) {
        for(int i = 0 ; i < vowels.length;  i++){
            if(vowels[i] == x){
                return true;
            };
        }
        return false;
    }

    private static void printResult(Stack<Character> result) {
        result.stream().forEach(System.out::print);
        System.out.println();
    }
}
