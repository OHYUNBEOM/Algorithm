from collections import defaultdict
a,b,c=map(int,input().split())
mp=defaultdict(int)
for _ in range(3):
    s,f=map(int,input().split())
    for i in range(s,f):
        mp[i]+=1

total=0
for i in mp:
    if mp[i]==1:
        total+=a*1
    elif mp[i]==2:
        total+=b*2
    elif mp[i]==3:
        total+=c*3

print(total)