n=int(input().strip())
for _ in range(n):
    line = input().strip()
    stack=[]
    for ch in line:
        if stack:
            if stack[-1] == '(' and ch==')':
                stack.pop()
            else:
                stack.append(ch)
        else:
            stack.append(ch)
    if not stack:
        print('YES')
    else:
        print('NO')