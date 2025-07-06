#include<bits/stdc++.h>
using namespace std;
int solution(string dirs) {
    set<tuple<int,int,int,int>> visited;
    int y=0,x=0;
    for(char c : dirs)
    {
        int ny=y,nx=x;
        if(c=='U') ny++;
        if(c=='D') ny--;
        if(c=='R') nx++;
        if(c=='L') nx--;
        if(ny<-5 || ny>5 || nx<-5 || nx>5) continue;
        visited.insert({y,x,ny,nx});
        visited.insert({ny,nx,y,x}); // 한번 가본 길 = 반대로 와도 가본 길이므로 반대도 처리해줌
        y=ny; // 한칸 옮겨간 곳에서 이어서 탐색
        x=nx;
    }
    return visited.size()/2; // 반대로 온 경우도 포함했으므로 2 나누고 return
}