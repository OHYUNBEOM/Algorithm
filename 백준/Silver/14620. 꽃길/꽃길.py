dy=[-1,0,1,0]
dx=[0,1,0,-1]
ret=float('inf')
def canPlace(y,x):
    if visited[y][x]: #이미 방문한 정점이면 False
        return False
    for i in range(4):
        ny=y+dy[i]
        nx=x+dx[i]
        if ny<0 or ny>=n or nx<0 or nx>=n or visited[ny][nx]: # 범위에서 벗어나면 False
            return False
    return True

def plantFlower(y,x):
    visited[y][x]=True
    c=a[y][x]
    for i in range(4):
        ny=y+dy[i]
        nx=x+dx[i]
        visited[ny][nx]=True
        c+=a[ny][nx]
    return c

def removeFlower(y,x):
    visited[y][x]=False
    for i in range(4):
        ny=y+dy[i]
        nx=x+dx[i]
        visited[ny][nx]=False

def dfs(cnt,sum):
    global ret
    if cnt==3:
        ret=min(ret,sum)
        return

    for i in range(1,n):
        for j in range(1,n):
            if(canPlace(i,j)):
                cost=plantFlower(i,j)
                dfs(cnt+1,sum+cost)
                removeFlower(i,j)

n=int(input().strip())
a=[[0] * n for _ in range(n)]
visited=[[False] * n for _ in range(n)]

for i in range(n):
    num=list(map(int,input().split()))
    for j in range(n):
        a[i][j]=num[j]

dfs(0,0) # cnt,sum
print(ret)