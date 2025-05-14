#include<bits/stdc++.h>
using namespace std;
int n,t_num,mm,ss,t1,t2,t1_lead_time,t2_lead_time;
int cur_time,priv;
int total_time=48*60;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %2d:%2d",&t_num,&mm,&ss);
		cur_time=mm*60+ss;
		if(t1>t2) t1_lead_time+=(cur_time-priv);
		else if(t2>t1) t2_lead_time+=(cur_time-priv);
		
		if(t_num==1) t1++;
		else if(t_num==2) t2++;
		
		priv=cur_time;
	}
	if(priv<total_time)
	{
		if(t1>t2) t1_lead_time+=(total_time-priv);
		else if(t2>t1) t2_lead_time+=(total_time-priv);
	}
	printf("%02d:%02d",t1_lead_time/60,t1_lead_time%60);
	printf("\n");
	printf("%02d:%02d",t2_lead_time/60,t2_lead_time%60);
}
