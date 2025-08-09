import sys
sys.setrecursionlimit(10**6)

dy=[-1,0,1,0]
dx=[0,1,0,-1]

r,c=map(int,input().split())
a=[[0]*c for _ in range(r)]


for i in range(r):
    line=list(map(int,input().split()))
    for j in range(c):
        a[i][j]=line[j]

ret=0
last_cnt=0

def dfs(y,x):
    visited[y][x]=True
    for i in range(4):
        ny=y+dy[i]
        nx=x+dx[i]
        if ny<0 or ny>=r or nx<0 or nx>=c or visited[ny][nx]:
            continue
        if a[ny][nx]==0:
            dfs(ny,nx)
        elif a[ny][nx]==1:
            contact[ny][nx]=1


while True:
    visited = [[False] * c for _ in range(r)]
    contact = [[0] * c for _ in range(r)]
    cur_cnt=0
    dfs(0,0)
    flag=True
    for i in range(r):
        for j in range(c):
            if a[i][j]==1 and contact[i][j]==1:
                cur_cnt+=1
                a[i][j]=0
                flag=False

    if flag:
        break

    ret+=1
    last_cnt=cur_cnt

print(ret)
print(last_cnt)