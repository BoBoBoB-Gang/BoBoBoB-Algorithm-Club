import sys
input = sys.stdin.readline

dr = [0, 0, 0, -1, 1]
dc = [0, 1, -1, 0, 0]

n, m, x, y, k = map(int, input().split())
maps = [list(map(int, input().split())) for _ in range(n)]
command = list(map(int, input().split()))
dice = [0] * 6


for d in command:
    nx = x + dr[d]
    ny = y + dc[d]

    if not 0 <= nx < n or not 0 <= ny < m:      # 범위 밖에 있는 좌표면 continue
        continue

    # 방향 명시
    east, west, south, north, up, down = dice[0], dice[1], dice[2], dice[3], dice[4], dice[5]

    # 주사위 굴리기
    if d == 1:
        dice[0], dice[1], dice[4], dice[5] = down, up, east, west
    elif d == 2:
        dice[0], dice[1], dice[4], dice[5] = up, down, west, east
    elif d == 3:
        dice[2], dice[3], dice[4], dice[5] = up, down, north, south
    elif d == 4:
        dice[2], dice[3], dice[4], dice[5] = down, up, south, north

    # 지도 숫자 0일 때
    if maps[nx][ny] == 0:
        maps[nx][ny] = dice[5]
    # 지도 숫자 0 아닐 때
    else:
        dice[5] = maps[nx][ny]
        maps[nx][ny] = 0

    # 값 갱신
    x, y = nx, ny
    print(dice[4])
