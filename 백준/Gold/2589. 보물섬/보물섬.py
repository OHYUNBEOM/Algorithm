from collections import deque
import sys
input=sys.stdin.readline

dy=[-1,0,1,0]
dx=[0,1,0,-1]
r,c=map(int,input().split())
a=[['']*c for _ in range(r)]
#visited=[[0]*c for _ in range(r)]
for i in range(r):
    line=input().strip()
    for j in range(c):
        a[i][j]=line[j]

ret=-float('inf')

def bfs(y,x):
    global ret
    visited[y][x]=1
    q=deque()
    q.append((y,x))
    while q:
        sy,sx=q.popleft()
        for i in range(4):
            ny=sy+dy[i]
            nx=sx+dx[i]
            if ny<0 or ny>=r or nx<0 or nx>=c or visited[ny][nx] or a[ny][nx]=='W':
                continue
            if not visited[ny][nx] and a[ny][nx]=='L':
                visited[ny][nx]=visited[sy][sx]+1
                ret=max(ret,visited[ny][nx]-1)
                q.append((ny,nx))

for i in range(r):
    for j in range(c):
        if a[i][j]=='L':
            visited=[[0]*c for _ in range(r)]
            bfs(i,j)

print(ret)