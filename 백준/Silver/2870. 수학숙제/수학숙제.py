n=int(input().strip())
a=[input().strip() for _ in range(n)]
num=[]
for i in a:
    temp=''
    for j in i:
        if j.isdigit():
            temp+=j
        else:
            if temp!='':
                num.append(int(temp))
                temp=''
    if temp!='':
        num.append(int(temp))

for i in sorted(num):
    print(i)