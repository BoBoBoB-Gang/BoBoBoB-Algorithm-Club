#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int curve_size, x, y, direction, generator;
vector<pair<int,int>> dragon_point;

pair<int, int> getCurvedPoint(pair<int,int> a, pair<int, int> b){
    return make_pair(b.first-a.second+b.second, a.first-b.first+b.second);
}
bool isExist(pair<int,int> point) {
    for (auto d: dragon_point){
        if (d == point) return true;
    }
    return false;
}
void makeDragonPoint() {
    vector<pair<int,int>> dragon_part;
    dragon_part.push_back({x,y});
    switch(direction){
    case 0: x++; break;
    case 1: y--; break;
    case 2: x--; break;
    case 3: y++; break;
    default: break;
    }
    dragon_part.push_back({x,y});
    while(generator > 0) {
        pair<int, int> pivot = dragon_part.back();
        int dragon_size = dragon_part.size()-2;
        for (int i=dragon_size; i>=0; i--){
            dragon_part.push_back(getCurvedPoint(dragon_part[i], pivot));
        }
        generator--;
    }
    for (auto d: dragon_part){
        if (!isExist(d)) dragon_point.push_back(d);
    }
}
bool isValidPoint(int x, int y){
    return isExist({x+1,y}) && isExist({x,y+1}) && isExist({x+1, y+1});
}
void getAnswer() {
    int answer = 0;
    sort(dragon_point.begin(), dragon_point.end());
    for (auto d: dragon_point){
        if (isValidPoint(d.first, d.second))
            answer++;
        //cout <<d.first << " " <<d.second <<endl;
    }
    cout <<answer;
}
void main_dragon_curve(){
    int inp;
    cin >> curve_size;
    for (int i=0; i<curve_size; i++) {
        cin >> x >> y >> direction >> generator;
        makeDragonPoint();
    }
    getAnswer();
}

int main() {
    main_dragon_curve();
    return 0;
}
