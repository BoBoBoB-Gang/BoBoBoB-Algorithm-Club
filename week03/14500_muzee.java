import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int res = -1;
    static int maxVal = -1;
    static int[][] paper = new int[500][500];
    static int[][] dir = {{-1,0},{0,1},{1,0},{0,-1}};

    public static void main(String[] args) throws IOException {
        // INPUT
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer  st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for(int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0 ; j<M; j++)
                paper[i][j] = Integer.parseInt(st.nextToken());
        }

        // SOLVING
        int[][] visited = new int[N][M];
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                maxVal = -1;
                visited[i][j] = 1;
                tetro(i,j,paper[i][j],0,visited);
                visited[i][j] = 0;
                theOtherShape(i,j,paper[i][j]);
                res = Math.max(res, maxVal);
            }
        }
        System.out.println(res);
    }

    static public void tetro(int r, int c, int sum, int depth, int[][] visited) {
        if(depth==3) {
            maxVal = Math.max(maxVal, sum);
            return;
        }
        for(int i=0; i<4; i++) {
            int row = r+dir[i][0];
            int col = c+dir[i][1];
            if(!(0<=row && row<N && 0<=col && col<M)) continue;
            if(visited[row][col]==1) continue;
            visited[row][col] = 1;
            tetro(row,col,sum+paper[row][col],depth+1, visited);
            visited[row][col] = 0;
        }
    }

    static public void theOtherShape(int r, int c, int b) {
        for(int i=0; i<4; i++) {
            int sum = b;
            for(int j=0; j<4; j++) {
                if(i==j) continue;
                int row = r+dir[j][0];
                int col = c+dir[j][1];
                if(!(row>=0&&row<N&&col>=0&&col<M)) {
                    sum = -1;
                    break;
                }
                sum += paper[row][col];
            }
            maxVal = Math.max(maxVal,sum);
        }
    }
}