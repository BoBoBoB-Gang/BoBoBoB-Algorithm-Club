#include <bits/stdc++.h>

using namespace std;
int train_num, train[50001], d[4][50001], max_num;
long train_sum[50011], answer = 0;
vector<int> train_vec, clients;

int getAnswer(int depth, int index){
    if (depth == 3) return 0;
    if (index >= train_num) return 0;

    int& ret = d[depth][index];
    if (ret != -1) return ret;

    ret = getAnswer(depth+1, index + max_num);
	ret += clients[index];
	ret = max(ret, getAnswer(depth, index+1));
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    cin >> train_num;
    for (int i=0; i<train_num; i++){
        cin >> train[i];
        if (i == 0) train_sum[i] = train[i];
        else train_sum[i] = train_sum[i-1] + train[i];
    }
    cin >> max_num;
    for (int i=0; i<train_num; i++){
        int a = (i == 0) ? 0 : train_sum[i-1];
        int b = (i+max_num-1 >= train_num) ? train_sum[train_num-1] : train_sum[i+max_num-1];
        clients.push_back(b - a);
    }
    if (max_num == 0) cout << 0;
    else {
        cout << getAnswer(0, 0);
    }
    return 0;
}
