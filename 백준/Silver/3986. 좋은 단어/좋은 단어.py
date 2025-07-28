n=int(input().strip())
words=[input().strip() for _ in range(n)]
cnt=0

for line in words:
    stack=[]
    for ch in line:
        if stack and stack[-1] == ch:
            stack.pop()
        else:
            stack.append(ch)
    if not stack:
        cnt+=1

print(cnt)