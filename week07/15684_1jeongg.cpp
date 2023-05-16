#include <bits/stdc++.h>

using namespace std;
int N, M, H;
int line[50][50];
vector<pair<int, int>> vec;
int flag = false;
int v = 1e9;

void getInput(){
    cin >> N >> M >> H;
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        line[a][b] = 1;
        line[a][b+1] = -1; // can't
        line[a][b-1] = -1; // can't
    }
}
bool isAnswer(){
    for (int i=1; i<=N; i++){
        int mv = 0;
        for (int j=1; j<=H; j++){
            if (line[j][mv+i] == 1)
                mv++;
            else if (line[j][mv+i-1] == 1)
                mv--;
        }
        if (mv != 0) return false;
    }
    return true;
}
void getAnswer(int a, int b) {

    if (isAnswer()){
        int vs = vec.size();
        v = min(v, vs);
        return;
    }
    if (vec.size() >= 3){
        return;
    }
    for (int i=a; i<=H; i++){
        for (int j=b; j<N; j++){
            if (line[i][j] == 1) {
                j += 1;
                continue;
            }
            if (line[i][j] == 0){
                line[i][j] = 1;
                vec.push_back({i,j});
                getAnswer(i,1);
                vec.pop_back();
                line[i][j] = 0;
            }
        }
    }
    return;

}
int main() {
    getInput();
    if (isAnswer()) cout << 0;
    else {
        getAnswer(1,1);
        if (v == 1e9) cout << -1;
        else cout << v;
    }

    return 0;
}
