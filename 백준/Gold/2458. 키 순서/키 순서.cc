#include <iostream>
#define MAX 501

int dist[MAX][MAX];
int N, M;

void Floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) dist[i][j] = 0;
			else dist[i][j] = 1;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;

		dist[a][b] = 1;
	}

	Floyd();

	int res = 0;

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			cnt += (dist[i][j] | dist[j][i]);
		}
		
		if (cnt == N)
			res++;
	}

	std::cout << res;
}