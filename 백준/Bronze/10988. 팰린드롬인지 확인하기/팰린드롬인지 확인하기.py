mystr=str(input())
mylist=list(mystr)

if mylist==mylist[::-1]:
    print('1')
else:
    print('0')