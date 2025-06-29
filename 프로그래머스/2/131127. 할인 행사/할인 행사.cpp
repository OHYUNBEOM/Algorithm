#include<bits/stdc++.h>
using namespace std;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer=0;
    map<string,int> want_map;
    for(int i=0;i<want.size();i++)
    {
        want_map[want[i]]=number[i]; // 구매하는 제품,갯수를 map에 저장
    }
    for(int i=0;i<=discount.size()-10;i++) //10일동안의 구간 
    {
        map<string,int> discount_map;
        for(int j=i;j<i+10;j++)
        {
            discount_map[discount[j]]++; // 10일간 판매하는 제품, 갯수를 map에 저장
        }
        bool flag=true;
        for(auto it : want_map)
        {
            // 판매하는 제품보다 구매하려는 제품이 많으면
            if(discount_map[it.first]<it.second) 
            {
                flag=false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}