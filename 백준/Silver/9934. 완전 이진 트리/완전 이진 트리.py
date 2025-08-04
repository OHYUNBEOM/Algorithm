def dfs(start,end,depth):
    if start>end:
        return
    mid=(start+end)//2
    level[depth].append(nodes[mid])
    dfs(start,mid-1,depth+1)
    dfs(mid+1,end,depth+1)


k=int(input().strip())
n=2**k-1
nodes=list(map(int,input().split()))

level=[[] for _ in range(k)] # 각 레벨 별 node 저장용

dfs(0,n-1,0) #start,end,level / Node 기반으로 탐색

for i in level:
    print(*i)