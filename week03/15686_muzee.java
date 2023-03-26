import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int res = Integer.MAX_VALUE;
    static ArrayList<Tuple> houses = new ArrayList<>();
    static ArrayList<Tuple> stores = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        // INPUT
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer  st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0 ; j<N; j++) {
                int info = Integer.parseInt(st.nextToken());
                if(info==1) houses.add(new Tuple(i,j));
                else if (info==2) stores.add(new Tuple(i,j));
            }
        }

        // SOLVING
        ArrayList<Tuple> survive = new ArrayList<>();
        combination(stores.size(), M, 0, survive);

        System.out.println(res);
    }

    static public void combination(int n, int r, int start, ArrayList<Tuple> survive) {
        if(r==0) {
            int sum = 0;
            for(Tuple house: houses)
                sum += house.getMinDist(survive);
            res = Math.min(res, sum);
            return;
        }
        for(int i=start; i<n; i++) {
            survive.add(stores.get(i));
            combination(n,r-1,i+1, survive);
            survive.remove(stores.get(i));
        }
    }

    static class Tuple {
        private int row, col;

        Tuple(int row, int col) {
            this.row = row;
            this.col = col;
        }

        public int getRow() {return row;}
        public int getCol() {return col;}

        public int getMinDist(ArrayList<Tuple> list) {
            int minDist = 10000;
            for(Tuple tuple: list)
                minDist = Math.min(minDist, Math.abs(row-tuple.getRow()) + Math.abs(col-tuple.getCol()));
            return minDist;
        }
    }
}