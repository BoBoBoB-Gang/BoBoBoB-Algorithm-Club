import java.io.*;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Queue;

public class Main {

    public static int N = 0;
    public static int M = 0;
    public static int maxEmpty = -1;
    public static int[][] map = new int[10][10];
    public static int[][] dir = {{1,0},{-1,0},{0,-1},{0,1}};
    public static ArrayList<Tuple> empties = new ArrayList<>();
    public static void main(String[] args) throws IOException {

        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for(int i=0; i<N; i++) {
            StringTokenizer array = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(array.nextToken());
                if (map[i][j] == 0) {
                    Tuple empty = new Tuple(i, j);
                    empties.add(empty);
                }
            }
        }
        // problem solving
        boolean[] visited = new boolean[empties.size()];
        solving(visited,0, empties.size(),3);
        System.out.println(maxEmpty);
    }

    static void solving(boolean[] visited, int start, int n, int r) {
        if(r==0) {
            int[][] newMap = new int[N][M];
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    newMap[i][j] = map[i][j];
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    if(map[i][j]==2) dfs(newMap,i,j);
            int cnt = 0;
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    if(newMap[i][j]==0) cnt++;
            maxEmpty = Math.max(maxEmpty,cnt);
            return;
        }
        for(int i=start; i<n; i++) {
            visited[i] = true;
            Tuple cann = empties.get(i);
            map[cann.getFirst()][cann.getSecond()] = 1;
            solving(visited, i+1, n, r-1);
            map[cann.getFirst()][cann.getSecond()] = 0;
            visited[i] = false;
        }
    }

    public static void dfs(int[][] newMap, int x, int y) {
        boolean[][] checked = new boolean[N][M];
        Queue<Tuple> queue = new LinkedList<>();
        queue.add(new Tuple(x,y));
        while(!queue.isEmpty()) {
            Tuple curCell = queue.poll();
            for(int i=0; i<4; i++) {
                int r = curCell.getFirst()+dir[i][0];
                int c = curCell.getSecond()+dir[i][1];
                if(!(r>=0 && r<N && c>=0 && c<M)) continue;
                if(checked[r][c]) continue;
                if(newMap[r][c]==1) continue;
                queue.add(new Tuple(r,c));
                newMap[r][c] = 2;
                checked[r][c] = true;
            }
        }
    }

    public static class Tuple {
        private int first;
        private int second;

        public Tuple(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int getFirst() { return first; }
        public int getSecond() { return second; }
    }
}