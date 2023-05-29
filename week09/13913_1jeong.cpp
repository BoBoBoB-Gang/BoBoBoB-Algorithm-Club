#include <bits/stdc++.h>

using namespace std;
int N, K, ans;

int visited[1000001];
int graph[1000001];


void getAnswer(){
    queue<int> q;
    q.push(N);
    visited[N] = 0;
    graph[N] = -1;

    while (!q.empty()){
        int pq = q.front();
        q.pop();
        if (pq == K){
            break;
        }
        int tmp[3] = {pq*2, pq+1, pq-1};
        for (int i=0; i<3; i++){
            int t = tmp[i];
            if (0 <= t && t <= 1000000 && !visited[t]){
                visited[t] = visited[pq]+1;
                graph[t] = pq;
                q.push(t);
            }
        }
    }
    int a = K;
    deque<int> vec;
    vec.push_front(a);
    while (a != N){
        a = graph[a];
        vec.push_front(a);
    }
    cout << vec.size()-1 << endl;

    for (auto d: vec)
        cout << d << " ";

}


int main() {
    cin >> N >> K;
    if (N > K) {
        cout << N-K << endl;
        for (int i=N; i>=K; i--)
            cout << i <<" ";
    }
    else getAnswer();


    return 0;
}
