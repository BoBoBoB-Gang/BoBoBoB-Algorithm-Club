import sys
input = sys.stdin.readline
N,M = map(int,input().split())
r,c,d = map(int,input().split())
board = []   # N X M
for _ in range(N):
    board.append(list(map(int,input().split())))
dr = [-1,0,1,0]   # 북 서 남 동
dc = [0,-1,0,1]
cnt = 0
if d==1:
    d=3
elif d==3:
    d=1
while True:
    if board[r][c] == 0:
        board[r][c] = -1
        cnt += 1
    for i in range(1,5):
        d = (d+1)%4
        row = r+dr[d]
        col = c+dc[d]
        if board[row][col] == 0:
            break
        if i==4:
            i=5
    if i == 5:
        row, col = r+dr[(d+2)%4], c+dc[(d+2)%4]
        if board[row][col] == 1:
            break
    r,c = row,col

print(cnt)
