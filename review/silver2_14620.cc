#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, ret = INT_MAX;
int board[12][12];
bool visited[12][12];

// 특정 좌표에 꽃을 심을 수 있는지 확인
bool canPlace(int y, int x) {
    if (visited[y][x]) return false;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
            return false;
    }
    return true;
}

// 꽃 심기
int placeFlower(int y, int x) {
    int cost = board[y][x];
    visited[y][x] = true;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        visited[ny][nx] = true;
        cost += board[ny][nx];
    }
    return cost;
}

// 꽃 제거
void removeFlower(int y, int x) {
    visited[y][x] = false;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        visited[ny][nx] = false;
    }
}

void dfs(int cnt, int sum) {
    if (cnt == 3) {
        ret = min(ret, sum);
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (canPlace(i, j)) {
                int cost = placeFlower(i, j);
                dfs(cnt + 1, sum + cost);
                removeFlower(i, j);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    dfs(0, 0);
    cout << ret;
}
