n=int(input().strip())
nums=list(map(int,input().split()))
nums.sort()
ret=0

for i in range(n):
    left=0
    right=n-1

    while left<right:
        if left==i:
            left+=1
            continue
        if right==i:
            right-=1
            continue

        sum_val=nums[left]+nums[right]

        if sum_val==nums[i]:
            ret+=1
            break
        elif sum_val<nums[i]:
            left+=1
        else:
            right-=1

print(ret)