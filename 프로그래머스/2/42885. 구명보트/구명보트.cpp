#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    int cnt=0;
    int left=0;
    int right=people.size()-1;
    int temp=limit;
    while(left<=right)
    {
        limit=temp;
        if(people[left]+people[right]<=limit)
        {
            limit=limit-(people[left]+people[right]);
            left++;
            right--;
        }
        else
        {
            limit-=people[right];
            right--;
        }
        cnt++;
    }
    return cnt;
}