#import sys
#sys.setrecursionlimit(10000)
dy=[-1,0,1,0]
dx=[0,1,0,-1]
ret=0
def dfs(y,x,cnt):
    global ret
    if cnt==k:
        if y==0 and x==c-1:
            ret+=1
        return

    for i in range(4):
        ny = y+dy[i]
        nx = x+dx[i]
        if ny<0 or ny>=r or nx<0 or nx>=c or visited[ny][nx] or a[ny][nx]=='T':
            continue
        if not visited[ny][nx] and a[ny][nx]=='.':
            visited[ny][nx]=True
            dfs(ny, nx, cnt + 1)
            visited[ny][nx]=False


r,c,k = map(int,input().split())

a=[['']*c for _ in range(r)]
visited=[[0]*c for _ in range(r)]

for i in range(r):
    line=input().strip()
    for j in range(c):
        a[i][j]=line[j]

visited[r-1][0]=True
dfs(r-1,0,1)
print(ret)