#include<bits/stdc++.h>
using namespace std;
vector<int> global_numbers;
int global_target,global_answer;
void dfs(int idx,int sum)
{
    if(idx==global_numbers.size()) // 마지막 숫자까지 탐색
    {
        if(sum==global_target)
        {
            global_answer++;
        }
        return;
    }
    dfs(idx+1,sum+global_numbers[idx]);
    dfs(idx+1,sum-global_numbers[idx]);
}
int solution(vector<int> numbers, int target) {
    global_numbers=numbers;
    global_target=target;
    global_answer=0;
    dfs(0,0);
    return global_answer;
}