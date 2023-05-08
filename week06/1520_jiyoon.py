import sys
sys.setrecursionlimit(10**6)
from copy import deepcopy
input = sys.stdin.readline

N, M = map(int, input().strip().split(' '))
mapp = []
for _ in range(N):
    mapp.append(list(map(int, input().strip().split(' '))))

num = 0
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def check_lower_h(cur_x, cur_y, test_map):
    candidates = []
    for i in range(4):
        nx = cur_x + dx[i]
        ny = cur_y + dy[i]
        if 0 <= nx < M and 0 <= ny < N and test_map[ny][nx] != 0:
            if test_map[cur_y][cur_x] > test_map[ny][nx]:
                candidates.append((nx, ny))
        
    return candidates

def DFS(cur_x, cur_y, arr):
    global num
    candidates = check_lower_h(cur_x, cur_y, arr)
    for i in candidates:
        test_map = deepcopy(arr)
        x, y = i
        test_map[y][x] = 0
        if x == M-1 and y == N-1:
            num += 1
        else:
            DFS(x, y, test_map)

DFS(0, 0, mapp)
print(num)