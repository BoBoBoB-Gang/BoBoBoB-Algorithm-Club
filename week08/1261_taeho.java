import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Baek1261 {
    static class Node{
        int x;
        int y;
        int t;
        public Node(int x, int y, int t) {
            this.x = x;
            this.y = y;
            this.t = t;
        }
    }
    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};
    static char[][] matrix;
    static int n;
    static int m;
    static boolean[][] isVisit;
    public static void main(String[] args) throws IOException {
        inputData();
        outputData(bfs());
    }
    public static int bfs(){
        PriorityQueue<Node> q = new PriorityQueue<>(Comparator.comparingInt((Node N) -> N.t));
        q.add(new Node(0,0,0));
        isVisit[0][0] = true;
        while(!q.isEmpty()){
            Node curNode = q.poll();
            if(curNode.x == n-1 && curNode.y == m-1) return curNode.t;

            for(int i=0; i<4; i++){
                int newX = dx[i] + curNode.x;
                int newY = dy[i] + curNode.y;
                if(0<=newX && newX<n && 0<=newY && newY<m && !isVisit[newX][newY]){
                    isVisit[newX][newY] = true;
                    if(matrix[newX][newY] == '1'){
                        q.add(new Node(newX, newY, curNode.t+1));
                    }else {
                        q.add(new Node(newX, newY, curNode.t));
                    }
                }
            }
        }
        return -1;
    }
    public static void inputData() throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        matrix = new char[n][m];
        isVisit = new boolean[n][m];
        for(int i=0; i<n; i++){
            String input = bf.readLine();
            for(int j=0; j<input.length(); j++){
                matrix[i][j] = input.charAt(j);
            }
        }
    }
    public static void outputData(int result){
        System.out.println(result);
    }
}
