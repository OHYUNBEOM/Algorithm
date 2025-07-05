#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> topping) {
    int ret=0;
    map<int,int> left,right;
    int left_kind=0,right_kind=0;
    for(auto it : topping)
    {
        if(right[it]==0) right_kind++;
        right[it]++;
    }
    for(int i=0;i<topping.size();i++)
    {
        // 왼쪽 추가
        if(left[topping[i]]==0) left_kind++;
        left[topping[i]]++;
        
        // 오른쪽 제거
        right[topping[i]]--;
        if(right[topping[i]]==0) right_kind--;
        
        // 종류 비교
        if(left_kind==right_kind) ret++;
    }
    return ret;
}