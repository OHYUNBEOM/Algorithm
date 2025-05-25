#include<bits/stdc++.h>
using namespace std;
int n;
int ret = -100000;
string s;
vector<int> v;
vector<char> c;
int oper(char c,int a,int b)
{
	if(c=='+') return a+b;
	if(c=='-') return a-b;
	if(c=='*') return a*b;
}
void dfs(int idx,int cur_val) // idx = 연산자 인덱스 기준 
{
	if(idx==c.size())
	{
		ret=max(ret,cur_val);
		return;
	}
	// 괄호 없이 그냥 계산 
	int no = oper(c[idx],cur_val,v[idx+1]); // 현재까지 계산값, 연산자 바로 뒤에 값이랑 더해줘야하니까.
	dfs(idx+1,no); //다음 idx와 방금 계산한 no값 
	
	// 연산자 남은 경우 체크해주면서  
	if(idx+1<c.size())
	{
		int yes = oper(c[idx+1],v[idx+1],v[idx+2]); // 괄호 먼저 계산 
		int ret_yes = oper(c[idx],cur_val,yes);
		dfs(idx+2,ret_yes);
	}
}
int main()
{
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)	
	{
		if(isdigit(s[i])) v.push_back(s[i]-'0'); // 숫자의 경우 v에 push 
		else c.push_back(s[i]); // 수식일 경우 c에 push 
	}
	dfs(0,v[0]);
	cout<<ret;
}