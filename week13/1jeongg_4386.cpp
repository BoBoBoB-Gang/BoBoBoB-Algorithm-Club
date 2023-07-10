#include <bits/stdc++.h>

using namespace std;
int sz;
vector<pair<double, double>> stars;
vector<int> vec;
bool visited[101];
double answer = 0;

double getDistance(pair<double, double> s1, pair<double, double> s2){
    auto [a,b] = s1;
    auto [c,d] = s2;
    return sqrt((c-a)*(c-a) + (d-b)*(d-b));
}
int getClosestStar(int last_star){
    int mystar;
    double mydistance = 1e9;
    for (auto v: vec){
        for (auto s=stars.begin(); s<stars.end(); s++){
            int index = s - stars.begin();
            if (index == v) continue;
            if (!visited[index]){
                double dist = getDistance(stars[v], *s);
                if (mydistance > dist){
                    mystar = index;
                    mydistance = dist;
                }
            }
        }
    }
    answer += mydistance;
    return mystar;
}
int main() {
    cin >> sz;
    for (int i=0; i<sz; i++){
        double a, b;
        cin >> a >> b;
        stars.push_back({a,b});
    }
    sort(stars.begin(), stars.end());

    vec.push_back(0);
    visited[0] = true;
    while (vec.size() != stars.size()){
        int index = getClosestStar(vec.back());
        visited[index] = true;
        vec.push_back(index);
    }

    cout << answer;


    return 0;
}
