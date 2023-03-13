import sys
import queue
input = sys.stdin.readline

N, M = tuple(map(int, input().strip().split(' ')))

lab = []
for _ in range(N):
    row = list(map(int, input().strip().split(' ')))
    lab.append(row)


dir = [(1,0), (-1,0), (0,1), (0,-1)]
def infect():

    q = queue()
    visit = set()

    for i in range(N):
        for s in range(M):
            if lab[i][s] == 2:
                
                for d in dir:
                    x, y = d
                    if i+y < N and s+x < M and lab[i][s] == 0:
                        lab[i][s] = 2
                

def check():
    num = 0
    for i in range(N):
        for s in range(M):
            if lab[i][s] == 0:
                num += 1

    return num


def make_wall(count):
    if count == 3:
        infect()
        global score
        score = max(score, check())
        return
    for i in range(N):
        for k in range(M):
            if lab[i][k] == 0:
                lab[i][k] = 1
                make_wall(count+1)
                lab[i][k] = 0

score = 0
make_wall(0)
print(score)