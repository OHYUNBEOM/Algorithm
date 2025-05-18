#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, S;
int board[50][50];
vector<pair<int, int>> vir;
vector<pair<int, int>> stk;

int dist[50][50];
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

int ans = 1000000007;

void bfs() {
	memset(dist, 0, sizeof(dist));
	queue<pair<int, int>> que;
	for (auto& p : stk) {
		dist[p.first][p.second] = 1;
		que.push(p);
	}

	while (!que.empty()) {
		int r = que.front().first, c = que.front().second; que.pop();
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i], cc = c + dc[i];
			if (-1 < rr && rr < N && -1 < cc && cc < N) {
				if (dist[rr][cc] == 0 && board[r][c] != 1) {
					dist[rr][cc] = dist[r][c] + 1;
					que.push(make_pair(rr, cc));
				}
			}
		}
	}
	int mx = 0; bool chk = 1;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (board[r][c] != 1) {
				if (dist[r][c] == 0) chk = 0;
				else mx = max(mx, dist[r][c]);
			}
		}
	}

	if (chk) ans = min(ans, mx);
}

void func(int idx) {
	if (stk.size() == M) {
		bfs();
		return;
	}
	if (idx == S) return;
	func(idx + 1);
	stk.emplace_back(vir[idx]);
	func(idx + 1);
	stk.pop_back();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> board[r][c];
			if (board[r][c] == 2) vir.emplace_back(make_pair(r, c));
		}
	}

	S = vir.size();
	func(0);

	if (ans == 1000000007) cout << -1;
	else cout << ans - 1;
}