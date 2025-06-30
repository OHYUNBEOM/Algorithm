#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int r1=arr1.size(); 
    int r2=arr1[0].size();
    int r3=arr2[0].size();
    for(int i=0;i<r1;i++) // arr1의 행
    {
        answer.push_back(vector<int>(r3,0)); 
        // arr1*arr2 = arr1행*arr2열 꼴이라서 
        // 바깥 for이 r1, push_back 하는 vector<int> 의 기준이 r3가 됨
    }
    for(int i=0;i<r1;i++) // arr1의 행
    {
        for(int j=0;j<r3;j++) // arr2의 열
        {
            for(int k=0;k<r2;k++) // arr1의 열이자 arr2으 행
            {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}