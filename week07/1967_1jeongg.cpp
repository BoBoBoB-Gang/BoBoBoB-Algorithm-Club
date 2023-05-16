#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<int, int>> graph[10001];

void getInput(){
    int a, b, c;
    cin >> n;
    for (int i=0; i<n-1; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
}
/*
1. 트리에서 임의의 정점 x를 잡는다.
2. 정점 x에서 가장 먼 정점 y를 찾는다.
3. 정점 y에서 가장 먼 정점 z를 찾는다.
*/
pair<int,int> bfs(int x){
    int m = 0, index = 0;
    vector<int> dist(n+1, 1e9);
    priority_queue<pair<int, int>> pq;
    dist[x] = 0;
    pq.push({0, x});
    while (!pq.empty()){
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        for (int i=0; i<graph[current].size(); i++){
            int next = graph[current][i].first;
            int next_cost = cost + graph[current][i].second;
            if (next_cost < dist[next]){
                dist[next] = next_cost;
                if (m < next_cost){
                    m = next_cost;
                    index = next;
                }
                pq.push({-next_cost, next});
            }
        }
    }
    return {index, dist[index]};
}

void dfs(int x) {

}
int main() {
    getInput();
    auto [x,y] = bfs(1);
    auto [a,b] = bfs(x);
    cout << b;
    return 0;
}
