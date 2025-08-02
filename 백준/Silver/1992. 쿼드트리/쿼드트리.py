def dfs(y,x,size):
    val=a[y][x]
    for i in range(y,y+size):
        for j in range(x,x+size):
            if val!=a[i][j]:
                half=size//2
                print('(',end='')
                dfs(y,x,half)
                dfs(y,x+half,half)
                dfs(y+half,x,half)
                dfs(y+half,x+half,half)
                print(')',end='')
                return
    print(val,end='')

n=int(input().strip())
a=[[0]*n for _ in range(n)]
for i in range(n):
    line=input().strip()
    for j in range(n):
        a[i][j]=int(line[j])

dfs(0,0,n) #y,x,size