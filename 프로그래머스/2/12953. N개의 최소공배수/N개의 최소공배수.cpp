#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> arr) {
    int ret=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        ret=lcm(ret,arr[i]);
    }
    return ret;
}