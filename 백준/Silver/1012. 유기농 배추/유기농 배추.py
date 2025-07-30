import sys
sys.setrecursionlimit(10000)

dy=[-1,0,1,0]
dx=[0,1,0,-1]

def dfs(y, x):
    visited[y][x]=1
    for i in range(4):
        ny = y+dy[i]
        nx = x+dx[i]
        if ny<0 or ny>=n or nx<0 or nx>=m or visited[ny][nx] or a[ny][nx]==0:
            continue
        if not visited[ny][nx] and a[ny][nx]==1:
            dfs(ny,nx)

t=int(input().strip())

for _ in range(t):
    ret=0
    n, m, k = map(int, input().split())
    a = [[0] * m for _ in range(n)]
    visited = [[0] * m for _ in range(n)]

    for _ in range(k):
        y,x=map(int,input().split())
        a[y][x]=1

    for i in range(n):
        for j in range(m):
            if not visited[i][j] and a[i][j]==1:
                ret+=1
                dfs(i,j)

    print(ret)