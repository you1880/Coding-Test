#include <iostream>
#define MAX 401
#define INF 1e9

int dist[MAX][MAX];
int V, E;

void Floyd() {
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int a, b, c;
	std::cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i != j) dist[i][j] = INF;
		}
	}

	for (int i = 0; i < E; i++) {
		std::cin >> a >> b >> c;

		dist[a][b] = c;
	}

	Floyd();

	int res = INF;

	for (int i = 1; i <= V; i++) {
		for (int j = i + 1; j <= V; j++) {
			res = std::min(res, dist[i][j] + dist[j][i]);
		}
	}

	if (res == INF) {
		std::cout << -1;
	}
	else {
		std::cout << res;
	}
}