#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n;
int sea[100][100];
pair<int, int> shark_size;
int diff_x[] = { -1, 0, 1, 0 };
int diff_y[] = { 0, 1, 0, -1 };

void getInput() {
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            cin >> sea[i][j];
            if (sea[i][j] == 9) {
                shark_size = {i,j};
                sea[i][j] = 0;
            }
        }
}
bool isValid(int x, int y){
    return x >= 0 && y>=0 && x < n && y < n;
}
int getDistance(int a1, int a2, int b1, int b2, int shark){
    bool visited[100][100];
    int cnt = 0;
    int dist[100][100] = {0, };

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            visited[i][j] = sea[i][j] > shark;
        }
    }
    queue<pair<int, int>> q;
    q.push({a1, a2});
    visited[a1][a2] = true;

    while (!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        if (x == b1 && y == b2)
            return dist[x][y];

        for (int i=0; i<4; i++){
            int tx = x + diff_x[i];
            int ty = y + diff_y[i];
            if (!visited[tx][ty] && isValid(tx, ty)){
                q.push({tx, ty});
                visited[tx][ty] = true;
                dist[tx][ty] = dist[x][y] + 1;
            }
        }
        cnt++;
    }
    return 0;
}
pair<int, int> getEatableFish(int x, int y, int shark){
    vector<pair<int, int>> fish;
    int fish_size = 1e9;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (shark > sea[i][j] && sea[i][j] != 0) {
                int diff = getDistance(x,y,i,j,shark);
                if (diff == 0);
                else if (fish_size > diff) {
                    fish_size = diff;
                    fish.clear();
                    fish.push_back({i, j});
                }
                else if (fish_size == diff)
                    fish.push_back({i, j});
            }
        }
    }
    if (fish.size() == 0)
        return {-1, -1};
    sort(fish.begin(), fish.end());
    return fish.front();
}

void babyShark() {
    int shark = 2, cnt = 0, answer = 0;
    int i = shark_size.first, j=shark_size.second;

    while (true){
        auto [x, y] = getEatableFish(i,j,shark);
        if (x == -1) break;

        answer += getDistance(x,y,i,j, shark);
        sea[x][y] = 0;
        i = x, j = y;
        cnt++;
        if (cnt == shark) {
            shark++;
            cnt = 0;
        }
    }
    cout << answer;


}
int main() {
    getInput();
    babyShark();
    return 0;
}
