from collections import deque
dy=[-1,0,1,0]
dx=[0,1,0,-1]

def bfs(y,x):
    visited[y][x]=True
    cur=deque()
    nxt=deque()
    cur.append((y,x))
    ret=0
    while True:
        if visited[x2-1][y2-1]:
            print(ret)
            return

        while cur:
            sy,sx=cur.popleft()
            for i in range(4):
                ny=sy+dy[i]
                nx=sx+dx[i]
                if ny<0 or ny>=n or nx<0 or nx>=m or visited[ny][nx]:
                    continue
                if a[ny][nx] in ('0','#'):
                    visited[ny][nx]=True
                    cur.append((ny,nx))
                elif a[ny][nx]=='1':
                    visited[ny][nx]=True
                    nxt.append((ny,nx))

        while nxt:
            sy,sx=nxt.popleft()
            a[sy][sx]='0'
            cur.append((sy,sx))

        ret+=1


n,m=map(int,input().split())
x1,y1,x2,y2=map(int,input().split())

a=[[0]*m for _ in range(n)]
visited=[[False]*m for _ in range(n)]

for i in range(n):
    line=input().strip()
    for j in range(m):
        a[i][j]=line[j]

bfs(x1-1,y1-1)