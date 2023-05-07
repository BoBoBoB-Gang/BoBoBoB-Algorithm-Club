#include <bits/stdc++.h>

using namespace std;
int K;
vector<int> vec[20001];
int color[20001];
int V, E, u,v;
bool flag = true;

void dfs(int a, int b){
    color[a] = b;
    for (auto x: vec[a]){
        if (color[x] == b){
            flag = false;
            return;
        }
        if (color[x] == 0){
            dfs(x, -b);
        }
    }
}

void getInput(){
    cin >> K;
    for (int i=0; i<K; i++){
        cin >> V >> E;

        for (int j=0; j<E; j++){
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        for (int j=1; j<=V; j++){
            if (!flag)
                break;
            if (color[j] == 0) {
                dfs(j,1);
            }
        }
        cout << (flag ? "YES" : "NO") <<endl;

        for (int j=1; j<=V; j++){
            vec[j].clear();
        }
        flag = true;
        fill(color, color+20001, 0);
    }
}

int main() {
    getInput();

    return 0;
}
