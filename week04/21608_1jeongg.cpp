#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define PAIR pair<int, int>

using namespace std;
int student_size, students[20][20] = {0,};
int diff_i[4] = {1,-1,0,0};
int diff_j[4] = {0,0,1,-1};

vector<int> student_order;
map<int, vector<int>> friends;

void getInput() {
    int a, b;
    cin >> student_size;
    for (int i=0; i<student_size*student_size; i++){
        vector<int> inp_vec;
        cin >> a;
        for (int j=0; j<4; j++){
            cin >> b;
            inp_vec.push_back(b);
        }
        student_order.push_back(a);
        friends.insert({a, inp_vec});
    }
}
bool isInRange(int x, int y){
    return x>=0 && x<student_size && y>=0 && y<student_size;
}
PAIR getSeatInfo(int num, int x, int y){
    int empty_seat = 0, friend_seat = 0;
    for (int k=0; k<4; k++){
        int tx = x + diff_i[k];
        int ty = y + diff_j[k];
        vector<int> f = friends[num];
        if (isInRange(tx, ty)) {
            if (students[tx][ty] == 0) empty_seat++;
            if (find(f.begin(), f.end(), students[tx][ty]) != f.end())
                friend_seat++;
        }
    }
    return {friend_seat, empty_seat};
}
bool cmp(pair<PAIR, PAIR> A, pair<PAIR, PAIR> B){
    PAIR a = A.first, b = A.second;
    PAIR c = B.first, d = B.second;
    if (a.first == c.first){
        if (a.second == c.second){
            if (b.first == d.first) {
                return b.second < d.second;
            }
            return b.first < d.first;
        }
        return a.second > c.second;
    }
    return a.first > c.first;
}
PAIR decideOwnSeat(int num) {
    vector<pair<PAIR, PAIR>> seats;
    for (int i=0; i<student_size; i++){
        for (int j=0; j<student_size; j++){
            PAIR s = getSeatInfo(num, i, j);
            if (students[i][j] == 0)
                seats.push_back({s, {i,j}}); // friend, empty, i, j
        }
    }
    sort(seats.begin(), seats.end(), cmp);
    return seats[0].second;
}
void decideAllSeat(){
    for (auto s: student_order){
        auto [x, y] = decideOwnSeat(s);
        students[x][y] = s;
    }
}

void printAnswer() {
    int answer = 0;
    for (int i=0; i<student_size; i++){
        for (int j=0; j<student_size; j++){
            int p = getSeatInfo(students[i][j] ,i, j).first;
            if (p <= 1) answer += p;
            if (p == 2) answer += 10;
            if (p == 3) answer += 100;
            if (p == 4) answer += 1000;
        }
    }
    cout <<answer;
}
int main() {
    getInput();
    decideAllSeat();
    printAnswer();
    return 0;
}
