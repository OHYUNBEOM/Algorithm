#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> operations) {
    int n = operations.size();
    multiset<int> ms;
    for(int i=0;i<n;i++)
    {
        string command = operations[i].substr(0,1);
        string value = operations[i].substr(2);
        if(command=="I")
        {
            ms.insert(stoi(value));
        }
        else if(ms.size() && command=="D")
        {
            if(value=="1")
            {
                ms.erase(*ms.rbegin());
            }
            else if(value=="-1") 
            {
                ms.erase(*ms.begin());
            }
        }
    }
    
    if(ms.empty()) return {0,0};
    return {*ms.rbegin(),*ms.begin()};
}