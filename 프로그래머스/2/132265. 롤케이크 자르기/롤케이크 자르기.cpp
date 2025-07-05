#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> topping) {
    int ret=0;
    map<int,int> left,right;
    for(auto it : topping)
    {
        right[it]++; // 오른쪽 구간에 전체 토핑 저장
    }
    for(int i=0;i<topping.size();i++)
    {
        left[topping[i]]++; // 왼쪽 구간으로 옮기기
        right[topping[i]]--; // 오른쪽 구간은 빼주기
        
        // 오른쪽 구간의 토핑 종류 다 사용했다면 key값 삭제
        if(right[topping[i]]==0) right.erase(topping[i]);
        
        // 왼쪽,오른쪽 구간의 key 개수가 같은 경우 = 공평한 경우
        if(left.size()==right.size()) ret++;
    }
    return ret;
}