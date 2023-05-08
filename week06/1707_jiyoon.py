import sys
# from collections import defaultdict
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

K = int(input())

def dfs(start):
    global isValid
    visited[start] = True
    for i in node_info[start]:
        if not visited[i]:
            team[i] = (team[start] + 1)%2
            dfs(i)
        elif team[i] == team[start]:
            isValid = False



for _ in range(K):
    isValid = True
    V, E = map(int, input().strip().split(' '))
    visited = [0] * (V+1)
    node_info = [[] for _ in range(V+1)]
    team = [0] * (V+1)
    for _ in range(E):
        k, v = map(int, input().strip().split(' '))
        node_info[k].append(v)
        node_info[v].append(k)

    for i in range(1, V+1):
        if isValid: # 1에서 시작해도 모든 노드 방문 -> 다른 시작점이 영향을 주나,,,?
            dfs(i)
        else:
            break

    if isValid:
        print("YES")
    else:
        print("NO")