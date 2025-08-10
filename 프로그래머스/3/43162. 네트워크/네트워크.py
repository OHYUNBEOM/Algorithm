def solution(n, computers):
    visited = [False] * n  # 1차원 visited 배열
    count = 0

    def dfs(node):
        visited[node] = True
        # node와 연결된 다른 컴퓨터(next_node)들을 탐색
        for next_node in range(n):
            # 1. node와 next_node가 연결되어 있고
            # 2. 아직 방문하지 않은 컴퓨터라면
            if computers[node][next_node] == 1 and not visited[next_node]:
                dfs(next_node)

    for i in range(n):
        # 아직 방문하지 않은 컴퓨터를 발견하면
        if not visited[i]:
            # 새로운 네트워크(컴포넌트)를 발견했으므로 count를 1 증가
            count += 1
            # 해당 컴퓨터부터 DFS 탐색 시작
            dfs(i)

    return count