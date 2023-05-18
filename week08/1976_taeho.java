import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.IntStream;

public class Baek1976 {
    static int n;
    static int m;
    static int[] tourList;
    static int[] parent;
    public static void main(String[] args) throws IOException {
        inputData();
        boolean flag = false;
        Set<Integer> s = new HashSet<>();
        for(int t : tourList){
            s.add(parent[t]);
            if(s.size() > 1) {
                flag = true;
                break;
            }
        }
        if(flag) System.out.println("NO");
        else System.out.println("YES");
    }
    public static int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    public static void union(int a, int b){
        int parentA = find(a);
        int parentB = find(b);

        if(parentA > parentB){
            parent[parentA] = parentB;
        }else if(parentA < parentB){
            parent[parentB] = parentA;
        }
    }
    public static void inputData() throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(bf.readLine());
        m = Integer.parseInt(bf.readLine());
        parent = IntStream.rangeClosed(0,n-1).toArray();
        tourList = new int[m];
        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(bf.readLine());
            for(int j=0; j<n; j++){
                int num = Integer.parseInt(st.nextToken());
                if(num == 1){
                    union(i,j);
                }
            }
        }

        StringTokenizer st = new StringTokenizer(bf.readLine());
        Set<Integer> s = new HashSet<>();
        for(int i=0; i<m; i++){
            tourList[i] = Integer.parseInt(st.nextToken())-1;
        }

    }
}