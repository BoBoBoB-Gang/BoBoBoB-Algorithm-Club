import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baek7579 {
    static int n, phoneMemory;
    static int[] appMemories;
    static int[] costs;
    static int[][] DP;
    static int sum=0;
    public static void main(String[] args) throws IOException {
        inputData();
        solve();
    }
    public static void solve(){
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(j - costs[i-1] >= 0){
                    DP[i][j] = Math.max(DP[i-1][j], DP[i-1][j-costs[i-1]] + appMemories[i-1]);
                }else {
                    DP[i][j] =DP[i - 1][j];
                }
            }
        }

        for(int i=0; i<=sum; i++){
            if(phoneMemory <= DP[n][i]){
                System.out.println(i);
                break;
            }
        }
    }
    public static void inputData() throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        n = Integer.parseInt(st.nextToken());
        phoneMemory = Integer.parseInt(st.nextToken());
        appMemories = new int[n];
        costs = new int[n];


        st = new StringTokenizer(bf.readLine());
        for(int i=0; i<n; i++){
            appMemories[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(bf.readLine());
        for(int i=0; i<n; i++){
            costs[i] = Integer.parseInt(st.nextToken());
            sum += costs[i];
        }
        DP = new int[n+1][sum+1];
    }
}
