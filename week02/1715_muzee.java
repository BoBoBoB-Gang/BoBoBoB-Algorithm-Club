import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static PriorityQueue<Integer> pq = new PriorityQueue<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        if(N==1)
            System.out.println(0);
        else {
            for (int i = 0; i < N; i++) {
                int num = Integer.parseInt(br.readLine());
                pq.add(num);
            }
            int res = 0;
            for(int i=0; i<N-1; i++){
                int num1 = pq.poll();
                int num2 = pq.poll();
                res += num1+num2;
                pq.add(num1+num2);
            }
            System.out.println(res);
        }
    }
}