import sys
from copy import deepcopy
input = sys.stdin.readline

N = int(input())

population = []
region = [[0] * N for _ in range(N)]
for _ in range(N):
    population.append(list(map(int, input().strip().split(' '))))

def check(arr):
    lst = [0] * 5
    for i in range(N):
        for s in range(N):
            lst[arr[i][s] - 1] += population[i][s]

    ans = max(lst) - min(lst)
    return ans



def expand(x, y, arr):
    global answer
    for d1 in range(1, N):
        for d2 in range(1, N):
            if y + d1 + d2 <= N and x + d1 + d2 <= N:
                arr_test = deepcopy(arr)
                for i in range(N):
                    for s in range(N):
                        if i <= y and s <= x:
                            arr_test[y][x] = 1
                        


    return




answer = int(1e9)
for i in range(N):
    for s in range(1, N-1):
        expand(s, i, region)
        