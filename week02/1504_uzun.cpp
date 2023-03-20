#include <bits/stdc++.h>
using namespace std;

#define INF 999999999
int N, E, a, b, c, u, v;
vector<pair<int, int>> path[801];
int dp[801];

int get_min_dis(int start, int goal) {
    fill_n(dp, N+1, INF);
    dp[start] = 0;

    priority_queue<pair<int, int>> pq; // {-거리, 번호}
    pq.emplace(0, start);

    while(!pq.empty()) {
        auto [dis, curr] = pq.top();
        dis = -dis;
        pq.pop();

        for(auto &neighbor: path[curr]) {
            auto [next, n_dis] = neighbor;
            if(dp[next] > dis + n_dis) {
                dp[next] = dis + n_dis;
                pq.emplace(-dp[next], next);
            }
        }
    }
    return dp[goal];
}

bool isInf(int value) { return value == INF; }

int main() {
    cin >> N >> E;
    for(int i=0;i<E;i++) {
        cin >> a >> b >> c;
        path[a].emplace_back(b, c);
        path[b].emplace_back(a, c);
    }
    cin >> u >> v;

    int o2u = get_min_dis(1, u);
    int o2v = get_min_dis(1, v);
    int u2v = get_min_dis(u, v);
    int v2u = get_min_dis(v, u);
    int v2N = get_min_dis(v, N);
    int u2N = get_min_dis(u, N);

    int case1 = isInf(o2u) || isInf(u2v) || isInf(v2N) ? 
        INF : o2u + u2v + v2N;
    int case2 = isInf(o2v) || isInf(v2u) || isInf(u2N) ? 
        INF : o2v + v2u + u2N;

    if(isInf(case1) && isInf(case2)) cout << "-1";
    else cout << min(case1, case2);
}
