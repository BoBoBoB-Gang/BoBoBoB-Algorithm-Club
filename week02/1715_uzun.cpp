#include <bits/stdc++.h>
using namespace std;

int N, n, n1, n2, total = 0;
priority_queue<int> cards;

int main() {
    cin >> N;
    while(cin >> n) cards.push(-n);
    
    while(cards.size() > 1) {
        n1 = -cards.top(); cards.pop();
        n2 = -cards.top(); cards.pop();

        int sum = n1 + n2;
        cards.push(-sum);
        total += sum;
    }

    cout << total;
}
