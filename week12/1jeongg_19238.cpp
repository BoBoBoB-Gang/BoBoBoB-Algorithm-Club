#include <bits/stdc++.h>

using namespace std;
int N, M, K, K1, K2, boj_x, boj_y;
int graph[50][50];
vector<vector<int>> customer;
int diff_x[4] = {0,0,-1,1}, diff_y[4] = {-1,1,0,0};

void getInput(){
    cin >> N >> M >> K;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> graph[i][j];
    cin >> boj_x >> boj_y;
    int a, b, c, d;
    for (int i=0; i<M; i++) {
        cin >> a >> b >> c >> d;
        customer.push_back({a-1, b-1, c-1, d-1});
        graph[a-1][b-1] = -i-1;
    }

}
bool isValid(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < N;
}
int BFS(){
    queue<pair<int,int>> q;
    int dist[50][50], gh[50][50];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            gh[i][j] = graph[i][j];

    q.push({boj_x, boj_y});
    dist[boj_x][boj_y] = 0;
    gh[boj_x][boj_y] = 1;
    int min_dist = 1e9, index = -1, row, col;

    if (graph[boj_x][boj_y] < 0) {
        K1 = 0;
        return -graph[boj_x][boj_y]-1;
    }
    while (!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int tx = x + diff_x[i];
            int ty = y + diff_y[i];
            if (!isValid(tx,ty)) continue;
            if (gh[tx][ty] != 1 ){
                dist[tx][ty] = dist[x][y] + 1;
                if (gh[tx][ty] < 0){
                    if ((dist[tx][ty] == min_dist &&
                       ((tx < row) || (tx == row && ty < col))) ||
                        dist[tx][ty] < min_dist){
                        row = tx, col = ty;
                        K1 = dist[tx][ty];
                        min_dist = dist[tx][ty];
                        index = -gh[tx][ty]-1;
                    }
                }
                gh[tx][ty] = 1;
                q.push({tx,ty});
            }
        }
    }

    return index;
}
bool BFS_COME(int dx, int dy){
    queue<pair<int,int>> q;
    int dist[50][50], gh[50][50];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            gh[i][j] = graph[i][j];

    q.push({boj_x, boj_y});
    dist[boj_x][boj_y] = 0;
    gh[boj_x][boj_y] = 1;

    while (!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int tx = x + diff_x[i];
            int ty = y + diff_y[i];
            if (!isValid(tx,ty)) continue;
            if (gh[tx][ty] != 1){
                dist[tx][ty] = dist[x][y] + 1;
                gh[tx][ty] = 1;
                q.push({tx,ty});
            }
        }
    }

    K2 = dist[dx][dy];
    return dist[dx][dy] != 0;
}
int main() {
    getInput();
    boj_x--; boj_y--;

    vector<vector<int>> cc(customer);
    bool isValid = true;
    while (!cc.empty()){
        int index = BFS();
        if (index == -1) {isValid = false; break;}
        boj_x = customer[index][0], boj_y = customer[index][1];
        K -= K1;
        if (K < 0) {isValid = false; break;}
        bool isOK = BFS_COME(customer[index][2], customer[index][3]);
        if (!isOK) {isValid = false; break;}
        graph[customer[index][0]][customer[index][1]] = 0;
        boj_x = customer[index][2], boj_y = customer[index][3];
        cc.erase(cc.begin() + index);
        K -= K2;
        if (K < 0){isValid = false; break;}
        K += 2*K2;
    }
    if (isValid) cout << K;
    else cout << -1;
    return 0;
}
