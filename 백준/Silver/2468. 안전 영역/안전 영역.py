from collections import deque
import copy
import sys
sys.setrecursionlimit(10**6)
dy=[-1,0,1,0]
dx=[0,1,0,-1]
ret=-float('inf')

def dfs(y, x):
    visited[y][x]=True
    for i in range(4):
        ny=y+dy[i]
        nx=x+dx[i]
        if ny<0 or ny>=n or nx<0 or nx>=n:
            continue
        if not visited[ny][nx] and a_copy[ny][nx]==1:
            dfs(ny,nx)
    return

n=int(input().strip())
a=[[0]*n for _ in range(n)]

for i in range(n):
    temp=list(map(int,input().split()))
    for j in range(n):
        a[i][j]=temp[j]

max_h=max(map(max,a))

for h in range(max_h+1):
    a_copy=copy.deepcopy(a)
    visited = [[False] * n for _ in range(n)]
    cnt=0

    for i in range(n):
        for j in range(n):
            if a_copy[i][j]<=h:
                a_copy[i][j]=0
            else:
                a_copy[i][j]=1

    for i in range(n):
        for j in range(n):
            if a_copy[i][j]==1 and not visited[i][j]:
                cnt+=1
                dfs(i,j)

    ret=max(ret,cnt)
print(ret)