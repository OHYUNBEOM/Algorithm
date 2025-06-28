#include<bits/stdc++.h>
using namespace std;
int solution(int k, vector<int> tangerine) {
    int cnt=0;
    map<int,int> mp;
    for(int i=0;i<tangerine.size();i++)
    {
        mp[tangerine[i]]++;
    }
    vector<int> v;
    for(auto it : mp)
    {
        v.push_back(it.second);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(auto it : v)
    {
        k-=it;
        cnt++;
        if(k<=0) return cnt;
    }
}