#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int width, height;
int diff_i[4] = {-1,0,1,0};
int diff_j[4] = {0,1,0,-1};
int office[8][8];
vector<pair<int, int>> cctv;
int cctv_size;
int answer = 1e9;

bool isInRange(int i, int j){
    return i>=0 && i<width && j>=0 && j<height;
}
void getInput() {
    cin >> width >> height;
    for (int i=0; i<width; i++){
        for (int j=0; j<height; j++){
            cin >> office[i][j];
            if (office[i][j] != 0 &&office[i][j] != 6)
                cctv.push_back({i,j});
        }
    }
    cctv_size = cctv.size();
}

void monitoring(int x, int y, int d, int d2){
    while (isInRange(x+d, y+d2)){
        if (office[x+d][y+d2] == 6) return;
        if (office[x+d][y+d2] == 0)
            office[x+d][y+d2] = -1;
        x += d, y += d2;

    }
}
void main_cctv(int index){
    int copy_office[8][8];

    if (index == cctv_size){
        int cnt = 0;
        for (int i=0; i<width; i++){
            for (int j=0; j<height; j++){
                if (office[i][j] == 0) cnt++;
            }
        }
        answer = min(answer, cnt);
        return;
    }
    auto [x, y] = cctv[index];
    int c = office[x][y];
    for (int i=0; i<4; i++){
        for (int a=0; a<8; a++){
            for (int b=0; b<8; b++){
                copy_office[a][b] = office[a][b];
            }
        }
        if (c >= 1)
             monitoring(x,y,diff_i[i], diff_j[i]);
        if (c == 2 && i<2)
            monitoring(x,y,diff_i[i+2], diff_j[i+2]);
        if (c >= 3)
            monitoring(x,y,diff_i[(i+1)%4], diff_j[(i+1)%4]);
        if (c >= 4)
            monitoring(x,y,diff_i[(i+2)%4], diff_j[(i+2)%4]);
        if (c == 5)
            monitoring(x,y,diff_i[(i+3)%4], diff_j[(i+3)%4]);

        main_cctv(index+1);
        for (int a=0; a<8; a++){
            for (int b=0; b<8; b++)
                office[a][b] = copy_office[a][b];
        }
    }

}
int main() {
    getInput();
    main_cctv(0);
    cout << answer;
    return 0;
}
