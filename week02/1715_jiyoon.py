# 잘못된 코드
import sys
input = sys.stdin.readline

N = int(input())
card_stacks = []
for _ in range(N):
    card_stacks.append(int(input()))

card_stacks.sort()

num = 0
def combine(arr):
    global num
    new_arr = []
    for i in range(0, len(arr), 2):
        if i != len(arr) - 1:
            comb = arr[i] + arr[i+1]
            num += comb
            new_arr.append(comb)
        else:
            new_arr.append(arr[i])
    
    if len(new_arr) > 1:
        combine(new_arr)
    else:
        return
    
combine(card_stacks)
print(num)


# 올바른 코드
import heapq
import sys
input = sys.stdin.readline

N = int(input())

cards = []
result = 0

for i in range(N):
    heapq.heappush(cards, int(input()))

if len(cards) == 1:
    print(0)
else:
    while len(cards) > 1:
        plus = heapq.heappop(cards) + heapq.heappop(cards) # 가장 작은 값 반환
        result += plus
        heapq.heappush(cards, plus) # 이미 합친 카드더라도 다시 정렬해준다 -> 자동으로 정렬해주는 heap을 써야 시간초과가 안난다

    print(result)