n=int(input())
p=[input().strip() for _ in range(n)]

mp={}
for ch in p:
    init = ch[0]
    if init in mp:
        mp[init]+=1
    else:
        mp[init]=1

result=[]
for i in mp:
    if mp[i]>=5:
        result.append(i)

if result:
    # print(''.join(sorted(result)))
    for ch in sorted(result):
        print(ch,end='')
else:
    print('PREDAJA')