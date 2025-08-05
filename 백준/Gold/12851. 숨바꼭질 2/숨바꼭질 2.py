from collections import deque
n,k=map(int,input().split())
dist=[-1]*100004 # 도달 시간
cnt=[0]*100004 # 도달 방법

dist[n]=0
cnt[n]=1

q=deque()
q.append(n)

while q:
    start=q.popleft()
    for next in [start+1,start-1,start*2]:
        if next<0 or next>100000:
            continue
        if dist[next]==-1:
            dist[next]=dist[start]+1
            cnt[next]=cnt[start]
            q.append(next)
        elif dist[next]==dist[start]+1:
            cnt[next]+=cnt[start]

print(dist[k])
print(cnt[k])