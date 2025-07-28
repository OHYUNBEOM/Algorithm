n,m = map(int,input().split())
j=int(input().strip())

left=1
right=m
cnt=0

for _ in range(j):
    a = int(input().strip())
    pos=0
    if a>right:
        pos=a-right
        right+=pos
        left+=pos
        cnt+=pos
    elif a<left:
        pos=left-a
        right-=pos
        left-=pos
        cnt+=pos
    else:
        continue

print(cnt)