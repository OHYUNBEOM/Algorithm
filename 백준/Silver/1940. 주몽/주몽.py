n=int(input().strip())
m=int(input().strip())
num=list(map(int,input().split()))
num.sort()

left=0
right=n-1
cnt=0

while left<right:
    s=num[left] + num[right]
    if s==m:
        left+=1
        right-=1
        cnt+=1
    elif s<m:
        left+=1
    else:
        right-=1
        
print(cnt)