import sys
from collections import defaultdict
input = sys.stdin.readline

N = int(input())
classroom = [[0] * N for _ in range(N)]
pref = defaultdict(list)
for _ in range(N**2):
    lst = list(map(int, input().strip().split(' ')))
    pref[lst[0]] = lst[1:]

dx = [0,1,-1,0]
dy = [1,0,0,-1]

def step1(arr):
    candidate = []
    like_max = 0
    for y in range(N):
        for x in range(N):
            if classroom[y][x] == 0:
                like_num = 0
                for i in range(4):
                    ny = y + dy[i]
                    nx = x + dx[i]

                    if 0 <= ny < N and 0 <= nx < N and classroom[ny][nx] in arr:
                        like_num += 1

                if like_num > like_max:
                    candidate = [(y, x)]
                    like_max = max(like_max, like_num)
                elif like_num == like_max:
                    candidate.append((y,x))
                else:
                    pass
                
    return candidate


def step2(arr):
    candidate = []
    empty_max = 0
    for n in arr:
        y, x = n
        empty_num = 0
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < N and 0 <= nx < N and classroom[ny][nx] == 0:
                empty_num += 1
        
        if empty_num > empty_max:
            candidate = [(y, x)]
            empty_max = max(empty_max, empty_num)
        elif empty_num == empty_max:
            candidate.append((y,x))
        else:
            pass
        
    return candidate


def step3(arr):
    candidates = sorted(arr, key=lambda x: (x[0], x[1]))

    return candidates[0]


#자리배치
for i in pref:
    student = i
    crush = pref[i]

    survivors = step1(crush)
    if len(survivors) == 1:
        y, x = survivors[0]
        classroom[y][x] = student

    # 1을 만족하는 칸 여러개
    else:
        survivors = step2(survivors)
        if len(survivors) == 1:
            y, x = survivors[0]
            classroom[y][x] = student

        # 2를 만족하는 칸 여러개
        else:
            y, x = step3(survivors)
            classroom[y][x] = student


#만족도 조사
satisfaction = 0
for y in range(N):
    for x in range(N):
        num = 0
        crush = pref[classroom[y][x]]
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < N and 0 <= nx < N and classroom[ny][nx] in crush:
                num += 1
        
        if num == 0:
            pass
        else:
            satisfaction += 10 ** (num-1)

print(satisfaction)