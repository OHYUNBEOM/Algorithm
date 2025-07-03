#include<bits/stdc++.h>
using namespace std;
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end()); // 접두사 관계가 있으면 정렬했을 때 이어질것
    for(int i=0;i<phone_book.size()-1;i++) // i+1 비교를 위해 phone_book.size()-1 까지
    {
        string cur=phone_book[i];
        string next=phone_book[i+1];
        if(next.substr(0,cur.size())==cur) return false; // next에서 cur만큼 잘랐을 때 같으면 접두사
    }
    return true;
}