#include <bits/stdc++.h>

using namespace std;
int N, K;
typedef struct _box{
    vector<int> box_chess; // index of chess
    int color;
} box;
box boxes[20][20];
tuple<int,int,int> chess[20]; // x, y, direction
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void getInput(){
    int x,y,d;
    cin >> N >> K;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> boxes[i][j].color;

    for (int i=0; i<K; i++){
        cin >> x >> y >> d;
        boxes[x-1][y-1].box_chess.push_back(i);
        chess[i] = {x-1,y-1,d-1};
    }
}
bool isValid(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < N;
}
void getAnswer(int depth){
    int x,y,d;
    if (depth >= 1000) {
        cout << -1;
        return;
    }
    for (int i=0; i<K; i++){
        tie(x,y,d)= chess[i];
        if (boxes[x][y].box_chess.empty() ||
            boxes[x][y].box_chess.front() != i) continue;
        int tx = x + dx[d], ty = y + dy[d];

        if (!isValid(tx,ty) || boxes[tx][ty].color == 2){
            if (d%2 == 1) d--; else d++;
            tx = x + dx[d], ty = y + dy[d];
            get<2>(chess[i]) = d;
            if (!isValid(tx, ty) || boxes[tx][ty].color == 2)
                continue;
        }
        vector<int> vec(boxes[x][y].box_chess);
        if (boxes[tx][ty].color == 1) reverse(vec.begin(), vec.end());
        for (auto k: vec) {
            boxes[tx][ty].box_chess.push_back(k);
            chess[k] = {tx, ty, get<2>(chess[k])};
        }
        boxes[x][y].box_chess.clear();
        if (boxes[tx][ty].box_chess.size() >= 4) {
            cout << depth+1;
            return;
        }

    }
    getAnswer(depth+1);
}
int main() {
    getInput();
    getAnswer(0);
    return 0;
}
