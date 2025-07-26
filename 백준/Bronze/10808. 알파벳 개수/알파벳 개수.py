a = [0]*26
s = input().strip()
for ch in s:
    index = ord(ch) - ord('a') # 'a' -> 0, 'b' -> 1...
    a[index]+=1
print(*a)