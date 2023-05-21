#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr[300][300];
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
int visited[300][300], cnt[300][300];
int a[300][300];
void getInput(){
    cin >> M >> N;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
}
bool isValid(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < M;
}
void getAnswer(){

    queue<pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = 0;

    while (!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        bool flag = false;
        for (int i=0; i<4; i++){
            int tx = x + dx[i], ty = y + dy[i];
            if (isValid(tx,ty)){
                if (visited[tx][ty] == -1) {
                    visited[tx][ty] = visited[x][y];
                    if (arr[tx][ty] == 1)
                       visited[tx][ty] += 1;
                    q.push({tx, ty});

                } else if (arr[tx][ty] == 0) {
                    visited[tx][ty] = min(visited[x][y], visited[tx][ty]);
                    //if (arr[tx][ty] == 1) visited[tx][ty] ++;
                }

            }
        }
    }
    int cnt = 10;
    while (cnt != 0) {
        cnt = 0;
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                int m =1e9;
                for (int k=0; k<4; k++){
                    int tx = i + dx[k], ty = j + dy[k];
                    if (isValid(tx,ty)){
                        m = min(m, visited[tx][ty]);
                    }
                }
                m = min(visited[i][j], m);
                a[i][j] = m + arr[i][j];
                if (visited[i][j] != a[i][j])
                    cnt ++;
            }
        }
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                visited[i][j] = a[i][j];
            }
        }
       // cout <<cnt <<endl;
    }
}

int main() {
    memset(visited, -1, sizeof(visited));
    getInput();
    getAnswer();

    cout << a[N-1][M-1];
    return 0;
}
