#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<pair<int, int>> parcel[201];
int answer[201][201];

void getInput(){
    int a,b,c;
    cin >> N >> M;
    for (int i=0; i<M; i++){
        cin >> a >> b >> c;
        parcel[a].push_back({b,c});
        parcel[b].push_back({a,c});
    }
}
void getAnswer(int start){
    priority_queue<pair<int, int>> q;
    int dist[10001], parent[10001];
    dist[start] = 0;
    for (int i=0; i<=N; i++)
        dist[i] = 1e9;

    q.push({0,start});
    while (!q.empty()){
        auto [distance, cur] = q.top();
        distance = -distance;
        q.pop();
        for (auto k: parcel[cur]){
            auto [next, next_distance] = k;
            if (distance + next_distance < dist[next]){
                answer[next][start] = cur;
                dist[next] = distance + next_distance;
                q.push({-dist[next], next});
            }
        }
    }
}
int main() {
    getInput();
    for (int i=1; i<=N; i++)
        getAnswer(i);


    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (i == j) cout << "- ";
            else cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
