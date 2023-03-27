import sys
import copy
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().strip().split(' '))
city = []
for _ in range(N):
    city.append(list(map(int, input().strip().split(' '))))


def select_chick(arr, n):
    result = []
    if n > len(arr):
        return result
    if n == 1:
        for i in arr:
            result.append([i])
    elif n > 1:
        for i in range(len(arr) - n + 1):
            for j in select_chick(arr[i+1:], n-1):
                result.append([arr[i]] + j)
    
    return result


dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
chick_coord = []
for r in range(N):
    for c in range(N):
        if city[r][c] == 2:
            chick_coord.append((r, c))
            city[r][c] = 0 # 처음부터 0으로 초기화 시켜놓는다

chick_cases = select_chick(chick_coord, M)
# print(type(sys.maxsize))

distance = sys.maxsize
for case in chick_cases:
    city_test = copy.deepcopy(city)
    for c in case:
        city_test[c[0]][c[1]] = 2
    
    result = 0
    for i in range(N):
        for s in range(N):
            if city_test[i][s] == 1:
                q = deque([(i, s)])
                visited = []
                
                while(q):
                    y, x = q.popleft()
                    visited.append((y, x))
                    if city_test[y][x] == 2:
                        result += (abs(y - i) + abs(x - s))
                        break

                    for t in range(4):
                        ny = y + dy[t]
                        nx = x + dx[t]

                        if 0 <= ny < N and 0 <= nx < N:
                            # for k in visited:
                            #     if k[0] != ny and k[1] != nx:
                            q.append((ny, nx))


    distance = min(result, distance)               

print(distance)