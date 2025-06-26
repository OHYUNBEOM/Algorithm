#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    for(int height=3; height<=sqrt(total); height++)
    {
        int width=total/height;
        if((height-2) * (width-2) == yellow)
        {
            return {width,height};
        }
    }
}