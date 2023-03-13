import sys; input = sys.stdin.readline
import copy

def wall_construct(wall_cnt):
    if wall_cnt == 3:
        virus_spread()
        return
    for n in range(N):
        for m in range(M):
            if board[n][m] == 0:
                board[n][m] = 1 # 벽 설치
                wall_construct(wall_cnt + 1)
                board[n][m] = 0 # 초기화

def virus_spread():
    global answer
    board_wall = copy.deepcopy(board)
    virus = [(n, m) for n in range(N) for m in range(M) if board_wall[n][m] == 2]

    while virus:
        x, y = virus.pop()
        for dx, dy in direction:
            nx = x + dx
            ny = y + dy
            if 0 <= nx < N and 0 <= ny < M and board_wall[nx][ny] == 0:
                board_wall[nx][ny] = 2
                virus.append((nx, ny)) 

    safezone_cnt = 0
    for row in board_wall:
        safezone_cnt += row.count(0)
    answer = max(answer, safezone_cnt)

if __name__ == "__main__":
    N, M = map(int, input().split())
    board = [list(map(int, input().split())) for _ in range(N)]
    direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    answer = 0
    wall_construct(0)
    print(answer)
