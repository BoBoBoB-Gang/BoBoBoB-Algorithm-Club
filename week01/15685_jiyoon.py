import sys
input = sys.stdin.readline
dc_num = int(input())

grid = [[0] * 101 for  _ in range(101)]
direction = [(1,0), (0,-1), (-1,0), (0,1)]

def spin(d):
    if d[1] != 0:
        return (-d[1], d[0])
    else:
        return (d[1], d[0])

def dc_move(n):
    dif = ((n[-2][0] - n[-1][0]), (n[-2][1] - n[-1][1]))
    spin_dif = spin(dif)
    spinned = ((n[-1][0] + spin_dif[0]), (n[-1][1] + spin_dif[1]))

    if len(n) >= 3:
        new_coord_array = [spinned]
        for i in range(len(n)-3,-1,-1):
            dif = ((n[i][0] - n[i+1][0]), (n[i][1] - n[i+1][1]))
            spin_dif = spin(dif)
            new_coord = ((new_coord_array[-1][0] + spin_dif[0]), (new_coord_array[-1][1] + spin_dif[1]))
            new_coord_array.append(new_coord)

        n += new_coord_array

    else:
        n.append(spinned)

    return n

for _ in range(dc_num):
    #입력값 저장 및 타입 변환
    dc_info = input().strip().split(' ')
    for i in range(len(dc_info)):
        dc_info[i] = int(dc_info[i])
    
    #0세대 드래곤 커브 설정
    dc = [(dc_info[0], dc_info[1]), (dc_info[0]+direction[dc_info[2]][0], dc_info[1]+direction[dc_info[2]][1])]
    #드래곤 커브
    if dc_info[3] != 0:
        for _ in range(dc_info[3]):
            dc = dc_move(dc)

    #격자 채우기
    for i in dc:
        if 101 > i[0] >= 0 and 101 > i[1] >= 0 and grid[i[1]][i[0]] == 0: 
            grid[i[1]][i[0]] = 1
        else:
            pass
        
# 사각형 갯수 세기
num = 0
for i in range(100):
    for s in range(100):
        check = grid[i][s] + grid[i+1][s] + grid[i][s+1] + grid[i+1][s+1]
        if check == 4:
            num += 1

print(num)
