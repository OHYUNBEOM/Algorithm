from collections import deque
from itertools import combinations
import copy
import sys
input=sys.stdin.readline
dy=[-1,0,1,0]
dx=[0,1,0,-1]

n,m=map(int,input().split())
wall=[]
virus=[]
a=[[0]*n for _ in range(n)]
empty_cnt = 0   # ★ 0과 2(=변환 후 0) 모두 카운트

for i in range(n):
    line=list(map(int,input().split()))
    for j in range(n):
        val = line[j]
        if val == 1:
            a[i][j] = 1
            wall.append((i,j))
        elif val == 2:
            virus.append((i,j))
            a[i][j] = 0       # ★ 2를 빈 칸으로 바꿔 둔다
            empty_cnt += 1     # ★ 빈 칸 카운트에 포함
        else:  # val == 0
            a[i][j] = 0
            empty_cnt += 1

# 애초에 빈 칸(0+2)이 없으면 0
if empty_cnt == 0:
    print(0)
    sys.exit(0)

ret=float('inf')

for v in combinations(virus, m):
    # a는 이미 2->0으로 변환되어 있으니 복사 유지해도 무방(최소 수정 원칙)
    a_copy=copy.deepcopy(a)
    visited = [[-1] * n for _ in range(n)]
    q=deque()

    for y,x in v:
        q.append((y,x))
        visited[y][x]=0

    while q:
        sy,sx=q.popleft()
        for i in range(4):
            ny=sy+dy[i]
            nx=sx+dx[i]
            if ny<0 or ny>=n or nx<0 or nx>=n: 
                continue
            if visited[ny][nx]!=-1 or a_copy[ny][nx]==1: 
                continue
            visited[ny][nx]=visited[sy][sx]+1
            q.append((ny,nx))

    # ★ 모든 빈 칸(0, 원래의 2 포함)이 감염됐는지와 최대 시간 계산
    filled = 0
    max_time = 0
    for i in range(n):
        for j in range(n):
            if a[i][j] == 0:                  # 변환 후 0 == 원래 0 또는 2
                if visited[i][j] != -1:
                    filled += 1
                    if visited[i][j] > max_time:
                        max_time = visited[i][j]

    if filled == empty_cnt:
        ret = min(ret, max_time)

print(-1 if ret==float('inf') else ret)
