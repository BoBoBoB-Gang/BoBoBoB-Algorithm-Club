import sys
from collections import defaultdict
from collections import deque
input = sys.stdin.readline

N, E = map(int, input().strip().split(' '))
graph = defaultdict(list)
for i in range(E):
    a, b, c = map(int, input().strip().split(' '))
    graph[a].append((b, c))
    
V_1, V_2 = map(int, input().strip().split(' '))

cost = 0
def travel(current, value, visited):
    global cost
    if current == N and V_1 in visited and V_2 in visited: #
        cost = min(cost, cost + value)
        return 

    else:
        for i in graph[current]:
            



travel(1, [1])
print(cost)