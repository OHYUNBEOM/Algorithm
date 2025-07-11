#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n=prices.size();
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=i+1;j<n;j++)
        {
            cnt++;
            if(prices[j]<prices[i]) break;
        }
        answer.push_back(cnt);
    }
    return answer;
}