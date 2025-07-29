while True:
    line = input()
    if line == '.':
        break
    stack=[]
    for ch in line:
        if ch in ['(', '[']:
            stack.append(ch)
        elif ch==')':
            if stack and stack[-1]=='(':
                stack.pop()
            else:
                stack.append(ch)
        elif ch==']':
            if stack and stack[-1]=='[':
                stack.pop()
            else:
                stack.append(ch)
            
    if not stack:
        print('yes')
    else:
        print('no')