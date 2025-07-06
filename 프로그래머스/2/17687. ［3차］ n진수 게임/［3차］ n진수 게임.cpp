#include<bits/stdc++.h>
using namespace std;
string convert(int n,int k) // 진법 변환, 16진수까지 cover
{
    string digits="0123456789ABCDEF";
    string result="";
    if(n==0) return "0";
    while(n>0)
    {
        result = digits[n%k] + result;
        n/=k;
    }
    return result;
}
string solution(int n, int t, int m, int p) {
    string total=""; 
    for(int i=0;total.length()<t*m;i++)
    {
        total+=convert(i,n); // 참가 인원에 맞춰서 미리 전체를 구해둠
    }
    string answer="";
    for(int i=0;answer.length()<t;i++)
    {
        if((i%m)+1==p)
        {
            answer += total[i];
        }
    }
    return answer;
}