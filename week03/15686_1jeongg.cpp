#include <iostream>
#include <vector>
#include <algorithm>
#define VECTOR vector<pair<int, int>>

using namespace std;

VECTOR chickens;
VECTOR house;
VECTOR chicken_group;

int city_size, max_chicken;
int answer = 1e9;

void getInput() {
    int inp;
    cin >> city_size >> max_chicken;
    for (int i=0; i<city_size; i++){
        for (int j=0; j<city_size; j++){
            cin >> inp;
            if (inp == 1)
                house.push_back({i,j});
            if (inp == 2)
                chickens.push_back({i,j});
        }
    }
}
int getPartialDistance(int row, int col){
    int dist=1e9;
    for (auto c: chicken_group){
        auto [x,y] = c;
        dist = min(dist, abs(row-x)+abs(col-y));
    }
    return dist;
}
int getChickenDistance(){
    int answer = 0;
    for (auto h: house){
        auto [x,y] = h;
        answer += getPartialDistance(x,y);
    }
    return answer;
}
void makeChickenGroup(int x) {
    if (chicken_group.size() == max_chicken){
        answer = min (answer, getChickenDistance());
        return;
    }
    for (int i=x; i<chickens.size(); i++){
        chicken_group.push_back(chickens[i]);
        makeChickenGroup(i+1);
        chicken_group.pop_back();
    }
}
int main() {
    getInput();
    makeChickenGroup(0);
    cout <<answer;
    return 0;
}
