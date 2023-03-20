import sys
input = sys.stdin

dx = [1,0,-1,0]
dy = [0,-1,0,1]

def getCurve(sx,sy,directions,gen):
    if gen == g:
        return

    leng = len(directions)
    newDir = [(directions[i]+1)%4 for i in range(len(directions)-1,-1,-1)]
    directions += newDir

    x,y = sx,sy
    for dir in directions[leng:]:
        x,y = x+dx[dir], y+dy[dir]
        cordinates.add((x,y))

    getCurve(x,y,directions,gen+1)

def findSquare(xx,yy):
    for i in range(3):
        xx,yy = xx+dx[i],yy+dy[i]
        if not (0<=x<=100 and 0<h¤Ë=y<=100):
            return False
        if (xx,yy) not in cordinates:
            return False
    return True


N = int(input.readline())

curves = []
cordinates = set()
answer = 0

for _ in range(N):
    x,y,d,g = map(int,input.readline().split())
    cordinates.add((x,y))
    cordinates.add((x+dx[d],y+dy[d]))
    getCurve(x+dx[d],y+dy[d],[d],0)

cors = list(cordinates)
for cor in cors:
    if not (0<=x<=100 and 0<=y<=100):
        continue
    if findSquare(cor[0],cor[1]):
        answer += 1

print(answer)
