#include<bits/stdc++.h>
using namespace std;
int solution(vector<vector<string>> clothes) {
    int ret=1;
    map<string,int> mp;
    for(int i=0;i<clothes.size();i++)
    {
        mp[clothes[i][1]]++; // 의상 종류 카운팅
    }
    for(auto it : mp)
    {
        ret*=it.second+1; // ex) headgear 2개, eyewear 1개 
                          // headgear(2) * headgear x (1) + eyewear(1) * eyewear x (1)
        // headgear 2종류 + 착용하지 않는 경우 1종류로 조합 계산
    }
    ret--; // 아무것도 착용하지 않는 경우는 전체 경우의 수에서 제외
    return ret;
}