# 입력
import sys
from collections import deque
input = sys.stdin.readline
t = [deque(list(map(int,input().rstrip()))) for _ in range(4)] # 톱니 상태 저장

# 톱니 돌리기 
k = int(input())
for _ in range(k): 
	r = [] # 처음 톱니 상태 저장
	for i in range(4):
		r.append([t[i][6],t[i][2]])
	n,d = map(int,input().split())
	n = n-1
    
    # 왼쪽에 있는 톱니들 돌리기
	if n != 0 :
		for i in range(n,0,-1):
			if r[i][0] != r[i-1][1]:
				if (n-(i-1))%2 == 0:
					t[i-1].rotate(d)
				elif (n-(i-1))%2 != 0:
					t[i-1].rotate(-1*d)
			elif r[i][0] == r[i-1][1]:
				break
                
	# 오른쪽에 있는 톱니들 돌리기
	if n != 3:
		for i in range(n,3):
			if r[i][1] != r[i+1][0]:
				if (n-(i+1))%2 == 0:
					t[i+1].rotate(d)
				elif (n-(i+1))%2 != 0:
					t[i+1].rotate(-1*d)
			elif r[i][1] == r[i+1][0]:
				break
	t[n].rotate(d)
    
# 출력
res = 0
if t[0][0] == 1:
	res+=1
if t[1][0] == 1:
	res+=2
if t[2][0] == 1:
	res+=4
if t[3][0] ==1:
	res+=8
print(res)
