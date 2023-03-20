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