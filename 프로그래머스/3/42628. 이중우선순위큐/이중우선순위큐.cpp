#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> operations) {
    int n = operations.size();
    multiset<int> ms;
    for(int i=0;i<n;i++)
    {
        string command = operations[i].substr(0,1);
        string value = operations[i].substr(2);
        if(command=="I") ms.insert(stoi(value));
        else // command == "D"
        {
            if(ms.size() && value=="1")
            {
                ms.erase(*ms.rbegin());
            }
            else if(ms.size() && value=="-1")
            {
                ms.erase(*ms.begin());
            }
        }
    }
    if(!ms.size()) return {0,0};
    else return {*ms.rbegin(),*ms.begin()};
}