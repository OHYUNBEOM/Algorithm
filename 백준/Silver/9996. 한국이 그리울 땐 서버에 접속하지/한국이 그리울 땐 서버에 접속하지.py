n=int(input().strip())
s,e=input().strip().split("*")
for _ in range(n):
    ch=input().strip()
    if len(ch) >= len(s)+len(e) and ch.startswith(s) and ch.endswith(e):
        print('DA')
    else:
        print('NE')