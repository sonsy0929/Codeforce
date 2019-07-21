#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> tup;
typedef pair<int, int> pi;
char map[1000][1000];
int visited[1000][1000];
const int roff[] = { -1, 1, 0, 0 };
const int coff[] = { 0, 0, -1, 1 };
queue<pi> q[10];
bool isEnd(int p) {
	for (int i = 0; i < p; i++) if (!q[i].empty()) return false;
	return true;
}
int main() {
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	int speed[10]{};
	for (int i = 0; i < p; i++) {
		scanf("%d", speed + i);
		if (speed[i] > 1000) speed[i] = 1000;
	}
	vector<tup> player;
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			map[i][j] = getchar();
			if (map[i][j] >= '1' && map[i][j] <= '9') player.push_back({ map[i][j] - '0', i, j });
		}
	}
	sort(player.begin(), player.end());
	for (auto tupCurr : player) {
		int num, r, c;
		tie(num, r, c) = tupCurr;
		q[num - 1].push({ r, c });
		visited[r][c] = num;
	}
	while (!isEnd(p)) {
		for (int i = 0; i < p; i++) {
			if (q[i].empty()) continue;
			for (int k = 1; k <= speed[i]; k++) {
				int qSize = q[i].size();
				for (int s = 0; s < qSize; s++) {
					int r = q[i].front().first, c = q[i].front().second;
					q[i].pop();
					for (int d = 0; d < 4; d++) {
						int nr = r + roff[d], nc = c + coff[d];
						if (nr < 0 || nc < 0 || nr >= n || nc >= m || map[nr][nc] == '#') continue;
						if (!visited[nr][nc]) {
							visited[nr][nc] = i + 1;
							q[i].push({ nr, nc });
						}
					}
				}
			}
		}
	}
	int ans[10]{};
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		int val = visited[i][j];
		if (visited[i][j]) ans[val]++;
	}
	for (int i = 1; i <= p; i++) printf("%d ", ans[i]);
	puts("");
}