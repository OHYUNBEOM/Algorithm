#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[101], V[101];
int dp[101][100001];

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i]; // i번 물건의 무게와 가치
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (j < W[i]) {
                // 현재 물건 못 넣음
                dp[i][j] = dp[i - 1][j];
            } else {
                // 넣을 수 있음 → 넣을지 말지 선택
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            }
        }
    }

    cout << dp[N][K] << "\n";
    return 0;
}