from itertools import combinations
import copy

dy=[-1,0,1,0]
dx=[0,1,0,-1]

ret=0
safe=[]

n,m=map(int,input().split())
a=[[0]*m for _ in range(n)]
for i in range(n):
    line=list(map(int,input().split()))
    for j in range(m):
        a[i][j]=line[j]
        if a[i][j]==0:
            safe.append((i,j))

def dfs(y,x):
    visited[y][x]=True
    for i in range(4):
        ny=y+dy[i]
        nx=x+dx[i]
        if ny<0 or ny>=n or nx<0 or nx>=m or visited[ny][nx] or a_copy[ny][nx]==1:
            continue
        if a_copy[ny][nx]==0:
            visited[ny][nx]=True
            a_copy[ny][nx]=2
            dfs(ny,nx)


for wall in combinations(safe,3): # 안전 영역 중 3곳을 고름
    a_copy=copy.deepcopy(a) # 조합 별 확인을 위해 원본 a는 보존, a_copy 사용
    visited=[[False]*m for _ in range(n)]
    cnt=0
    
    for y,x in wall: # 벽 세우기
        a_copy[y][x]=1

    for i in range(n):
        for j in range(m):
            if a_copy[i][j]==2 and not visited[i][j]:
                dfs(i,j)

    for i in range(n):
        for j in range(m):
            if a_copy[i][j]==0:
                cnt+=1

    ret=max(ret,cnt)

print(ret)