import sys
from collections import deque
from itertools import combinations
from copy import deepcopy
import numpy
import math
input = sys.stdin.readline

N, M = map(int, input().split())

lab = []
virus = []
for i in range(N):
    lst = list(map(int, input().strip().split(' ')))
    for s in range(N):
        if lst[s] == 2:
            virus.append((i,s))
            lst[s] = '*'
        elif lst[s] == 1:
            lst[s] = '-' 
    lab.append(lst)
            
virus_case =  list(combinations(virus, M))

def check():
    flag = True
    for r in range(N):
        for c in range(N):
            if test_lab[r][c] == 0:
                flag = False
                return flag
    
    return flag


dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

result = [1] * len(virus_case)
q = deque()
min_time = math.inf
flag = False

for case in range(len(virus_case)):
    test_lab = deepcopy(lab) 
    for i in virus_case[case]:
       test_lab[i[0]][i[1]] = -1 #활성 바이러스 위치
       q.append(i)

    time = 0
    loop, loop_count = len(q), 0
    while q:
        if loop_count == loop:
            if check(): #바이러스가 전부 퍼졌을 때
                q.clear()
                flag = True
                break
            else:
                time += 1
                loop_count = 0
                loop = len(q)
        
        cur_y, cur_x = q.popleft()
        for s in range(4):
            nx = cur_x + dx[s]
            ny = cur_y + dy[s]
        
            if 0<=nx<N and 0<=ny<N:
                if test_lab[ny][nx] == 0:
                    test_lab[ny][nx] += time
                    q.append((ny,nx))
                elif test_lab[ny][nx] == '*':
                    test_lab[ny][nx] = -1
                    q.append((ny,nx))

        loop_count += 1

    if flag:
        min_time = min(time, min_time)
        result[case] = 0

if not numpy.prod(result):
    print(min_time)
else:
    print(-1)