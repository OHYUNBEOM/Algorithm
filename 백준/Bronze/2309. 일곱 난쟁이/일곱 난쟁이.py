from itertools import combinations
# n=[int(input()) for _ in range(9)]
n=[]
for _ in range(9):
    n.append(int(input()))

for comb in combinations(n,7):
    if sum(comb) == 100:
        for i in sorted(comb):
            print(i)
        break