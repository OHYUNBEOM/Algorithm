#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> prices) {
    int n=prices.size();
    vector<int> answer(n);
    stack<int> stk;
    for(int i=0;i<n;i++)
    {
        while(stk.size() && prices[i]<prices[stk.top()]) // 가격이 떨어진 경우
        {
            int idx=stk.top(); stk.pop();
            answer[idx] = i-idx;
        }
        stk.push(i);
    }
    while(stk.size())
    {
        int idx=stk.top();stk.pop();
        answer[idx]=n-1-idx;
    }
    return answer;
}