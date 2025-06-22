#include<bits/stdc++.h>
using namespace std;
void dfs(int idx,int sum, vector<int>& numbers, int target, int& answer)
{
    if(idx==numbers.size())
    {
        if(sum==target) answer++;
        return;
    }
    dfs(idx+1,sum+numbers[idx],numbers,target,answer);
    dfs(idx+1,sum-numbers[idx],numbers,target,answer);
}
int solution(vector<int> numbers, int target) {
    int answer=0;
    dfs(0,0,numbers,target,answer); //idx,sum
    return answer;
}