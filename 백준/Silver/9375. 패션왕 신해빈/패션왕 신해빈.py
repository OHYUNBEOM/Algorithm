from collections import defaultdict
t=int(input().strip())
for _ in range(t):
    mp = defaultdict(int)
    n=int(input().strip())
    for i in range(n):
        a,b=input().split()
        mp[b]+=1

    result=1
    for i in mp:
        result *= (mp[i]+1)
    print(result-1)