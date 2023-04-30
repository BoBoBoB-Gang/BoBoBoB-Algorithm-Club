import sys
input = sys.stdin.readline
N,M,x,y,K = map(int, input().split())
board = []
for _ in range(N):
    board.append(list(map(int,input().split())))
command = list(map(int,input().split()))
dr = [0,0,-1,1] # 동 서 북 남
dc = [1,-1,0,0]
r,c = x,y
dice = [0] * 6
for k in command:
    row,col = r+dr[k-1], c+dc[k-1]
    if not(0<=row<N and 0<=col<M):
        continue
    r,c = row,col
    if k == 1:
        dice[0], dice[2], dice[5], dice[3] = dice[3], dice[0], dice[2], dice[5]
    elif k == 2:
        dice[0], dice[2], dice[5], dice[3] = dice[2], dice[5], dice[3], dice[0]
    elif k == 3:
        dice[0], dice[4], dice[5], dice[1] = dice[4], dice[5], dice[1], dice[0]
    else:
        dice[0], dice[4], dice[5], dice[1] = dice[1], dice[0], dice[4], dice[5]
    if board[r][c] == 0:
        board[r][c] = dice[5]
    else:
        dice[5] = board[r][c]
        board[r][c] = 0
    print(dice[0])
