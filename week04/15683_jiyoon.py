import sys
from collections import defaultdict
from copy import deepcopy
input = sys.stdin.readline

N, M = map(int, input().strip().split(' '))
room = []
for _ in range(N):
    room.append(list(map(int, input().strip().split(' '))))

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]


def cctv1(arr, case, coord):
    global arr
    y, x = coord
    while (0<=x<M and 0<=y<N):
        y += dy[case]
        x += dx[case]
        arr[y][x] = '#'

    return


def cctv2(arr, case, coord):
    global arr
    y, x = coord
    for n in range(0, 3, 2):
        ny, nx = y, x
        while (0<=nx<M and 0<=ny<N):
            ny += dy[case+n]
            nx += dx[case+n]
            arr[ny][nx] = '#'

    return


def cctv3(arr, case, coord):
    global arr
    y, x = coord
    for n in range(0, 2):
        if case == 3 and n == 1:
            case = -1
        ny, nx = y, x
        while (0<=nx<M and 0<=ny<N):
            ny += dy[case+n]
            nx += dx[case+n]
            arr[ny][nx] = '#'

    return


def cctv4(arr, case, coord):
    global arr
    y, x = coord

    for n in range(4):
        if n == 2:
            continue
        ny, nx = y, x
        while (0<=nx<M and 0<=ny<N):
            ny += dy[case-n]
            nx += dx[case-n]
            arr[ny][nx] = '#'

    return


def cctv5(arr, coord):
    global arr
    y, x = coord
    for i in range(4):
        ny, nx = y, x
        while (0<=nx<M and 0<=ny<N):
            ny += dy[i]
            nx += dx[i]
            arr[ny][nx] = '#'

    return
        

def check(arr):
    num = 0
    for r in room:
        for c in r:
            if c == 0:
                num += 1
    
    return num


bs = N*M


cctv_loc = defaultdict(list)
for i in range(1, 6):
    cctv_loc[i] = []

# cctv 위치 정보 저장
for i in range(N):
    for s in range(M):
        if room[i][s] != 0:
            if room[i][s] == 1:
                cctv_loc[1].append((i, s))
            elif room[i][s] == 2:
                cctv_loc[2].append((i, s))
            elif room[i][s] == 3:
                cctv_loc[3].append((i, s))
            elif room[i][s] == 4:
                cctv_loc[4].append((i, s))
            elif room[i][s] == 5:
                cctv_loc[5].append((i, s))
            else:
                pass
        
        else:
            pass


for i in cctv_loc[1]:
    for 

            