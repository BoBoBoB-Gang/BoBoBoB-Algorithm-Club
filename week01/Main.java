import java.io.*;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.PriorityQueue;



public class Main {
    public static int limit = 100;
    public static int n = 3;
    public static int m = 3;
    public static int[][] A = new int[100][100];
    public static void sortR() {
        for(int row=0; row<n; row++) {
            int cnt[] = new int[101];
            PriorityQueue<Tuple> pq = new PriorityQueue<>();
            for(int col=0; col<m; col++) {
                int curNum = A[row][col];
                if (curNum == 0) continue;
                cnt[curNum]++;
                A[row][col] = 0;
            }
            for(int i=1; i<101; i++) {
                if (cnt[i] == 0) continue;
                Tuple tuple = new Tuple(i, cnt[i]);
                pq.add(tuple);
            }
            int col = 0;
            while(!pq.isEmpty()) {
                Tuple tuple = pq.poll();
                A[row][col++] = tuple.getNum();
                A[row][col++] = tuple.getCnt();
            }
            m = Math.max(m,col);
        }
    }
    public static void sortC() {
        for(int col=0; col<m; col++) {
            int cnt[] = new int[101];
            PriorityQueue<Tuple> pq = new PriorityQueue<>();
            for(int row=0; row<n; row++) {
                int curNum = A[row][col];
                if(curNum==0) continue;
                cnt[curNum]++;
                A[row][col] = 0;
            }
            for(int i=1; i<101; i++) {
                if (cnt[i] == 0) continue;
                Tuple tuple = new Tuple(i, cnt[i]);
                pq.add(tuple);
            }
            int row = 0;
            while(!pq.isEmpty()) {
                Tuple tuple = pq.poll();
                A[row++][col] = tuple.getNum();
                A[row++][col] = tuple.getCnt();
            }
            n= Math.max(n,row);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int r = Integer.parseInt(st.nextToken())-1;
        int c = Integer.parseInt(st.nextToken())-1;
        int k = Integer.parseInt(st.nextToken());

        for(int i=0; i<3; i++) {
            StringTokenizer array = new StringTokenizer(br.readLine());
            for(int j=0; j<3; j++) {
                A[i][j] = Integer.parseInt(array.nextToken());
            }
        }

        int time = 0;
        while(time<=limit) {
            if(A[r][c]==k) break;
            time++;
            if(n >= m) sortR();
            else sortC();
        }

        if(time>limit) System.out.println(-1);
        else System.out.println(time);

    }
    public static class Tuple implements Comparable<Tuple> {
        private int num;
        private int cnt;
        public Tuple(int num, int cnt) {
            this.num = num;
            this.cnt = cnt;
        }

        public int getCnt() { return cnt; }
        public int getNum() { return num; }
        @Override
        public int compareTo(Tuple target) {
            if(this.cnt > target.cnt) return 1;
            else if(this.cnt < target.cnt) return -1;
            else if (this.num > target.num) return 1;
            return -1;
        }
    }
}