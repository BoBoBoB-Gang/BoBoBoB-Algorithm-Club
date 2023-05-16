#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr[300][300];
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
int visited[300][300];

void getInput(){
    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> arr[i][j];
}
bool isValid(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < M;
}

void removeIce(){
    int cp_arr[N][M];
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cp_arr[i][j] = arr[i][j];
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            int r = 0;
            for (int k=0; k<4; k++){
                int tx = i+dx[k], ty = j+dy[k];
                if (isValid(tx,ty) && cp_arr[tx][ty] == 0)
                    r++;
            }
            arr[i][j] -= r;
            if (arr[i][j] < 0) arr[i][j] = 0;
        }
    }
}
void getPart(int x, int y) {
    for (int i=0; i<4; i++){
        int tx = x+dx[i], ty=y+dy[i];
        if (isValid(tx,ty) && arr[tx][ty] != 0 && !visited[tx][ty]){
            visited[tx][ty] = 1;
            getPart(tx,ty);
        }
    }
}
void printIce(){
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
void clearIce(){
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            visited[i][j] = 0;
}
int getPartNum(){
    int num = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (arr[i][j] != 0 && visited[i][j] == 0){
                num++;
                getPart(i, j);
            }
        }
    }
    return num;
}
int getAnswer(){
    int cnt = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (arr[i][j] != 0 && !visited[i][j]){

                if (getPartNum() > 1) return cnt;
                removeIce();
                clearIce();
                cnt++;
            }
        }
    }
    return 0;
}

int main() {
    getInput();
    cout << getAnswer();
    return 0;
}
