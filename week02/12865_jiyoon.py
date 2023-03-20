import sys
input = sys.stdin.readline

N, K = map(int, input().strip().split(' '))
d = [[0]*(K+1) for _ in range(N+1)]
item = [[0,0]]

for _ in range(N):
    item.append(list(map(int, input().strip().split(' '))))

for i in range(1, N+1):
    for j in range(1, K+1):
        w = item[i][0]
        v = item[i][1]

        if j < w:
            d[i][j] = d[i-1][j]
        else:
            d[i][j] = max(d[i-1][j], (d[i-1][j-w]+v))

print(d[N][K])


