#include<bits/stdc++.h>
using namespace std;
int solution(int n) {
    int answer = 0;
    int start=1;
    while(start<=n)
    {
        int sum=0;
        int temp=start;
        while(sum<n)
        {
            sum+=temp++;
            if(sum==n) answer++;
        }
        start++;
    }
    return answer;
}