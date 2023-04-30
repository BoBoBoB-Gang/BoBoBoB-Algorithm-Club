#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, M, x, y, K;
int graph[100][100];

int dice_info[6] = {0,1,2,3,4,5};
int dice[6] = {0,0,0,0,0,0};

int diff_x[] = {0,0,-1,1};
int diff_y[] = {1,-1,0,0};
int index[4][6] = {{1,5,0,3,4,2}, {2,0,5,3,4,1}, {3,1,2,5,0,4}, {4,1,2,0,5,3}};
int answer_index[6] = {5,2,1,4,3,0};

bool isValid(int a, int b){
    return a >= 0 && b >= 0 && a < N && b < M;
}
int diceNum(int inst){
    int tx = x + diff_x[inst-1];
    int ty = y + diff_y[inst-1];

    if (!isValid(tx, ty))
        return -1;

    int copy_dice[6];
    for (int i=0; i<6; i++){
        copy_dice[i] = dice_info[index[inst-1][i]];
    }
    for (int i=0; i<6; i++){
        dice_info[i] = copy_dice[i];
    }
    int dice_index = copy_dice[0];
    x = tx, y = ty;
    if (graph[tx][ty] == 0) {
        graph[tx][ty] = dice[dice_index];
    } else {
        dice[dice_index] = graph[tx][ty];
        graph[tx][ty] = 0;
    }
    return dice[answer_index[dice_index]];
}

void rollDice() {
    cin >> N >> M >> x >> y >> K;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> graph[i][j];
        }
    }
    int k;
    for (int i=0; i<K; i++){
        cin >> k;
        int ans = diceNum(k);
        if (ans != -1)
            cout << ans << endl;
    }
}


int main() {
    rollDice();
    return 0;
}
