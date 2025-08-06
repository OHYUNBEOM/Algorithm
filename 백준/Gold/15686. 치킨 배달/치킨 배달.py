from itertools import combinations
dy=[-1,0,1,0]
dx=[0,1,0,-1]
n,m=map(int,input().split())
a=[[0]*n for _ in range(n)]
ch=[]
home=[]
for i in range(n):
    line=list(map(int,input().split()))
    for j in range(n):
        a[i][j]=line[j]
        if a[i][j]==2:
            ch.append((i,j)) # 치킨 집 좌표 저장
        elif a[i][j]==1:
            home.append((i,j))

ret=float('inf')

for chic in combinations(ch,m):
    sum=0
    for y1,x1 in home:
        dist=float('inf')
        for y2,x2 in chic:
            dist=min(dist,abs(y1-y2)+abs(x1-x2))
        sum+=dist
    ret=min(ret,sum)
print(ret)