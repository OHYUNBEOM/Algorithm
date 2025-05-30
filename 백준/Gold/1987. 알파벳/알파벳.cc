#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int r,c,ny,nx,cnt;
char a[24][24];
bool visited[26];
void DFS(int y,int x)
{
	cnt=max(cnt,(int)count(visited,visited+26,true));
	for(int i=0;i<4;i++)
	{
		ny = y+dy[i];
		nx = x+dx[i];
		int idx = a[ny][nx]-'A';
		if(ny<0 || ny>=r || nx<0 || nx>=c || visited[idx]) continue;
		if(!visited[idx])
		{
			visited[idx]=true;
			DFS(ny,nx);
			visited[idx]=false;
		}
	}
}
int main()
{
   cin>>r>>c;
   for(int i=0;i<r;i++)
   {
      for(int j=0;j<c;j++)
      {
         cin>>a[i][j];
      }
   }
   visited[a[0][0]-'A']=true;
   DFS(0,0);
   
   cout<<cnt;
}