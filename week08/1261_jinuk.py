import sys
from collections import deque

N,M=map(int,sys.stdin.readline().rstrip().split())

graph = [list(map(int,sys.stdin.readline().rstrip())) for _ in range(M)]

visited =[[False]*N for _ in range(M)]

dy=[1,-1,0,0]
dx=[0,0,1,-1]

def scope(y,x):
    if y>=0 and y<M and x>=0 and x<N:
        return True
    else:
        return False
    
def sol():
    q=deque()
    q.append([0,0])
    visited[0][0]=True
    
    while q:
        fy,fx=q.popleft()
        if fy==M-1 and fx ==N-1:
            print(graph[fy][fx])
            break

        for i in range(4):
            my=fy+dy[i]
            mx=fx+dx[i]

            if scope(my,mx):
                if not visited[my][mx] and graph[my][mx]==0:
                    visited[my][mx]=True
                    graph[my][mx]=graph[fy][fx]
                    q.appendleft([my,mx])

                elif not visited[my][mx] and graph[my][mx]!=0:
                    visited[my][mx]=True
                    graph[my][mx]=graph[fy][fx]+1
                    q.append([my,mx])
sol()
