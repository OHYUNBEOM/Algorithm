from collections import deque

dy=[-1,0,1,0]
dx=[0,1,0,-1]
r,c=map(int,input().split())
a=[['']*c for _ in range(r)]
fire_visited=[[0]*c for _ in range(r)]
man_visited=[[0]*c for _ in range(r)]

fire=deque()
man=deque()

for i in range(r):
    line=input().strip()
    for j in range(c):
        a[i][j]=line[j]
        if a[i][j]=='J':
            man_visited[i][j]=1
            man.append((i,j))
            a[i][j]='.'
        elif a[i][j]=='F':
            fire_visited[i][j]=1
            fire.append((i,j))
            a[i][j]='.'

def bfs_fire():
    while fire:
        y,x=fire.popleft()
        for i in range(4):
            ny=y+dy[i]
            nx=x+dx[i]
            if ny<0 or ny>=r or nx<0 or nx>=c or fire_visited[ny][nx] or a[ny][nx]=='#':
                continue
            fire_visited[ny][nx]=fire_visited[y][x]+1
            fire.append((ny,nx))

def bfs_man():
    while man:
        y,x=man.popleft()
        for i in range(4):
            ny=y+dy[i]
            nx=x+dx[i]
            if ny<0 or ny>=r or nx<0 or nx>=c:
                print(man_visited[y][x])
                return
            if man_visited[ny][nx] or a[ny][nx]=='#':
                continue
            if fire_visited[ny][nx]!=0 and fire_visited[ny][nx]<=man_visited[y][x]+1:
                continue
            man_visited[ny][nx]=man_visited[y][x]+1
            man.append((ny,nx))
    print("IMPOSSIBLE")


bfs_fire()
bfs_man()