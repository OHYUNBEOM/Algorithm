#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    int n = operations.size();
    multiset<int> ms;
    for(int i=0;i<n;i++)
    {
        if(operations[i].substr(0,1)=="I")
        {
            ms.insert(stoi(operations[i].substr(2)));
        }
        else if(ms.size() && operations[i].substr(0,1)=="D")
        {
            if(operations[i].substr(2)=="1")
            {
                ms.erase(*ms.rbegin());
                //ms.erase(prev(ms.end()));
            }
            else if(operations[i].substr(2)=="-1") 
            {
                ms.erase(*ms.begin());
            }
        }
    }
    vector<int> answer;
    if(ms.size()==0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*ms.rbegin());
        answer.push_back(*ms.begin());
    }
    return answer;
}