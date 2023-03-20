#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<pair<int, int>> graph[200001];
int vertex_size, edge_size;

int dijkstra(int start, int index) {
    int dist[200001];
    fill(dist, dist + 200001, 1e9);
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start)); // (dist, vertex)
    dist[start] = 0;
    while(!pq.empty()) {
        int cost = -pq.top().first; // 가중치
        int current = pq.top().second; // 현재 노드
        pq.pop();
        for(int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i].first; // 다음 노드
            int nextDist = cost + graph[current][i].second; // 다음 노드까지 가는데 필요한 비용
            if(nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push(make_pair(-nextDist, next));
            }
        }
    }
    return dist[index];
}
int getDistance(int v1, int v2){
    int answer = dijkstra(1, v1);
    answer += dijkstra(v1, v2);
    answer += dijkstra(v2, vertex_size);
    return answer;
}
void mainShortestPath(){
    int a, b, c, v1, v2, answer;
    cin >> vertex_size >> edge_size;
    for (int i=0; i<edge_size; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    answer = min(getDistance(v1, v2), getDistance(v2, v1));

    if (edge_size == 0) cout << -1;
    else if (answer < 1e9) cout << answer;
    else cout << -1;
}
int main() {
    mainShortestPath();
    return 0;
}
