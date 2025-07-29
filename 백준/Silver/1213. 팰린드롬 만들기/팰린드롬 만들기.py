from collections import defaultdict
line=input().strip()
mp=defaultdict(int)

cnt=0 # 홀수 카운팅
middle=''
first=''
second=''

for ch in line:
    mp[ch]+=1 # {'A' : 3, 'B' : 2}

for ch in sorted(mp.keys()):
    if mp[ch]%2==1:
        cnt+=1
        middle=ch
    for _ in range(mp[ch]//2):
        first+=ch

second=first[::-1]
if cnt>1:
    print("I'm Sorry Hansoo")
else:
    print(f"{first}{middle}{second}")