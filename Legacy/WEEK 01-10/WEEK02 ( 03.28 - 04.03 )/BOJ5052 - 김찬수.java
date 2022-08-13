import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for(int i =0 ; i < t; i++){
            if( isConsistent(br) ){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
         }
    }

    private static boolean isConsistent(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        String[] phoneList = new String[n];
        for(int i = 0; i < n; i++){  // n : 1 ~ 10000
            phoneList[i] =  br.readLine();
        }
        Arrays.sort(phoneList);//정렬수행

        for(int  i = 0 ; i < n-1 ; i ++){
            if(phoneList[i+1].startsWith(phoneList[i])){ //
                return false;
            };
        }
        return true;
    }
}