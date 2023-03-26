#include <iostream>
#include <vector>
#include <tuple>
#define VECTOR vector<vector<pair<int,int>>>
using namespace std;

int col_size, row_size;
int answer = 0;

vector<vector<int>> paper;
VECTOR shape_1 = {{{0,0},{0,1},{0,2},{0,3}}, {{0,0},{1,0},{2,0},{3,0}}};
VECTOR shape_2 = {{{0,0},{0,1},{1,0},{1,1}}};
VECTOR shape_3 = {
    {{0,0},{1,0},{2,0},{2,1}}, {{0,0},{0,1},{0,2},{-1,2}}, {{0,0},{0,1},{1,1},{2,1}}, {{0,0},{1,0},{0,1},{0,2}},
    {{0,0},{0,1},{-1,1},{-2,1}}, {{0,0},{1,0},{1,1},{1,2}}, {{0,0},{0,1},{1,0},{2,0}}, {{0,0},{0,1},{0,2},{1,2}},
};
VECTOR shape_4 = {
    {{0,0},{1,0},{1,1},{2,1}}, {{0,0},{0,1},{-1,1},{-1,2}}, {{0,0},{0,1},{1,1},{1,2}}, {{0,0},{-1,0},{-1,1},{-2,1}}
};
VECTOR shape_5 = {
    {{0,0},{0,1},{0,2},{1,1}}, {{0,0},{0,1},{-1,1},{0,2}}, {{0,0},{0,1},{-1,1},{1,1}},{{0,0},{1,0},{-1,0},{0,1}}
};
vector<VECTOR> shape = {shape_1, shape_2, shape_3, shape_4, shape_5};
bool isInRange(int i, int j) {
    return i >= 0 && i < col_size && j >= 0 && j < row_size;
}
void getInput() {
    int inp;
    cin >> col_size >> row_size;
    for (int i=0; i<col_size; i++){
        vector<int> inp_vec;
        for (int j=0; j<row_size; j++){
            cin >> inp;
            inp_vec.push_back(inp);
        }
        paper.push_back(inp_vec);
    }
}
void calculateSum(int i, int j){
    for (auto a: shape){
        for (auto b: a){
            int total = 0;
            for (auto c: b){
                auto [x,y] = c;
                x += i, y += j;
                if (isInRange(x,y))
                    total += paper[x][y];
            }
            answer = max(answer, total);
        }
    }

}
void printAnswer() {
    for (int i=0; i<col_size; i++){
        for (int j=0; j<row_size; j++){
            calculateSum(i,j);
        }
    }
    cout << answer;
}
int main() {
    getInput();
    printAnswer();
    return 0;
}
