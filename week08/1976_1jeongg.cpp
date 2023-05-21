#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> vec[1001];
int trip_city[1001];
bool visited[1001];

void getInput(){
    int inp;
    cin >> N >> M;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++){
            cin >> inp;
            if (inp == 1){
                vec[i].push_back(j);
                vec[j].push_back(i);
            }
        }

    for (int i=0; i<M; i++){
        cin >> trip_city[i];
    }
}
void DFS(int a){
    visited[a] = true;
    for (int i=0; i<vec[a].size(); i++){
        int x = vec[a][i];
        if (visited[x]) continue;
        DFS(x);
    }
}
string isTripable(){
    for (int i=0; i<M-1; i++){
        int source = trip_city[i], dest = trip_city[i+1];
        DFS(source);
        if (!visited[dest]) return "NO";
        memset(visited, false, sizeof(visited));
    }
    return "YES";
}

int main() {
    getInput();
    cout << isTripable();
    return 0;
}
