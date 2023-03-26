#include <bits/stdc++.h>
using namespace std;

int N, M;
int paper[501][501];


int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> paper[i][j];
    
    int max_sum = 0;

    // ㅡ
    for(int i=0;i<N;i++) {
        for(int j=0;j<M-3;j++) {
            int local_sum = 
                paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i][j+3];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㅣ
    for(int i=0;i<N-3;i++) {
        for(int j=0;j<M;j++) {
            int local_sum = 
                paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+3][j];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㅁ
    for(int i=0;i<N-1;i++) {
        for(int j=0;j<M-1;j++) {
            int local_sum = 
                paper[i][j] + paper[i+1][j] + paper[i][j+1] + paper[i+1][j+1];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴㄱ 1
    for(int i=0;i<N-2;i++) {
        for(int j=0;j<M-1;j++) {
            int local_sum = 
                paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+2][j+1];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴㄱ 2
    for(int i=0;i<N-1;i++) {
        for(int j=0;j<M-2;j++) {
            int local_sum = 
                paper[i+1][j] + paper[i+1][j+1] + paper[i][j+1] + paper[i][j+2];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴㄱ 3 뒤집어서
    for(int i=0;i<N-2;i++) {
        for(int j=0;j<M-1;j++) {
            int local_sum = 
                paper[i][j+1] + paper[i+1][j+1] + paper[i+1][j] + paper[i+2][j];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴㄱ 4 뒤집어서
    for(int i=0;i<N-1;i++) {
        for(int j=0;j<M-2;j++) {
            int local_sum = 
                paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+1][j+2];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴ 1
    for(int i=0;i<N-2;i++) {
        for(int j=0;j<M-1;j++) {
            int local_sum = 
                paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+2][j+1];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴ 2
    for(int i=0;i<N-1;i++) {
        for(int j=0;j<M-2;j++) {
            int local_sum = 
                paper[i][j] + paper[i+1][j] + paper[i][j+1] + paper[i][j+2];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴ 3 (ㄱ)
    for(int i=0;i<N-2;i++) {
        for(int j=0;j<M-1;j++) {
            int local_sum = 
                paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴ 4
    for(int i=0;i<N-1;i++) {
        for(int j=0;j<M-2;j++) {
            int local_sum = 
                paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2] + paper[i][j+2];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴ 5
    for(int i=0;i<N-2;i++) {
        for(int j=0;j<M-1;j++) {
            int local_sum = 
                paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i][j+1];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴ 6
    for(int i=0;i<N-1;i++) {
        for(int j=0;j<M-2;j++) {
            int local_sum = 
                paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴ 7
    for(int i=0;i<N-2;i++) {
        for(int j=0;j<M-1;j++) {
            int local_sum = 
                paper[i+2][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㄴ 8
    for(int i=0;i<N-1;i++) {
        for(int j=0;j<M-2;j++) {
            int local_sum = 
                paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+2];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㅗ
    for(int i=0;i<N-1;i++) {
        for(int j=0;j<M-2;j++) {
            int local_sum = 
                paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2] + paper[i][j+1];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㅏ
    for(int i=0;i<N-2;i++) {
        for(int j=0;j<M-1;j++) {
            int local_sum = 
                paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+2][j];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㅜ
    for(int i=0;i<N-1;i++) {
        for(int j=0;j<M-2;j++) {
            int local_sum = 
                paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+1];

            max_sum = max(max_sum, local_sum);
        }
    }

    // ㅓ
    for(int i=0;i<N-2;i++) {
        for(int j=0;j<M-1;j++) {
            int local_sum = 
                paper[i+1][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1];

            max_sum = max(max_sum, local_sum);
        }
    }

    cout << max_sum;
}
