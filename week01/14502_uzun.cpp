#include <bits/stdc++.h>
using namespace std;

int N, M, maxCount = 0;
int dx[4] {0, 1, 0, -1}, dy[4] {-1, 0, 1, 0};
vector<vector<int>> labMap(8, vector<int>(8));
vector<pair<int, int>> virusList;

bool isIn(int y, int x) {
    return 0 <= x && x < M && 0 <= y && y < N;
}

int countAfterBuild(
    vector<pair<int, int>> &walls,
    vector<vector<int>> lab
) {
    for(auto &wall : walls)
        lab[wall.first][wall.second] = 1;

    queue<pair<int, int>> q;
    for(auto &point : virusList)
        q.push(point);
    
    while(!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        for(int i=0;i<4;i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if(isIn(ny, nx) && lab[ny][nx] == 0) {
                q.emplace(ny, nx);
                lab[ny][nx] = 2;
            }
        }
    }

    int cnt = 0;
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++)
            if(lab[i][j] == 0) cnt++;
    
    return cnt;
}

void toNext(int &y, int &x) {
    if(x >= M-1) {
        y = y + 1;
        x = 0;
    } else { 
        x = x + 1; 
    }
}

void buildWall(
    pair<int, int> next,
    vector<pair<int, int>> walls
) {
    auto [y, x] = next;

    if(labMap[y][x] == 0) walls.emplace_back(y, x);
    else return;
    
    if(walls.size() == 3) {
        int saftyZone = countAfterBuild(walls, labMap);
        maxCount = max(maxCount, saftyZone);
        return;
    }

    while(true) {
        toNext(y, x);
        if(y >= N) return;
        buildWall({y, x}, walls);
    }
}

void input() {
    cin >> N >> M;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
        cin >> labMap[i][j];
        if(labMap[i][j] == 2) virusList.emplace_back(i, j);
    }
}

int main() {
    input();
    vector<pair<int, int>> walls({});

    for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
        if(labMap[i][j]==0) buildWall({i, j}, walls);
    }
    
    cout << maxCount;
}
