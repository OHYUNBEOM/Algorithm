# two pointer
n=int(input().strip())
m=int(input().strip())
a=list(map(int,input().split()))

a.sort()

left=0
right=n-1
cnt=0

while left<right: # left==right인 경우 서로 다른 두 수 위배, left가 right 넘어가면 이미 모든 경우 다 확인한경우
    s = a[left] + a[right] # 배열의 첫번째 원소 + 마지막 원소
    if s==m: # 조건을 만족
        cnt+=1 # 카운팅
        right-=1 # 오른쪽 범위 하나 줄임
        left+=1 # 왼쪽 범위 하나 줄임
    elif s<m:
        left+=1
    else:
        right-=1

print(cnt)