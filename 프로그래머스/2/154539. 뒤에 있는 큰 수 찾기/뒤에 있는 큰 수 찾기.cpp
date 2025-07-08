#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    stack<int> stk;
    vector<int> answer(n,-1);
    for(int i=0;i<n;i++)
    {
        while(stk.size() && numbers[i]>numbers[stk.top()])
        {
            answer[stk.top()]=numbers[i];
            stk.pop();
        }
        stk.push(i);
    }
    return answer;
}