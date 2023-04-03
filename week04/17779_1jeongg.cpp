#include <iostream>
#include <algorithm>

using namespace std;
int gerry_size;
int gerry[101][101];

bool isInRange(int i, int j){
    return i>0 && i<=gerry_size && j>0 && j<=gerry_size;
}
void getInput() {
    cin >> gerry_size;
    for (int i=1; i<=gerry_size; i++){
        for (int j=1; j<=gerry_size; j++)
            cin >> gerry[i][j];
    }
}
int getPeople(int x, int y, int d1, int d2) {
    int people[5] = {0,0,0,0,0};
    if (!isInRange(x+d1, y-d1)) return 1e9;
    if (!isInRange(x+d2, y+d2)) return 1e9;
    if (!isInRange(x+d1+d2, y-d1+d2)) return 1e9;

    int a = 0, b = 0;
    bool bool_a = true, bool_b = true;

    int gerry_copy[101][101];
    for (int i=1; i<=gerry_size; i++){
        for (int j=1; j<=gerry_size; j++){
            gerry_copy[i][j] = gerry[i][j];
        }
    }
    for (int i=x; i<=x+d1+d2; i++){
        if (a == d1) bool_a = false;
        if (b == d2) bool_b = false;

        int start = y-a, finish = y+b;
        for (int p=start; p<=finish; p++){
            people[4] += gerry[i][p];
            gerry[i][p] = 0;
        }

        if (bool_a) a++; else a--;
        if (bool_b) b++; else b--;
    }

    for (int i=1; i<=gerry_size; i++){
        for (int j=1; j<=gerry_size; j++){
             if (i < x+d1 && j <= y)
                people[0] += gerry[i][j];
             if (i <= x+d2 && j > y)
                people[1] += gerry[i][j];
             if (i >= x+d1 && j < y-d1+d2)
                people[2] += gerry[i][j];
             if (i > x+d2 && j >= y-d1+d2)
                people[3] += gerry[i][j];

        }
    }
    for (int i=1; i<=gerry_size; i++){
        for (int j=1; j<=gerry_size; j++){
            gerry[i][j] = gerry_copy[i][j];
        }
    }

    return *max_element(people, people+5) - *min_element(people, people+5);
}
void gerrymandering(){
    int answer = 1e9;
    for (int i=1; i<=gerry_size; i++){
        for (int j=1; j<=gerry_size; j++){
            int d1_max = j-1, d2_max = gerry_size-j;
            for (int a=1; a<=d1_max; a++){
                for (int b=1; b<=d2_max; b++){
                    answer = min(answer, getPeople(i,j,a,b));
                }
            }
        }
    }
    cout << answer;
}
int main() {
    getInput();
    gerrymandering();
    return 0;
}
