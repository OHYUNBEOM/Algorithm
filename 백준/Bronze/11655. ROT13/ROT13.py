s = input()
l = len(s)
result =[]
for i in range(l):
    if 'a' <= s[i] <= 'z':
        if ord(s[i])+13>122:
            result.append(chr(ord(s[i]) - 13))
        else:
            result.append(chr(ord(s[i]) + 13))
    elif 'A' <= s[i] <= 'Z':
        if ord(s[i])+13>90:
            result.append(chr(ord(s[i]) - 13))
        else:
            result.append(chr(ord(s[i]) + 13))
    else:
        result.append(s[i])
print(*result,sep='')