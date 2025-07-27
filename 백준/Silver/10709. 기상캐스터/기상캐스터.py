h,w=map(int,input().split())

a=[input().strip() for _ in range(h)]
result=[[-1]*w for _ in range(h)]

for i in range(h):
    cloud=-1
    for j in range(w):
        if a[i][j]=='c':
            cloud = j
            result[i][j]=0
        elif a[i][j]=='.':
            if cloud!=-1:
                result[i][j]=j-cloud
            else:
                result[i][j]=-1

for i in result:
    print(*i)