mx="0"
mn="9999999999"

def oper(ch,a,b):
    if ch=='<':
        return a<b
    elif ch=='>':
        return a>b

def dfs(idx,num):
    global mx,mn
    if idx==k+1:
        if mx<num:
            mx=num
        if mn>num:
            mn=num
        return

    for i in range(10):
        if visited[i]:
            continue
        if idx>=1 and not oper(op[idx-1],int(num[idx-1]),i):
            continue
        visited[i]=True
        dfs(idx+1,num+str(i))
        visited[i]=False

k=int(input().strip())
op=list(input().split())
visited=[False]*10
dfs(0,"") # index, num(str)
print(mx)
print(mn)