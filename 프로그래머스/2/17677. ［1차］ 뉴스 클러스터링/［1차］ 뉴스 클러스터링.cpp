#include<bits/stdc++.h>
using namespace std;
int solution(string str1, string str2) {
    transform(str1.begin(),str1.end(),str1.begin(),::tolower); // 소문자로 변환
    transform(str2.begin(),str2.end(),str2.begin(),::tolower); // 소문자로 변환
    map<string,int> str1_map,str2_map;
    for(int i=0;i<str1.size()-1;i++) // 다중 집합, 알파벳인지 검사
    {
        string temp=str1.substr(i,2);
        if(isalpha(temp[0]) && isalpha(temp[1]))
        {
            str1_map[temp]++;
        }
    }
    for(int i=0;i<str2.size()-1;i++)
    {
        string temp=str2.substr(i,2);
        if(isalpha(temp[0]) && isalpha(temp[1]))
        {
            str2_map[temp]++;
        }
    }
    set<string> all_key;
    for(auto it : str1_map) all_key.insert(it.first);
    for(auto it : str2_map) all_key.insert(it.first);
    
    double inter,uni=0;
    for(auto it : all_key)
    {
        inter+=min(str1_map[it],str2_map[it]);
        uni+=max(str1_map[it],str2_map[it]);
    }
    if(uni==0) return 65536;
    return (int)(inter/uni*65536);
}