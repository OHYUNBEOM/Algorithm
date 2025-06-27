#include<bits/stdc++.h>
using namespace std;
int solution(int n) {
    const int mod=1234567;
    int next=0;
    int a=0,b=1;
    for(int i=2;i<=n;i++)
    {
        next=(a+b)%mod;
        a=b;
        b=next;
    }
    return next;
}