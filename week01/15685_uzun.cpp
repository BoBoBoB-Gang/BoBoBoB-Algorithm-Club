#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> pointMap = vector(101, vector<bool>(101, false));
int dx[4] {1, 0, -1, 0}, dy[4] {0, -1, 0, 1};

// 90도 회전 페이즈 진행
void curveIt(
    vector<int> &curveList,
    pair<int, int> &endPoint
) {
    for(int i=curveList.size()-1;i>=0;i--) {
        auto [x, y] = endPoint;
        int d = (curveList[i] + 1) % 4;
        curveList.push_back(d);
        endPoint = {x + dx[d], y + dy[d]};
        pointMap[endPoint.second][endPoint.first] = true;
    }
}

// 시작점 x, y로 부터 g번 curve
void dragonCurve(int x, int y, int d, int g) {
    vector<int> curveList { d };
    pair<int, int> endPoint = {x+dx[d], y+dy[d]};
    pointMap[y][x] = pointMap[endPoint.second][endPoint.first] = true;

    while(g--) curveIt(curveList, endPoint);
}

// 만족 사각형 여부 검사
auto isSqaureStatisfied = [](int y, int x) -> bool {
    return pointMap[x][y] && pointMap[x+1][y] && pointMap[x][y+1] && pointMap[x+1][y+1];
};

// 만족 사각형 카운팅
int getSatisfiedSquareCount() {
    int count = 0;

    for(int i=0;i<100;i++) 
        for(int j=0;j<100;j++) 
            if(isSqaureStatisfied(i, j)) count++;

    return count;
}

int main() {
    int N, x, y, d, g;
    cin >> N;
    while(cin >> x >> y >> d >> g) 
        dragonCurve(x, y, d, g);

    cout << getSatisfiedSquareCount() << endl;
}
