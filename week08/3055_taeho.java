import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Baek3055 {
    static class Node{
        int x;
        int y;
        int time;
        public Node(int x, int y, int time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }
    }
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    static int r;
    static int c;
    static char[][] matrix;
    static int[] start;
    static int[] end;
    static List<int[]> waters = new ArrayList<>();
    public static void waterFlood(){
        List<int[]> temp = new ArrayList<>();
        for(int[] water : waters){
            for(int i=0; i<4; i++){
                int newX = water[0] + dx[i];
                int newY = water[1] + dy[i];
                if(0<=newX && newX<r && 0<=newY && newY<c && (matrix[newX][newY] == '.' || matrix[newX][newY] == 'S')){
                    matrix[newX][newY] = '*';
                    temp.add(new int[] {newX, newY});
                }
            }
        }
        waters = temp;
    }
    public static int bfs(){
        Queue<Node> q = new ArrayDeque<>();
        q.add(new Node(start[0],start[1], 0));
        int lastTime = 0;
        while(!q.isEmpty()){
            Node curNode = q.poll();
            if(lastTime != curNode.time){
                waterFlood();
                lastTime = curNode.time;
            }
            if(matrix[curNode.x][curNode.y] == '*') continue;
            if(curNode.x == end[0] && curNode.y == end[1]){
                return curNode.time;
            }

            for(int i=0; i<4; i++){
                int newX = curNode.x + dx[i];
                int newY = curNode.y + dy[i];
                if(0<=newX && newX<r && 0<=newY && newY<c && (matrix[newX][newY] == '.' || matrix[newX][newY] == 'D')){
                    if(matrix[newX][newY] == '.')
                        matrix[newX][newY] = 'S';
                    q.add(new Node(newX, newY, curNode.time+1));
                }
            }
        }
        return -1;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        matrix = new char[r][c];
        for(int i=0; i<r; i++){
            String input = bf.readLine();
            for(int j=0; j<c; j++){
                matrix[i][j] = input.charAt(j);
                if(input.charAt(j) == 'D') end = new int[] {i,j};
                else if(input.charAt(j) == 'S') start = new int[] {i,j};
                else if(input.charAt(j) == '*') waters.add(new int[] {i,j});
            }
        }
        int result = bfs();
        if(result == -1){
            System.out.println("KAKTUS");
        }else{
            System.out.println(result);
        }
    }
}
