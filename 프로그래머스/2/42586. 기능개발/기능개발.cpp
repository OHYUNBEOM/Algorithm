#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int n = progresses.size();
    int cnt[104]={0};
    while(true)
    {
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(progresses[i]<100)
            {
                progresses[i]+=speeds[i];
                cnt[i]++;
                flag=false;
            }
        }
        if(flag) break;
    }
    vector<int> ret;
    int first=cnt[0];
    int f_cnt=1;
    for(int i=1;i<n;i++)
    {
        if(cnt[i]<=first) f_cnt++;
        else
        {
            ret.push_back(f_cnt);
            first=cnt[i];
            f_cnt=1;
        }
    }
    ret.push_back(f_cnt);
    return ret;
}