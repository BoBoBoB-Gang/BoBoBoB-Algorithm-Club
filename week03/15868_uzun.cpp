#include <bits/stdc++.h>
using namespace std;

int N, M, tmp, min_city_dist = INT_MAX;
int city[51][51];
vector<pair<int, int>> houses, stores, selected_stores;

int getDistance(pair<int, int> &a, pair<int, int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int getChickenDistance(pair<int, int> &house) {
    int chicken_dist = INT_MAX;

    for(auto &store: selected_stores)
        chicken_dist = min(chicken_dist, getDistance(house, store));
    
    return chicken_dist;
}

void selectStores(int idx) {

    if(selected_stores.size() == M) {
        int city_chicken_dist = 0;

        for(auto &house: houses)
            city_chicken_dist +=  getChickenDistance(house);

        min_city_dist = min(min_city_dist, city_chicken_dist);
        return;
    }

    for(int i=idx; i<stores.size(); i++) {
        selected_stores.push_back(stores[i]);
        selectStores(i+1);
        selected_stores.pop_back();
    }
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++) 
        for(int j=0;j<N;j++) {
            cin >> tmp;
            if(tmp == 1) houses.emplace_back(i, j);
            else if(tmp == 2) stores.emplace_back(i, j);
        }

    selectStores(0);
    
    cout << min_city_dist;
}
