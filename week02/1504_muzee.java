import java.io.*;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.PriorityQueue;
import java.util.ArrayList;
import java.util.Arrays;



public class Main {
    static int N = 0;
    static int E = -1;
    static int v1 = -1;
    static int v2 = -2;
    static ArrayList<ArrayList<Node>> list; // 인접리스트.
    static int[] dist; // 시작점에서 각 정점으로 가는 최단거리.
    static boolean[] check; // 방문 확인.
    static final int INF = 200000000;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        list = new ArrayList<>();
        dist = new int[N + 1];
        check = new boolean[N + 1];

        Arrays.fill(dist, INF);

        for (int i = 0; i <= N; i++) {
            list.add(new ArrayList<>());
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            list.get(a).add(new Node(b, c));
            list.get(b).add(new Node(a, c));
        }

        StringTokenizer sttt = new StringTokenizer(br.readLine());
        v1 = Integer.parseInt(sttt.nextToken());
        v2 = Integer.parseInt(sttt.nextToken());

        int res1 = 0;
        res1 += dijkstra(1, v1);
        res1 += dijkstra(v1, v2);
        res1 += dijkstra(v2, N);

        int res2 = 0;
        res2 += dijkstra(1, v2);
        res2 += dijkstra(v2, v1);
        res2 += dijkstra(v1, N);

        if (res1 >= INF && res2 >= INF)
            System.out.println(-1);
        else
            System.out.println(Math.min(res1, res2));
    }

    public static int dijkstra(int start, int end) {
        Arrays.fill(dist, INF);
        Arrays.fill(check, false);

        PriorityQueue<Node> pq = new PriorityQueue<>();
        boolean[] check = new boolean[N + 1];
        pq.offer(new Node(start, 0));
        dist[start] = 0;

        while (!pq.isEmpty()) {
            Node curNode = pq.poll();
            int cur = curNode.end;

            if (!check[cur]) {
                check[cur] = true;

                for (Node node : list.get(cur)) {
                    if (!check[node.end] && dist[node.end] > dist[cur] + node.weight) {
                        dist[node.end] = dist[cur] + node.weight;
                        pq.add(new Node(node.end, dist[node.end]));
                    }
                }
            }
        }

        return dist[end];
    }

    public static class Node implements Comparable<Node> {
        int end;
        int weight;

        Node(int end, int weight) {
            this.end = end;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return weight - o.weight;
        }

    }
}