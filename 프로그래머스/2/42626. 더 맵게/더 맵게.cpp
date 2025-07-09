#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> scoville, int K) {
    // 모든 음식 스코빌 지수 K 이상으로
    // 섞은 음식 스코빌 지수 = 가장 낮은 스코빌 + (두번째 스코빌 * 2)
    // 가장 작은 스코빌 2개 쓴다 = 최소 힙쓰면 편하다
    // 모든 음식 스코빌 지수가 K 이상 될때까지 섞는다 = while 사용?
    // 모든 음식의 스코빌 지수를 K 이상 만들기 위해 최소 횟수 return
    // scoville 길이 = 100만까지 준걸로 보아 무식하게 완탐으로는 못품
    // K 이상으로 만들수 없는 경우 -1 return -> flag 하나 사용해서 false면 -1을 return?
    priority_queue<int,vector<int>,greater<int>> pq;
    int answer = 0;
    for(int i=0;i<scoville.size();i++)
    {
        pq.push(scoville[i]); // 최소 힙, pq.top()에는 최솟값이 들어감
    }
    while(pq.size()>=2 && pq.top()<K)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a+b*2);
        answer++;
    }
    if(pq.top()>=K) return answer;
    else return -1;
}