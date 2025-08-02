n,k=map(int,input().split())
nums=list(map(int,input().split()))

cur_sum=0
for i in range(k):
    cur_sum+=nums[i]
max_sum=cur_sum

for i in range(k,n):
    cur_sum=cur_sum-nums[i-k]+nums[i] # nums[i-k] : 빠지는 가장 왼쪽 숫자, nums[i] : 새롭게 오른쪽에 들어오는 숫자
    max_sum=max(max_sum,cur_sum)

print(max_sum)