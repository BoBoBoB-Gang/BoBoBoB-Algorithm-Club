#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, L, R;
int country[100][100];
int country_visit[100][100];

int diff_x[] = {0,0,1,-1};
int diff_y[] = {1,-1,0,0};

void getInput() {
    cin >> N >> L >> R;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> country[i][j];
        }
    }
}
bool isValid(int x, int y){
    return x>=0 && y>=0 && x<N && y<N;
}
bool isCountryValid(int x, int y){
    for (int i=0; i<4; i++){
        int tx = x+diff_x[i];
        int ty = y+diff_y[i];
        if (isValid(tx, ty)&& country_visit[tx][ty] == 0
            && abs(country[tx][ty] - country[x][y]) >= L
            && abs(country[tx][ty] - country[x][y]) <= R) {
            return true;
        }
    }
    return false;
}
void dfs(int x, int y){

    for (int i=0; i<4; i++){
        int tx = x+diff_x[i];
        int ty = y+diff_y[i];
        if (isValid(tx, ty) && country_visit[tx][ty] == 0){
            if (abs(country[tx][ty] - country[x][y]) >= L
            && abs(country[tx][ty] - country[x][y]) <= R) {
                country_visit[tx][ty] = 1;
                dfs(tx, ty);
            }
        }
    }
}
void mergeCountry() {
    int total = 0, cnt = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (country_visit[i][j] == 1){
                total += country[i][j];
                cnt++;
            }
        }
    }
    int avg = total / cnt;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (country_visit[i][j] == 1){
                country_visit[i][j] = -1;
                country[i][j] = avg;
            }
        }
    }
}
void initCountryVisit() {
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            country_visit[i][j] = 0;
    }
}
int getDays() {
    int days = 0;
    while (true) {
        bool flag = true;

        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (country_visit[i][j] == 0
                    && isCountryValid(i,j)){
                    dfs(i,j);
                    mergeCountry();
                    flag = false;
                }
            }
        }
        initCountryVisit();

        if (flag) break;
        days++;

    }
    return days;
}
int main() {
    getInput();
    cout << getDays();
    return 0;
}
