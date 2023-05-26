from sys import stdin,maxsize
from itertools import combinations
from typing import Tuple, List

def next_generation(count:int, comb:Tuple) -> Tuple[int, List[List[int,int]]]:
    temp = []
    for c in comb:
        for i in range(4):
            new_x = dx[i] + c[0]
            new_y = dy[i] + c[1]
            if 0<=new_x<n and 0<=new_y<n and matrix[new_x][new_y] != 1 and not visited[new_x][new_y]:
                visited[new_x][new_y] = True
                if matrix[new_x][new_y] == 0:
                    count+=1
                temp.append([new_x,new_y])
    comb = temp
    return count, comb

def start(comb: Tuple[List[int, int]], count) -> int:
    generation = 0
    while count < total and comb:
        count, comb = next_generation(count, comb)
        generation+=1

    if count != total:
        return maxsize
    return generation

n,m = map(int, stdin.readline().split())
dx = [0,0,-1,1]
dy = [-1,1,0,0]
answer = maxsize
total = n*n
virus_count = 0
matrix = [ list(map(int, stdin.readline().split())) for _ in range(n)]
virus = []
for i, mat in enumerate(matrix):
    for j, d in enumerate(mat):
        if(d == 2):
            virus.append([i,j,])
            virus_count += 1
        elif(d == 1):
            total -= 1

for comb in combinations(virus,m):
    visited = [[False]*n for _ in range(n)]
    answer = min(answer, start(comb, virus_count))

print(answer if answer != maxsize else -1)