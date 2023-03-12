#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int r,c,k, sort_time=0;
int row_size=3, col_size=3;
int arr[100][100];

void getInput() {
    cin >> r >> c >> k;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
}
bool isValid(int num){
    return num == arr[r-1][c-1];
}
bool isNumInVec(int num, vector<pair<int,int>> &vec){
    for (int i=0; i<vec.size(); i++){
        if (vec[i].first == num){
            vec[i].second ++;
            return true;
        }
    }
    return false;
}
bool cmp(pair<int,int> a, pair<int, int> b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
void rowSort() {
    for (int i=0; i<col_size; i++){
        vector<pair<int,int>> vec;
        for (int j=0; j<row_size; j++){
            if (!isNumInVec(arr[i][j], vec) && arr[i][j]!=0)
                vec.push_back({arr[i][j], 1});
        }
        sort(vec.begin(), vec.end(), cmp);
        int vec_size = vec.size();
        row_size = max(row_size, vec_size*2);
        int index = 0;
        for (auto v: vec){
            arr[i][index] = v.first;
            arr[i][index+1] = v.second;
            index += 2;
        }
        while (index < row_size){
            arr[i][index] = 0;
            index++;
        }

    }

}
void columnSort(){
    for (int i=0; i<row_size; i++){
        vector<pair<int,int>> vec;
        for (int j=0; j<col_size; j++){
            if (!isNumInVec(arr[j][i], vec) && arr[j][i]!=0)
                vec.push_back({arr[j][i], 1});
        }

        sort(vec.begin(), vec.end(), cmp);
        int vec_size = vec.size();
        col_size = max(col_size, vec_size*2);
        int index = 0;
        for (auto v: vec){
            arr[index][i] = v.first;
            arr[index+1][i] = v.second;
            index += 2;
        }
        while (index < col_size){
            arr[index][i] = 0;
            index++;
        }
    }
}

void getSmallestTime(){
    while (!isValid(k) && sort_time<=100) {
        if (row_size <= col_size) rowSort();
        else columnSort();

        sort_time++;
    }
    if (sort_time > 100) cout << -1;
    else cout << sort_time;
}

int main() {
    getInput();
    getSmallestTime();
    return 0;
}
