#include<bits/stdc++.h>
using namespace std;

int solution(int n)
{
    int cnt=0;
    while(n>0)
    {
        if(n%2==0) n/=2; // 순간이동이 가능하다면 최대한 나눠줌
        else // 최대한 나눈 이후 점프하면서 점프 거리 카운팅
        {
            n-=1;
            cnt++;
        }
    }
    return cnt;
}