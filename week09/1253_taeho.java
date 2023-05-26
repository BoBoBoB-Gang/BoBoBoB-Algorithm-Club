import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Baek1253 {
    static int n;
    static int[] numbers;
    public static void main(String[] args) throws IOException {
        input();
        Arrays.sort(numbers);
        int answer = 0;
        for(int i=0 ;i<n; i++){
            int target = numbers[i];
            int left = 0;
            int right = n-1;
            while(left < right){
                int num1 = numbers[left];
                int num2 = numbers[right];
                if(num1 + num2 == target && left != i && right != i){
                    answer++;
                    break;
                }
                if(num1 + num2 < target){
                    left++;
                }else if(num1 + num2 > target){
                    right--;
                }else if(left == i){
                    left++;
                }else{
                    right--;
                }
            }
        }
        System.out.println(answer);
    }

    public static void input() throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(bf.readLine());
        numbers = new int[n];
        StringTokenizer st = new StringTokenizer(bf.readLine());
        for(int i=0; i<n; i++){
            int num = Integer.parseInt(st.nextToken());
            numbers[i] = num;
        }

    }
}
