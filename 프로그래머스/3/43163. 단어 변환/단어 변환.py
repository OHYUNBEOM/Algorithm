def solution(begin, target, words):
    if target not in words:
        return 0

    n = len(words)
    visited = [False] * n
    ret = [10**9]  # INT_MAX 대체

    def convert(a, b):
        count = 0
        for i in range(len(a)):
            if a[i] != b[i]:
                count += 1
                if count > 1:
                    return False
        return True  # (<=1 글자 차이면 True) C++ 로직 그대로

    def dfs(cur, cnt):
        if cur == target:
            if cnt < ret[0]:
                ret[0] = cnt
            return
        for i in range(n):
            if not visited[i] and convert(cur, words[i]):
                visited[i] = True
                dfs(words[i], cnt + 1)
                visited[i] = False

    dfs(begin, 0)
    return 0 if ret[0] == 10**9 else ret[0]
