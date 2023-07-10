#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int N, maxlen=0;
string str[30];
long long total[30];

int main() {
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> str[i];
        int len = str[i].length();
        maxlen = max(maxlen, len);
    }

    int pt = 0, mylen = maxlen;
    while (pt != maxlen) {
        for (int i=0; i<N; i++) {
            if (pt < maxlen - str[i].length()) {continue;}
            int pt2 = pt - maxlen + str[i].length();
            int index = str[i][pt2] - 'A';
            total[index] += pow(10, str[i].length() - pt2 - 1);
        }
        pt++;
    }
    sort(total, total + 30, greater<int>());
    int num = 9, ans = 0;
    for (int i=0; i<30; i++){
        ans += total[i] * num;
        num--;
    }
    cout << ans;


    return 0;
}
