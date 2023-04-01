import sys
input = sys.stdin.readline

N, M = map(int, input().strip().split(' '))
r, c, d = map(int, input().strip().split(' '))

room = []
for _ in range(N):
    room.append(list(map(int, input().strip().split(' '))))

dx = [0,1,0,-1]
dy = [-1,0,1,0] 

while(1):
    room[r][c] = 2
    for i in range(4):
        ny = r + dy[i]
        nx = c + dx[i]

        if 0 <= ny < N and 0 <= nx < M and room[ny][nx] == 0:
            
