#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr[300][300], copy_arr[300][300], visited[300][300];
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
vector<pair<int, int>> virus;
vector<pair<int, int>> vec;
int ans = 1e9;

void getInput(){
    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) virus.push_back({i,j});
        }
}
bool isValid(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}
void getAnswer(){
    int m = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            copy_arr[i][j] = -arr[i][j]-1; // -1 -2 -3(unactivated)

    queue<pair<int, int>> q;
    for (auto v: vec) {
        q.push(v);
        copy_arr[v.first][v.second] = 0; // activated
    }

    while (!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for (int i=0; i<4; i++){
            int tx = x + dx[i], ty = y + dy[i];

            if (isValid(tx,ty)) {
                if (copy_arr[tx][ty] == -1 || copy_arr[tx][ty] == -3) { // blank
                    copy_arr[tx][ty] = copy_arr[x][y]+1;
                    q.push({tx, ty});
                }
            }
        }
    }
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            if (arr[i][j] != 2)
                m = max(m, copy_arr[i][j]);
            if (copy_arr[i][j] == -1){
                m = 1e9;
                return;
            }
        }
    ans = min(m, ans);
}
void DFS(int k, int d){
    if (d == M){
        //cout <<vec[0].first << " " <<vec[0].second <<endl;
        getAnswer();
        return;
    }
    for (int p=k; p<virus.size(); p++){
        auto [i,j] = virus[p];
        if (!visited[i][j]) {
            visited[i][j] = 1;
            vec.push_back({i,j});
            DFS(p, d+1);
            visited[i][j] = 0;
            vec.pop_back();
        }
    }

}

int main() {
    getInput();
    DFS(0,0);
    if (ans == 1e9) cout << -1;
    else cout << ans;

    return 0;
}
