#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> citations) {
    sort(citations.begin(),citations.end());
    reverse(citations.begin(),citations.end());
    int h_max = citations[0];
    int n=citations.size();
    for(int h=h_max; h>=0; h--) // 인용 횟수가 가장 많은 논문부터 내림차순으로 검토
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(citations[i]>=h) cnt++; // 인용된 논문이 h편 이상인 논문을 카운팅
        }
        if(cnt>=h) return h; // h: 현재 우리가 H-index 후보로 체크 중인 인용 횟수
                             // cnt: 인용 횟수가 h 이상인 논문의 수
                             // if(cnt>=h) : h번 이상 인용된 논문이 h편 이상 있는가?
                             // 내림차순으로 h를 줄여가며 체크, 조건을 처음 만족한 순간의 h가 최대 H-index
    }
    return 0;
}