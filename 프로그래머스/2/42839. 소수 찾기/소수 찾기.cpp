#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
void permutation(string numbers, set<int> &result)
{
    sort(numbers.begin(),numbers.end()); //오름차순 정렬
    do
    {
        for(int i=1;i<=numbers.size();i++)
        {
            string temp=numbers.substr(0,i);
            result.insert(stoi(temp));
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
}
int solution(string numbers) {
    set<int> num;
    permutation(numbers,num);
    int count=0;
    for(int n : num)
    {
        if(isPrime(n)) count++;
    }
    return count;
}