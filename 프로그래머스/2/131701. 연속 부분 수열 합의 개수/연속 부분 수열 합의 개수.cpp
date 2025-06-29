#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> elements) {
    int len=elements.size();
    vector<int> circle=elements;
    // 원형수열 계산을 위해 하나 더 이어붙임
    circle.insert(circle.end(),elements.begin(),elements.end());
    set<int> ret;
    for(int i=1;i<=len;i++) // 가능한 부분 수열 합 범위
    {
        for(int j=0;j<len;j++) // 수열 합 구할 start 위치
        {
            int sum=0;
            for(int k=0;k<i;k++)
            {
                sum+=circle[j+k]; // 시작 위치부터 부분 수열 합 개수만큼 누적합
            }
            ret.insert(sum);
        }
    }
    return ret.size();
}