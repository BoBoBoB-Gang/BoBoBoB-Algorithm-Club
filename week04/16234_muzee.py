from collections import deque
import sys

std = sys.stdin

A = []
dr = [1,-1,0,0]
dc = [0,0,1,-1]

N,L,R = map(int,std.readline().split())
for _ in range(N):
    A.append(list(map(int,std.readline().split())))

def findUnit(r,c,visited):
    que = deque([(r,c)])
    visited[r][c] = 1
    population = A[r][c]           
    countries = set([(r,c)])        
    
    while que:
        xr,xc = que.popleft()
        for i in range(4):
            row,col = xr+dr[i], xc+dc[i]
            # if not (0<=row<N and 0<=col<N):
            #     continue
            if (0<=row<N and 0<=col<N) and not visited[row][col] and L<=abs(A[xr][xc]-A[row][col])<=R:
                que.append((row,col))
                visited[row][col] = 1
                countries.add((row,col))
                population += A[row][col]
                
    for row,col in countries:
        A[row][col] = population//len(countries)
                
    return len(countries)

days, isMoved = 0,1
while isMoved:
    visited = [[0 for _ in range(N)] for k in range(N)]
    isMoved = 0
    for i in range(N):
        for j in range(N):
            if visited[i][j]:
                continue
            if findUnit(i,j,visited)!=1:
                isMoved = 1
    if isMoved:
        days += 1

print(days)
