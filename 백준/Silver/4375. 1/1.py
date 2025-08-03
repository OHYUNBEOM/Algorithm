while True:
    try:
        n=int(input().strip())
        cnt=ret=1
        while True:
            if ret%n==0:
                print(cnt)
                break
            else:
                ret=(ret*10+1)%n
                cnt+=1
    except EOFError:
        break