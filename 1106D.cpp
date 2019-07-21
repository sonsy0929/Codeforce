#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
vector<int> adj[100000];
bool visited[100000];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(0);
	visited[0] = true;
	while (!pq.empty()) {
		int curr = pq.top();
		pq.pop();
		printf("%d ", curr + 1);
		for (int next : adj[curr]) {
			if (!visited[next]) pq.push(next), visited[next] = true;
		}
	}
}