 #include <bits/stdc++.h>

using namespace std;
int N, M;
int path[500][500];
int dx[] = {-1,1,0,0}, dy[] = {0,0,1,-1};
int dp[500][500];

void getInput(){
    cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++) {
            cin >> path[i][j];
            dp[i][j] = -1;
        }
    }

}
bool isValid(int x, int y){
    return x>=0 && y>=0 && x<N && y<M;
}

int bfs(int x, int y){
    if (x == N-1 && y == M-1){
        return 1;
    }
    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 0;

    for (int i=0; i<4; i++){
        int tx = x + dx[i], ty = y + dy[i];
        if (isValid(tx,ty) && path[x][y] > path[tx][ty])
            dp[x][y] += bfs(tx,ty);
    }
    return dp[x][y];
}
int main() {
    getInput();
    cout << bfs(0,0);
    return 0;
}
