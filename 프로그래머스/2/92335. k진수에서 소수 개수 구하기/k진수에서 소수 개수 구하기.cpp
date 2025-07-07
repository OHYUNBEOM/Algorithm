#include<bits/stdc++.h>
using namespace std;
bool isPrime(long long n)
{
    if(n<2) return false;
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
string convert(int n,int k)
{
    string result="";
    while(n>0)
    {
        result = to_string(n%k) + result;
        n/=k;
    }
    return result;
}
int solution(int n, int k) {
    string conv=convert(n,k);
    int cnt=0;
    string temp="";
    for(int i=0;i<conv.size();i++)
    {
        if(conv[i]=='0')
        {
            if(temp.size()&&isPrime(stoll(temp))) cnt++;
            temp="";
        }
        else
        {
            temp+=conv[i];    
        }
    }
    if(temp.size())
    {
        if(isPrime(stoll(temp))) cnt++;
    }
    return cnt;
}