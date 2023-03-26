#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

tuple<int, int, int> point;
int col_size, row_size;
int diff_i[4] = {-1,0,1,0}; // 북동남서
int diff_j[4] = {0,1,0,-1};
vector<vector<int>> room;

bool isInRange(int i, int j) {
    return i >= 0 && i < col_size && j >= 0 && j < row_size;
}
void getInput() {
    int x,y,z, inp;
    cin >> col_size >> row_size;
    cin >> x >> y >> z;
    point = {x,y,z};
    for (int i=0; i<col_size; i++){
        vector<int> inp_vec;
        for (int j=0; j<row_size; j++){
            cin >> inp;
            inp_vec.push_back(inp);
        }
        room.push_back(inp_vec);
    }
}

bool isEmptyExist(int col, int row, int direct){
    for (int i=3; i>=0; i--){
        int a = col + diff_i[(i+direct)%4];
        int b = row + diff_j[(i+direct)%4];
       // cout <<(i+direct)%4 << " " << a << " " << b << endl;
        if (isInRange(a,b) && room[a][b] == 0){ // 청소 안된 칸 있으면
            point = {a,b,(i+direct)%4};
            return true;
        }
    }
    return false;
}
void main_robot() {
    int x,y,z, answer=0;
    while (true){
        tie(x,y,z) = point;
        if (isInRange(x,y) && room[x][y] == 0) {
            room[x][y] = 2;
            answer++;
            continue;
        }
        if (isEmptyExist(x, y, z)){
            continue;
        }
        else {
            switch(z){
            case 0: x++; break;
            case 1: y--; break;
            case 2: x--; break;
            case 3: y++; break;
            }
            if (isInRange(x,y) && room[x][y] == 1) break;
            point = {x,y,z};
        }
    }
    cout << answer;
}
int main() {
    getInput();
    main_robot();

    return 0;
}
