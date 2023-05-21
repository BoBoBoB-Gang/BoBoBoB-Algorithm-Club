#include <bits/stdc++.h>

using namespace std;
int N, M;
char forest[300][300];
int dotch[300][300];
int water[300][300];
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
pair<int, int> source, dest;

void getInput(){
    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) {
            cin >> forest[i][j];
            if (forest[i][j] == 'D') dest = {i,j};
            if (forest[i][j] == 'S') source = {i,j};
        }
    memset(water,-1,sizeof(water));
    memset(dotch,-1,sizeof(dotch));
}
bool isValid(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < M;
}
void moveDotch(){
    queue<pair<int, int>> q;
    q.push({source.first, source.second});
    dotch[source.first][source.second] = 0;

    while (!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int tx = x + dx[i], ty = y + dy[i];
            if (isValid(tx,ty) && dotch[tx][ty] == -1
                && !(forest[tx][ty] == 'X' || forest[tx][ty] == 'D')){
                dotch[tx][ty] = dotch[x][y] + 1;
                q.push({tx,ty});
            }
        }
    }
}
void moveWater(){
    queue<pair<int, int>> q;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (forest[i][j] == '*') {
                q.push({i,j});
                water[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int tx = x + dx[i], ty = y + dy[i];
            if (isValid(tx,ty) && water[tx][ty] == -1
                && !(forest[tx][ty] == 'X' || forest[tx][ty] == 'D')){
                water[tx][ty] = water[x][y] + 1;
                q.push({tx,ty});
            }
        }
    }


}
void getAnswer(){
    priority_queue<int> q;
    for (int i=0; i<4; i++){
        int tx = dest.first + dx[i], ty = dest.second + dy[i];
        if (isValid(tx,ty) && dotch[tx][ty] != -1
            && !(dotch[tx][ty] >= water[tx][ty] && water[tx][ty] > 0) )
            q.push(-dotch[tx][ty]);

    }
    if (q.empty()) cout << "KAKTUS";
    else cout << -q.top()+1;
}
int main() {

    getInput();
    moveDotch();
    moveWater();
    getAnswer();
    return 0;
}
