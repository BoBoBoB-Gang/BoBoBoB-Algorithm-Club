from collections import deque
import copy
import sys
input = sys.stdin.readline
 
N, M = tuple(map(int, input().strip().split(' ')))

lab = []
for _ in range(N):
    row = list(map(int, input().strip().split(' ')))
    lab.append(row)

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def infect():
    q = deque()
    test_lab = copy.deepcopy(lab)
    for i in range(N):
        for s in range(M):
            if test_lab[i][s] == 2:
                q.append((i,s))

    while q:
        i,s = q.popleft()

        for d in range(4):
            ny = i+dy[d]
            nx = s+dx[d]

            if (0<= ny < N) and (0<= nx < M) and test_lab[ny][nx] == 0:
                test_lab[ny][nx] = 2
                q.append((ny, nx))

    global result
    count = 0
    for i in range(N):
        for k in range(M):
            if test_lab[i][k] == 0:
                count +=1

    result = max(result, count)
    

def make_wall(count):
    if count == 3:
        infect()
        return
    for i in range(N):
        for k in range(M):
            if lab[i][k] == 0:
                lab[i][k] = 1
                make_wall(count+1)
                lab[i][k] = 0

result = 0 
make_wall(0)
print(result)