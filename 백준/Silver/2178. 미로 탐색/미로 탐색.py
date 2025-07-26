from collections import deque
dy=[-1,0,1,0]
dx=[0,1,0,-1]

n,m=map(int,input().split())
a = [list(map(int, input().strip())) for _ in range(n)]
visited=[[0]*m for _ in range(n)]

def bfs(sy,sx):
    visited[sy][sx]=1
    q=deque()
    q.append((sy,sx))
    while q:
        y,x=q.popleft()
        for i in range(4):
            ny=y+dy[i]
            nx=x+dx[i]
            if ny<0 or ny>=n or nx<0 or nx>=m or visited[ny][nx] or a[ny][nx]==0 :
                continue
            visited[ny][nx] = visited[y][x]+1
            q.append((ny,nx))

bfs(0,0)
print(visited[n-1][m-1])