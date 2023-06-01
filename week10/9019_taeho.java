import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baek9019 {
    static class DSLR{
        int num;
        String s;
        public DSLR(int num, String s) {
            this.num = num;
            this.s = s;
        }
    }
    static int a,b;
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        int testcase = Integer.parseInt(bf.readLine());
        for(int i=0; i<testcase; i++){
            inputData();
            sb.append(BFS() + "\n");
        }
        outputData();
    }
    public static int cal(int num, char dslr){
        switch (dslr){
            case 'D':
                return num*2%10000;
            case 'S':
                num--;
                return num < 0 ? 9999 : num;
            case 'L':
                return num*10%10000 + num*10/10000;
            case 'R':
                return num/10 + num%10*1000;
        }
        return num;
    }
    public static String BFS() {
        boolean[] visited = new boolean[10000];
        Queue<DSLR> q = new ArrayDeque<>();
        q.add(new DSLR(a, ""));
        while(!q.isEmpty()) {
            DSLR dslr = q.poll();
            if(dslr.num == b){
                return dslr.s;
            }
            for(char c: "DSLR".toCharArray()){
                int num = cal(dslr.num, c);
                if(!visited[num]) {
                    visited[num] = true;
                    q.add(new DSLR(num, dslr.s + c));
                }
            }

        }
        return "";
    }
    public static void inputData() throws IOException{
        StringTokenizer st = new StringTokenizer(bf.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
    }
    public static void outputData(){
        System.out.print(sb);
    }
}
