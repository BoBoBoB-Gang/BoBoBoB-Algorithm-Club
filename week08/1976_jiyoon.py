import sys
from collections import deque
input = sys.stdin.readline

N = int(input().strip())
M = int(input().strip())

conn = [[0] * N]
for _ in range(N):
    conn.append([0] + list(map(int, input().strip().split(' '))))

travel_plan = list(map(int, input().strip().split(' ')))


def check(start, end):
    q = deque()
    if conn[start][end]:
        return True
    else:
        for city in range(len(conn[start])):
            if conn[start][city]:
                q.append(city)
        
        while(q):
            next_start = q.popleft()
            for city in range(len(conn[next_start])):
                if conn[next_start][city]:
                    if city == end:
                        return True
                    else:
                        q.append(city)
        
    return False


flag = True
for i in range(len(travel_plan) - 1):
    if not check(travel_plan[i], travel_plan[i+1]):
        flag = False
        break


if flag:
    print("YES")
else:
    print("NO")
