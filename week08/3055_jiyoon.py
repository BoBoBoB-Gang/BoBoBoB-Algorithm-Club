import sys
from collections import deque
input = sys.stdin.readline

R, C = map(int, input().strip().split(' '))

forest = []
water_q = deque()
hedgehog_q = deque()
for i in range(R):
    lst = [*input().strip()]
    for s in range(C):
        if lst[s] == "S":
            hedgehog_q.append((i,s))
        elif lst[s] == "*":
            water_q.append((i,s))

    forest.append(lst)

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]


def move_hedgehog(y, x):
    global forest, hedgehog_q, success
    flag = 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < R and 0 <= nx < C:
            if forest[ny][nx] == "." :
                if not hedgehog_visit[ny][nx]:
                    hedgehog_q.append((ny,nx))
                    hedgehog_visit[ny][nx] = 1
                    flag = 1
            elif forest[ny][nx] == "D":
                success = True
                break

    return flag 
    

def expand_water(y, x):
    global forest, water_q, water_visit
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if (0 <= ny < R and 0 <= nx < C) and (forest[ny][nx] == "." or forest[ny][nx] == "S"):
            if not water_visit[ny][nx]:
                forest[ny][nx] = '*'
                water_visit[ny][nx] = 1
                water_q.append((ny,nx))
            else:
                continue
    return 


ans = 0
success = False
water_visit = [[0] * C for _ in range(R)]
hedgehog_visit = [[0] * C for _ in range(R)]

while(hedgehog_q):
    # 한 주기씩 실행
    # 물 확장
    num = len(water_q)
    for _ in range(num):
        water_y, water_x = water_q.popleft()
        expand_water(water_y, water_x)

    #고슴도치 이동
    num = len(hedgehog_q)
    sum_check = 0
    for _ in range(num):
        hedgehog_y, hedgehog_x = hedgehog_q.popleft()
        sum_check += move_hedgehog(hedgehog_y, hedgehog_x)

        #q에 굴이 있을 경우
        if success:
            ans += 1
            break

    if not success:
        if sum_check > 0:
            ans += 1
        else:
            ans = 0
            break
    else:
        break


if success:
    print(ans)
else:
    print("KAKTUS")