import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**6)

dy=[-1,0,1,0]
dx=[0,1,0,-1]

n,m=map(int,input().split())
a=[[0]*m for _ in range(n)]

for i in range(n):
    line=list(map(int,input().split()))
    for j in range(m):
        a[i][j]=line[j]

def dfs(y,x):
    visited[y][x]=True
    for i in range(4):
        ny=y+dy[i]
        nx=x+dx[i]
        if ny<0 or ny>=n or nx<0 or nx>=m or visited[ny][nx]:
            continue
        if a[ny][nx]==0:
            dfs(ny,nx)
        elif a[ny][nx]==1:
            contact[ny][nx]+=1
ret=0

while True:
    visited = [[False] * m for _ in range(n)]
    contact = [[0] * m for _ in range(n)]
    flag=True
    ret+=1

    dfs(0,0)

    for i in range(n):
        for j in range(m):
            if a[i][j]==1 and contact[i][j]>=2:
                a[i][j]=0

    for i in range(n):
        for j in range(m):
            if a[i][j]!=0:
                flag=False

    if flag:
        break

print(ret)