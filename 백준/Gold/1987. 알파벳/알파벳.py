import sys
input = sys.stdin.readline

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
r, c = map(int, input().split())

a = [list(input().strip()) for _ in range(r)]
visited = [False] * 26
ret = 1

def go(y, x, count):
    global ret
    ret = max(ret, count)

    idx = ord(a[y][x]) - 65
    visited[idx] = True

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < r and 0 <= nx < c:
            next_idx = ord(a[ny][nx]) - 65
            if not visited[next_idx]:
                go(ny, nx, count + 1)

    visited[idx] = False


go(0, 0, 1)
print(ret)