#include <bits/stdc++.h>
using namespace std;
int N, K, W[101], V[101], dp[101][100001];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> W[i] >> V[i];
    for(int i=1; i<=N; i++) {
        for(int j=0; j<=K; j++) {
            if(j<W[i]) dp[i][j] = dp[i-1][j];
            else if(dp[i-1][j-W[i]]+V[i] > dp[i-1][j]) dp[i][j] = dp[i-1][j-W[i]]+V[i];
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    int M = 0;
    for(int i=0; i<=K; i++) M = max(M,dp[N][i]);
    cout << M;
}