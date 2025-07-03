#include<bits/stdc++.h>
using namespace std;
vector<int> solution(string s) {
    vector<vector<int>> tup;
    vector<int> temp;
    string num="";
    for(char c : s)
    {
        if(isdigit(c)) //숫자
        {
            num+=c;
        }
        else // 문자(,{,})
        {
            if(num.size()!=0) // num에 문자형 숫자가 있으면
            {
                temp.push_back(stoi(num)); // temp에 넣어주고 num 초기화
                num="";
            }
            if(c=='}') // 튜플 집합 끝났으면
            {
                if(temp.size()!=0)
                {
                    tup.push_back(temp); // vector 자체를 push
                    temp.clear();
                }
            }
        }
    }
    
    for(int i=0;i<tup.size();i++) // 원소 개수 확인해서 오름차순 정렬
    {
        for(int j=i+1;j<tup.size();j++)
        {
            if(tup[i].size()>tup[j].size()) // 원소 개수 순으로 오름차순 정렬
            {
                vector<int> temp=tup[i];
                tup[i]=tup[j];
                tup[j]=temp;
            }
        }
    }
    
    vector<int> answer;
    set<int> ret;
    for(int i=0;i<tup.size();i++)
    {
        for(int j=0;j<tup[i].size();j++)
        {
            int num=tup[i][j];
            if(ret.find(num)==ret.end()) // set 자료구조에서 못찾았다면 (중복 x)
            {
                answer.push_back(num);
                ret.insert(num);
            }
        }
    }
    return answer;
}