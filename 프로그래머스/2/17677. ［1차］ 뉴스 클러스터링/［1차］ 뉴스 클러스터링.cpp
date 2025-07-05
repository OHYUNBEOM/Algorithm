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
    
    set<string> all_key; // 모든 key값 = 다중 집합의 전체 원소 모음
    for(auto it : str1_map) all_key.insert(it.first);
    for(auto it : str2_map) all_key.insert(it.first);
    
    double inter=0,uni=0; //inter : 교집합,uni : 합집합
    for(auto it : all_key)
    {
        inter+=min(str1_map[it],str2_map[it]); // 교집합의 개수 : min
        uni+=max(str1_map[it],str2_map[it]); 
        // 합집합의 개수 : max -> max(0,1)로 하나만 있는 원소도 들어감
    }
    if(inter==0 && uni==0) return 65536; // 공집합인 경우 1 * 65536 return
    return (int)(inter/uni*65536);
}
