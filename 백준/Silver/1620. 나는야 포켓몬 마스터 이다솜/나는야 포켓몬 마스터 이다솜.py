from collections import defaultdict
n,m=map(int,input().split())
a=[input().strip() for _ in range(n)]
b=[input().strip() for _ in range(m)]

mp_1=defaultdict(int)
mp_2=defaultdict(str)
l = len(a)

for i in range(l):
    mp_1[a[i]]=i+1
    mp_2[i+1]=a[i]

for i in b:
    if i.isdigit():
        print(mp_2[int(i)])
    else:
        print(mp_1[i])