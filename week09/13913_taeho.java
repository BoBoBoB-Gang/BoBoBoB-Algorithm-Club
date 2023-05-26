import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Baek13913 {

    static class Walk{
        int v;
        int t;

        public Walk(int v, int t) {
            this.v = v;
            this.t = t;
        }
    }
    static int n,k,answer;
    static List<Integer> history = new ArrayList<>();
    static int[] move = new int[200001];

    public static int bfs(){
        Queue<Walk> q = new ArrayDeque<>();
        q.add(new Walk(n, 0));
        move[n] = 0;
        while(!q.isEmpty()){
            Walk curWalk = q.poll();

            if(curWalk.v-1 >= 0 && move[curWalk.v-1] == -1){
                move[curWalk.v-1] = curWalk.t+1;
                q.add(new Walk(curWalk.v-1, curWalk.t+1));
            }
            if(curWalk.v*2 <= 2*k  && move[curWalk.v*2] == -1){
                move[curWalk.v*2] = curWalk.t+1;
                q.add(new Walk(curWalk.v*2, curWalk.t+1));
            }
            if(curWalk.v+1 <= k+1  && move[curWalk.v+1] == -1){
                move[curWalk.v+1] = curWalk.t+1;
                q.add(new Walk(curWalk.v+1, curWalk.t+1));
            }
        }
        return move[k];
    }
    public static void tracing(int cnt, int v){
        if (cnt == answer){
            return;
        }
        if(v%2 == 0 && move[v/2] == answer-cnt-1){
            history.add(v/2);
            tracing(cnt+1, v/2);
        }else if(v-1 >= 0 && move[v-1] == answer-cnt-1){
            history.add(v-1);
            tracing(cnt+1, v-1);
        }else if(move[v+1] == answer-cnt-1){
            history.add(v+1);
            tracing(cnt+1, v+1);
        }
    }
    public static void main(String[] args) throws IOException {
        input();
        answer = bfs();
        history.add(k);
        tracing(0, k);
        output();
    }
    public static void input() throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        Arrays.fill(move, -1);
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
    }
    public static void output(){
        StringBuilder sb = new StringBuilder();
        System.out.println(answer);
        for(int i=history.size()-1; i>=0; i--){
            sb.append(history.get(i) + " ");
        }
        System.out.println(sb);
    }
}
