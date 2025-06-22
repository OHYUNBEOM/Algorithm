#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> A, vector<int> B)
{
    //Greedy, 곱의 합이 최소 : 가장 작은 수 x 가장 큰 수 꼴
    int answer=0;
    sort(A.begin(),A.end()); // A : 오름차순 정렬
    sort(B.rbegin(),B.rend()); // B : 내림차순 정렬
    for(int i=0;i<A.size();i++)
    {
        answer += A[i]*B[i]; // 같은 index끼리 곱함
    }
    return answer;
    // Greedy 최솟값 -> 오름차순 / 내림차순 구성, sum+=A[i]*B[i;
    // Greedy 최댓값 -> 오름차순 / 오름차순 or 내림차순 / 내림차순 구성, sum += A[i]*B[i];
}
