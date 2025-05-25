#include<bits/stdc++.h>
using namespace std;
int n=0,ret=INT_MIN; // 최대값 구하는 경우 INT_MIN, 최소값은 INT_MAX로 초기화 하는 습관을 가질것 
vector<int> v;
vector<char> c;
string s;
int oper(char c,int a,int b)
{
	if(c=='+') return a+b;
	if(c=='*') return a*b;
	if(c=='-') return a-b;
}
void dfs(int idx,int cur_val) // idx : 연산자의 index값, cur_val : 가장 최근 계산된 값(누적합) 
{
	if(idx==c.size()) // 연산자를 모두 사용했을 때 
	{
		ret=max(ret,cur_val); // 현재 경로(cur_val)의 계산 결과를 최댓값 후보로 갱신
		return;
	}
	
	// 괄호가 없는 경우 
	int no=oper(c[idx],cur_val,v[idx+1]);
	dfs(idx+1,no);
	
	// 괄호가 있는 경우 
	if(idx+1<c.size()) // 인덱스 범위 유의, 괄호 계산을 위한 idx+1이 c 범위에서 벗어나지 않도록 체크 
	{
		// 뒤쏙에 위치한 수식을 괄호를 씌웠다고 가정하고 먼저 계산 
		int yes=oper(c[idx+1],v[idx+1],v[idx+2]);
		// 먼저 괄호 개념으로 계산한 뒤쪽값과 현재 상태를 계산 
		int ret_yes=oper(c[idx],cur_val,yes);
		// 괄호로 계산한 경우 연산자 2개(c[idx], c[idx+1])를 사용했으므로 idx+2부터 탐색
		dfs(idx+2,ret_yes);
	}
}
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(isdigit(s[i])) v.push_back(s[i]-'0'); // 숫자형 문자 -> 정수로 변환 
		else c.push_back(s[i]);
	}
	dfs(0,v[0]);  
	cout<<ret;
}
