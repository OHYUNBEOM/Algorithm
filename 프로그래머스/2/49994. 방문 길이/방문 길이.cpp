#include<bits/stdc++.h>
using namespace std;
int solution(string dirs) {
    set<tuple<int,int,int,int>> visited;
    int y=0;
    int x=0;
    for(char c : dirs)
    {
        int ny=y;
        int nx=x;
        if(c=='U') ny++;
        if(c=='D') ny--;
        if(c=='L') nx--;
        if(c=='R') nx++;
        if(nx<-5 || nx>5 || ny<-5 || ny>5) continue;
        visited.insert({y,x,ny,nx});
        visited.insert({ny,nx,y,x});
        y=ny;
        x=nx;
    }
    return visited.size()/2;
}