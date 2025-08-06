import sys
sys.setrecursionlimit(10**6)
dy=[-1,0,1,0]
dx=[0,1,0,-1]
n,l,r=map(int,input().split())
ret=0
a=[[0]*n for _ in range(n)]
for i in range(n):
    line=list(map(int,input().split()))
    for j in range(n):
        a[i][j]=line[j]

def go(y,x):
    visited[y][x]=True
    united.append((y,x))
    for i in range(4):
        ny=y+dy[i]
        nx=x+dx[i]
        if ny<0 or ny>=n or nx<0 or nx>=n or visited[ny][nx]:
            continue
        if l <= abs(a[y][x]-a[ny][nx]) <= r:
            go(ny,nx)

while True:
    flag=True
    visited = [[False] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                united=[]
                go(i,j) # 연합 가능한지 확인
                if len(united)>1:
                    flag=False
                    total=avg=0

                    for y,x in united:
                        total+=a[y][x]

                    avg=total//len(united)

                    for y,x in united:
                        a[y][x]=avg

    if flag:
        break
    else:
        ret+=1

print(ret)