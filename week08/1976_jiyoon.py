import sys
from collections import deque
input = sys.stdin.readline

N = int(input().strip())
M = int(input().strip())

conn = [[0] * N]
for _ in range(N):
    conn.append([0] + list(map(int, input().strip().split(' '))))
travel_plan = list(map(int, input().strip().split(' ')))


parents = [0] * (N+1) #부모 테이블 초기화
for i in range(1, N+1): #부모 노드 자기 자신으로 할당
    parents[i] = i


def find(a): #a 노드의 루트 노드 찾기
    if a == parents[a]:
        return a
    p = find(parents[a]) #a의 루트 노드 찾기
    parents[a] = p
    return parents[a]


def union(a,b):
    a = find(a)
    b = find(b)

    if a == b: # 같은 그룹일 때
        return
    elif a < b: # 더 작은 값이 루트로 갱신된다 -> 하나의 기준? 랭크?
        parents[b] = a
    else:
        parents[a] = b


for i in range(1, N+1):
    for s in range(1, N+1):
        if conn[i][s] == 1:
            union(i,s) # 두 노드가 연결 돼 있을 경우, 합친다(루트 노드를 동일하게 만든다)


result = set([find(i) for i in travel_plan]) #여행 계획 내 각 노드의 루트 노드를 구한다
if len(result) != 1: # set이므로 중복 노드 없음 -> 길이 1일 경우, 계획 노드는 모두 이어져있다고 판단 가능
    print("NO")
else:
    print("YES")