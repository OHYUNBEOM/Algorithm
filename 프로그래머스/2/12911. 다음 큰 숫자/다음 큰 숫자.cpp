#include<bits/stdc++.h>
using namespace std;
int change(int num)
{
    string result="";
    while(num>0)
    {
        result = to_string(num%2)+result;
        num=num/2;
    }
    int count=0;
    for(int i=0;i<result.size();i++)
    {
        if(result[i]=='1') count++;
    }
    return count;
}
int solution(int n) {
    int count_n = change(n); // n -> 2진수로 변환, 1의 갯수 저장
    int temp=n+1; // n+1부터 검사
    while(true)
    {
        if(change(temp)==count_n) return temp;
        else temp++;
    }
}