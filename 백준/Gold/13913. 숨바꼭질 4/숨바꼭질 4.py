from collections import deque
n,k=map(int,input().split())
dist=[-1]*100004 # 도달 시간
route=[-1]*100004 # 경로

dist[n]=0

q=deque()
q.append(n)

while q:
    start=q.popleft()
    for next in [start+1,start-1,start*2]:
        if next<0 or next>100000:
            continue
        if dist[next]==-1:
            dist[next]=dist[start]+1
            route[next]=start
            q.append(next)

print(dist[k])

path=[]
now=k
while now!=-1:
    path.append(now)
    now=route[now]
path.reverse()
print(*path)