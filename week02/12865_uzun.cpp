#inlude <bits/stdc++.h>
using namespace std;

// bottom-up
pair<int, int> items[101];
int dp[101][100001]; // [갯수][무게] = 최고가치

int main() {
    int N, K, W, V;
    
    cin >> N >> K;
    for(int i=1; cin >> W >> V; i++) 
        items[i] = {W, V};
    
    for(int i=1;i<=N;i++) {
        for(int k=1;k<=K;k++) {
            auto [w, v] = items[i];
            if(w <= k) dp[i][k] = max(dp[i-1][k], dp[i-1][k-w] + v);
            else dp[i][k] = dp[i-1][k];
        }
    }

    cout << dp[N][K];
}

// top-down
int N, K;
int value[101],weight[101], dp[100][100001] = {0,};

int knapsack(int n,int k){
    if(n < 0) return 0;
    if(dp[n][k]) return dp[n][k];
    if(k < weight[n]) return dp[n][k] = knapsack(n-1,k);

    return dp[n][k] = max(knapsack(n-1,k), knapsack(n-1,k-weight[n]) + value[n]) ;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> weight[i] >> value[i];

    cout << knapsack(N-1,K);
    return 0;
}
