#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int num_size, max_weight;
vector<pair<int,int>> backpack;

void getInput(){
    int weight, value;
    cin >> num_size >> max_weight;
    for (int i=0; i<num_size; i++){
        cin >> weight >> value;
        backpack.push_back({weight, value});
    }
}
void printLargest() {
    sort(backpack.begin(), backpack.end());
    vector<vector<int>> arr(num_size+1, vector<int> (max_weight+1, 0));

    for (int i=1; i<=num_size; i++){
        int weight = backpack[i-1].first;
        int value = backpack[i-1].second;
        for (int j=0; j<=max_weight; j++){
            arr[i][j] = arr[i-1][j];
            if (weight <= j)
                arr[i][j] = max(value + arr[i-1][j-weight], arr[i][j]);
        }
    }
    cout << arr[num_size][max_weight];
}
int main() {
    getInput();
    printLargest();
    return 0;
}
