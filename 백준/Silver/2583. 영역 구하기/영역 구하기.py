import sys
sys.setrecursionlimit(10**6)
dy=[-1,0,1,0]
dx=[0,1,0,-1]

m,n,k=map(int,input().split())
a=[[1]*n for _ in range(m)]
visited=[[False]*n for _ in range(m)]
cnt=0
sizes=[]

def dfs(y,x):
    global ret
    visited[y][x]=True
    ret+=1
    for i in range(4):
        ny=y+dy[i]
        nx=x+dx[i]
        if ny<0 or ny>=m or nx<0 or nx>=n or visited[ny][nx] or a[ny][nx]==0:
            continue
        dfs(ny,nx)

for _ in range(k):
    x1,y1,x2,y2=map(int,input().split())
    for i in range(y1,y2):
        for j in range(x1,x2):
            a[i][j]=0

for i in range(m):
    for j in range(n):
        if a[i][j]==1 and not visited[i][j]:
            ret=0
            cnt+=1
            dfs(i,j)
            sizes.append(ret)

print(cnt)
print(*sorted(sizes),end=' ')