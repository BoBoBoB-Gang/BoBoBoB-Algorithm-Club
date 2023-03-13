import sys

input = sys.stdin.readline

n = int(input())

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

arr = [[0] * 101 for _ in range(101)]

for _ in range(n):
    x, y, d, g = map(int, input().split())
    arr[x][y] = 1

    move = [d]
    for _ in range(g):
        tmp = []
        for i in range(len(move)):
            tmp.append((move[-i - 1] + 1) % 4)
        move.extend(tmp)

    for i in move:
        nx = x + dx[i]
        ny = y + dy[i]
        arr[nx][ny] = 1
        x, y = nx, ny

ans = 0
for i in range(100):
    for j in range(100):
        if arr[i][j] and arr[i + 1][j] and arr[i][j + 1] and arr[i + 1][j + 1]:
            ans += 1

print(ans)
