import sys
from collections import deque
# from copy import deepcopy
input = sys.stdin.readline

N, M = map(int, input().strip().split(' '))

ice_berg = []
for i in range(N):
    ice_berg.append(list(map(int, input().strip().split(' '))))

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def check_mass():
    num = 0
    visited = [[0]*M for _ in range(N)]
    for i in range(N):
        for s in range(M):
            if ice_berg[i][s] != 0 and visited[i][s] != 1:
                q = deque()
                q.append((i, s))
                
                #BFS
                while q:
                    r, c = q.popleft()
                    visited[r][c] = 1
                    
                    for t in range(4):
                        nx = c + dx[t]
                        ny = r + dy[t]
                        
                        if 0 <= nx < M and 0 <= ny < N and ice_berg[ny][nx] != 0 and visited[ny][nx] == 0:
                            q.append((ny, nx))
                num += 1
    
    return num


year = 0          
while(1):
    melt = [[0] * M for _ in range(N)]
    # new_ice_berg = deepcopy(ice_berg)
    for i in range(N):
        for s in range(M):
            if ice_berg[i][s] != 0:
                
                for t in range(4):
                    nx = s + dx[t]
                    ny = i + dy[t]
                    if 0 <= nx < M and 0 <= ny < N and ice_berg[ny][nx] == 0:
                        melt[i][s] += 1
                    else:
                        continue
    
    for i in range(N):
        for s in range(M):
            if ice_berg[i][s] - melt[i][s] > 0:
                ice_berg[i][s] -= melt[i][s]
            else:
                ice_berg[i][s] = 0

    year += 1

    mass = check_mass()
    if mass >= 2:
        break;
    else:
        flag = True
        for i in range(N):
            for s in range(M):
                if ice_berg[i][s] != 0:
                    flag = False

        if flag:
            year = 0
            break;

print(year)