import sys
input = sys.stdin.readline

# r,c,k 정보 저장
info = input().strip().split(' ')
for i in range(len(info)):
    info[i] = int(info[i])

# 배열 저장
arr = []
for _ in range(3):
    row = input().strip().split(' ')
    for i in range(len(row)):
        row[i] = int(row[i])
    arr.append(row)

sec = 0
flag = False
while sec <= 100:

    try:
        if arr[info[0]-1][info[1]-1] == info[2]:
            flag = True
            break
    
    except IndexError:
        pass
    
    row_num = len(arr)
    col_num = len(arr[0])

    # 행 or 열의 최대 사이즈 초깃값 설정
    max_size = 0

    # R연산
    if row_num >= col_num:
        idx = 0
        for i in arr:
            row_unique = list(set(i))
            # 0이 있을 경우 제거
            if row_unique.count(0):
                row_unique.remove(0) 

            unique_num = []
            for s in row_unique:
                unique_num.append((s, i.count(s)))
            
            # 갯수 -> 크기 순
            sorted_lst = sorted(unique_num, key=lambda x: (x[1], x[0]))
            i = []
            for s in sorted_lst:
                (num, count) = s
                i.append(num)
                i.append(count)
            
            # arr & 행 크기 최댓값 갱신
            max_size = max(max_size, len(i))
            arr[idx] = i
            idx += 1

        # 빈 공간 0 채우기 
        for i in arr:
            if len(i) < max_size:
                i += [0]*(max_size-len(i)) 
                
    # C연산
    else:
        arr_col = []
        for i in range(len(arr[0])):
            col_lst = []
            for s in arr:
                col_lst.append(s[i])
            col_unique = list(set(col_lst))

            # 0이 있을 경우 제거
            if col_unique.count(0):
                col_unique.remove(0) 

            unique_num = []
            for s in col_unique:
                unique_num.append((s, col_lst.count(s)))
            
            # 갯수 -> 크기 순
            sorted_lst = sorted(unique_num, key=lambda x: (x[1], x[0]))
            col = []
            for s in sorted_lst:
                (num, count) = s
                col.append(num)
                col.append(count)

            # 열 크기 최댓값 갱신
            max_size = max(max_size, len(col))
            arr_col.append(col)


        # 빈 공간 0 채우기 
        for i in arr_col:
            if len(i) < max_size:
                i += [0]*(max_size-len(i)) 

        arr = list(zip(*arr_col))

    sec += 1


if flag:
    print(sec)
else:
    print(-1)