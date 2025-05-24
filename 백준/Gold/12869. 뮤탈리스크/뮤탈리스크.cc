#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> scv;
int dp[61][61][61];

int main() 
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
      int temp;
      cin>>temp;
      scv.push_back(temp);
   }
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(scv[0],scv[1],scv[2]));

    dp[scv[0]][scv[1]][scv[2]]=1;

    vector<int> dmg = {9,3,1};

    while(q.size()){
       int a,b,c;
        tie(a,b,c) = q.front(); q.pop();

        sort(dmg.begin(), dmg.end());
        do {
            int na=max(0, a-dmg[0]);
            int nb=max(0, b-dmg[1]);
            int nc=max(0, c-dmg[2]);

            if (dp[na][nb][nc] == 0) {
                dp[na][nb][nc] = dp[a][b][c]+1;
                q.push(make_tuple(na,nb,nc));
            }
        } while (next_permutation(dmg.begin(),dmg.end()));
    }

    cout << dp[0][0][0]-1 << "\n";
}