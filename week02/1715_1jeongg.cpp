#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int num_size;
priority_queue<int, vector<int>, greater<int>> cards;

void getInput(){
    int inp;
    cin >> num_size;
    for (int i=0; i<num_size; i++){
        cin >> inp;
        cards.push(inp);
    }
}
void printCompareCount() {
    int answer = 0;
    while(cards.size() > 1){
        int c1 = cards.top();
        cards.pop();
        int c2 = cards.top();
        cards.pop();
        cards.push(c1 + c2);
        answer += (c1+c2);
    }
    cout << answer;
}
int main() {
    getInput();
    printCompareCount();
    return 0;
}
