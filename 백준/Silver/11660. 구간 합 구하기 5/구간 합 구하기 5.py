#백준 11660
import sys
input = sys.stdin.readline
n,m=map(int,input().split())#n=4,m-3 이면 4x4행렬/테케3개 입력한단 의미
arr=[]
for i in range(n):#4x4 행렬 만들기
    a=list(map(int,input().split()))
    arr.append(a)#ex.[[1, 2, 3, 4], [2, 3, 4, 5], [3, 4, 5, 6], [4, 5, 6, 7]] <- 테케1 4x4 배열

dp=[[0]*(n+1) for i in range(n+1)]
#n=4이면 dp=[[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
#[[0]*5 for i in range(5)]/[0]*5 = [0,0,0,0,0,] 이게 총 5개 만들어지는데 list안에 들어감
for i in range(1,n+1):#dp를 5x5로 선언해놓고 1행 1열은 안쓸거니까 애초에 인덱스 시작을 1부터 해주고 마지막값에도 +1 맞춰줌
    for j in range(1,n+1):
        dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+arr[i-1][j-1]#2차원배열 누적합 / 마지막 arr[i-1][j-1]은 arr을 4x4 배열로 받았고 dp에서는 5x5로 했으니까 좌표 위치 맞추려면 행,열 하나씩 줄여야함

for k in range(m):#테케 입력받기
    x1,y1,x2,y2=map(int,input().split())

    result=dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1] # 특정 좌표에서 특정 좌표까지!!
    print(result)