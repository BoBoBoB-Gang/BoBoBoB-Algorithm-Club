import sys
from collections import deque

r, c = map(int,sys.stdin.readline().rstrip().split())

forest = [list(sys.stdin.readline().rstrip()) for _ in range(r)]
waterMap = [[-1] * c for _ in range(r)]
beaverMap = [[-1] * c for _ in range(r)]
start = []
end = []

Dx=[1,-1,0,0]
Dy=[0,0,1,-1]
q = deque()

for i in range(r):
    for j in range(c):
        if forest[i][j] == 'D':
            end = [i, j]
        elif forest[i][j] == 'S':
            start = [i, j]
            beaverMap[i][j] = 0
            forest[i][j] = '.'
        elif forest[i][j] == '*':
            q.append([i, j])
            waterMap[i][j] = 0

while q:
    x, y = q.popleft()
    for i in range(4):
        dx = x + Dx[i]
        dy = y + Dy[i]
        if 0 <= dx < r and 0 <= dy < c and forest[dx][dy] == '.' and waterMap[dx][dy] == -1:
            waterMap[dx][dy] = waterMap[x][y] + 1
            q.append([dx, dy])

q.append(start)
while q:
    x, y = q.popleft()
    for i in range(4):
        dx = x + Dx[i]
        dy = y + Dy[i]
        if 0 <= dx < r and 0 <= dy < c and forest[dx][dy] in '.D' and beaverMap[dx][dy] == -1:
            if beaverMap[x][y] + 1 < waterMap[dx][dy] or waterMap[dx][dy] == -1:
                beaverMap[dx][dy] = beaverMap[x][y] + 1
                q.append([dx, dy])

if beaverMap[end[0]][end[1]] == -1:
    print('KAKTUS')
else:
    print(beaverMap[end[0]][end[1]])