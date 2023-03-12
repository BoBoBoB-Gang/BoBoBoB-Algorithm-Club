#include <bits/stdc++.h>
using namespace std;

int R=3, C=3;
int A[101][101];

void operateR() {
    int newC = 0;
    for(int r=1; r<=R && r<=100; r++) {
        map<int, int> freqMap;

        for(int c=1; c<=C && c<=100; c++)
            if(A[r][c]) freqMap[A[r][c]]++;
        
        vector<pair<int, int>> sortedRow(freqMap.begin(), freqMap.end());

        sort(sortedRow.begin(), sortedRow.end(), [](auto p1, auto p2) {
            if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second < p2.second;
        });

        newC = max(newC, (int) (sortedRow.size() * 2));
        newC = min(newC , 50);

        for(int i=0;i<sortedRow.size() && i<50;i++) {
            A[r][2*i+1] = sortedRow[i].first;
            A[r][2*i+2] = sortedRow[i].second;
        }

        if(sortedRow.size() * 2 < C)
            for(int i=2*sortedRow.size()+1;i<=C;i++)
                A[r][i] = 0;
    }
    C = newC;
}


void operateC() {
    int newR = 0;
    for(int c=1; c<=C && c<=100; c++) {
        map<int, int> freqMap;

        for(int r=1; r<=R && r<=100; r++)
            if(A[r][c]) freqMap[A[r][c]]++;
        
        vector<pair<int, int>> sortedCol(freqMap.begin(), freqMap.end());

        sort(sortedCol.begin(), sortedCol.end(), [](auto p1, auto p2) {
            if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second < p2.second;
        });

        newR = max(newR, (int) (sortedCol.size() * 2));
        newR = min(newR , 50);

        for(int i=0;i<sortedCol.size() && i<50;i++) {
            A[2*i+1][c] = sortedCol[i].first;
            A[2*i+2][c] = sortedCol[i].second;
        } 

        if(sortedCol.size() * 2 < C)
            for(int i=2*sortedCol.size()+1;i<=C;i++)
                A[i][c] = 0;
    }
    R = newR;
}

int main() {
    int r, c, k, t=0;
    cin >> r >> c >> k;

    for(int i=1;i<=R;i++) 
        for(int j=1;j<=C;j++)
            cin >> A[i][j];

    while(A[r][c] != k) {
        if(R>=C) operateR();
        else operateC();
        if(t++ == 100) {
            t = -1; 
            break;
        }
    }
    cout << t;
}
