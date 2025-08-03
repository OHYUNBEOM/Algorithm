from collections import Counter
n,s=map(int,input().split())
nums=list(map(int,input().split()))
value = Counter(nums) # nums 리스트의 모든 숫자 순회, 각 숫자가 몇번 나왔는지 세고 dict 처럼 동작하는 Counter 객체가됨
for key,item in value.most_common(): # 빈도 내림차순으로 정렬된 value의 튜플을 기준으로 key,item을 뽑음
    for _ in range(item):
        print(key,end=' ')