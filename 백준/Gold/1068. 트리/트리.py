n=int(input().strip())
nodes=list(map(int,input().split()))
remove_node=int(input().strip())

tree=[[] for _ in range(n)]
root=-1
for i in range(n):
    if nodes[i]==-1:
        root=i
    else:
        tree[nodes[i]].append(i) # 각 노드의 자식 노드 번호 기록
        
def dfs(here):
    ret=child=0
    for there in tree[here]:
        if there==remove_node:
            continue
        ret+=dfs(there)
        child+=1

    if child==0:
        ret=1

    return ret

if remove_node==root:
    print(0)
else:
    print(dfs(root))