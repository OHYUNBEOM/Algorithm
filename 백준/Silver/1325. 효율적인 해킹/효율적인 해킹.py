import sys
from collections import deque

input = sys.stdin.readline


def bfs(start_node):
    queue = deque([start_node])
    visited = set()
    visited.add(start_node)
    count = 1

    while queue:
        node = queue.popleft()
        for n in graph[node]:
            if n not in visited:
                visited.add(n)
                queue.append(n)
                count += 1
    return count


N, M = map(int, input().split())

graph = [[] for _ in range(N + 1)]

for _ in range(M):
    s, e = map(int, input().split())
    graph[e].append(s)

answer = [0] * (N + 1)

for i in range(1, N + 1):
    answer[i] = bfs(i)

max_cnt = max(answer)

for i in range(1,N+1):
    if answer[i] == max_cnt:
        print(i, end=" ")