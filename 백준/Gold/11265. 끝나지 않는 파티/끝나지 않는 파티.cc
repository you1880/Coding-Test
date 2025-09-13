#include <iostream>
#define MAX 501

int dist[MAX][MAX];
int N, M;

void Floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int A, B, C;
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> dist[i][j];
		}
	}

	Floyd();

	for (int i = 0; i < M; i++) {
		std::cin >> A >> B >> C;

		if (C >= dist[A][B]) {
			std::cout << "Enjoy other party\n";
		}
		else {
			std::cout << "Stay here\n";
		}
	}
}