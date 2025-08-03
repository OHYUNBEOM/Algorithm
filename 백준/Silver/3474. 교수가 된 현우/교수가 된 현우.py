import sys
input=sys.stdin.readline
t=int(input().strip())
for _ in range(t):
    n=int(input().strip())
    cnt=0
    while n>=5:
        n//=5
        cnt+=n
    print(cnt)