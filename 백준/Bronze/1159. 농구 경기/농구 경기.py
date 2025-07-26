n=int(input())
p=[]
for _ in range(n):
    p.append(input().strip())

mp={}
for ch in p:
    init=ch[0]
    if init in mp:
        mp[init]+=1
    else:
        mp[init]=1

result=[]
for i in mp:
    if mp[i]>=5:
        result.append(i)

if result:
    print(''.join(sorted(result)))
else:
    print('PREDAJA')