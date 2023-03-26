#include <bits/stdc++.h>
using namespace std;

int N, M, r, c, d;
int room[51][51];
int dx[4] {0, 1, 0, -1}, dy[4] {-1, 0, 1, 0};

bool isIn(int y, int x) {
    return 0 <= x && x < M && 0 < y && y <= N;
}

bool IsDirty(int y, int x, int d) {
    return isIn(y+dy[d], x+dx[d]) && room[y+dy[d]][x+dx[d]] == 0;
}

bool IsAroundClean() {
    for(int i=0;i<4;i++)
        if(IsDirty(r, c, i)) return false;
    return true;
}

int main() {
    cin >> N >> M;
    cin >> r >> c >> d;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> room[i][j];
        }
    }
    int sum = 0;
    int count = 0;

    while(true) {
        if(room[r][c] == 0) {
            sum++;
            room[r][c] = 2;
        }

        if(IsAroundClean()) { 
            // 주변 4칸 깨끗
            int back = (d + 2) % 4;
            int br = r+dy[back], bc = c+dx[back];
            if(isIn(br, bc) && room[br][bc] != 1) {
                // 후진
                r = br;
                c = bc;
            }
            // 작동 정지
            else break; 

        } else { 
            // 주변 4칸 중 청소되지 않은 칸 존재
            int fr, fc;
            do {
                d = (d + 3) % 4; // 반시계 90도 회전
                fr = r+dy[d];
                fc = c+dx[d];
            } while(!isIn(fr, fc) || room[fr][fc] != 0);
            r = fr;
            c = fc;
        }
    }
    cout << sum;
}
