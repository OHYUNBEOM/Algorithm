#include <bits/stdc++.h>
using namespace std;
int n, c, temp;
map<int, int> m1, m2;
vector<int> v;
bool cmp(int a, int b){
    if(m1[a] != m1[b]) return m1[a] > m1[b];
    return m2[a] < m2[b];
}

int main(){
    cin >> n >> c;
    for (int i = 0; i < n; ++i){
        cin >> temp;
        v.push_back(temp);
        if(m1[temp]) ++m1[temp];
        else{
            m1[temp] = 1;
            m2[temp] = i;
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i:v) cout << i << " ";
    return 0;
}