#include<bits/stdc++.h>
using namespace std;
int n,priv,cur_time,team_num,mm,ss,team1,team2,team1_lead_time,team2_lead_time;
int total_time = 48*60;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %2d:%2d",&team_num,&mm,&ss);
		cur_time=mm*60+ss;
		
		if(team1>team2) team1_lead_time += cur_time-priv;
		if(team2>team1) team2_lead_time += cur_time-priv;
		if(team_num==1) team1++;
		else team2++;
		priv=cur_time;
	}
	if(priv<total_time)
	{
		if(team1>team2) team1_lead_time += total_time-priv;
		if(team2>team1) team2_lead_time += total_time-priv;
	}
	printf("%02d:%02d\n",team1_lead_time/60,team1_lead_time%60);
	printf("%02d:%02d\n",team2_lead_time/60,team2_lead_time%60);
}