#include <iostream>
#define MAX 101
#define INF 1e9

int d[MAX][MAX];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m, a, b, c;
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				d[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		std::cin >> a >> b >> c;

		d[a][b] = d[a][b] > c ? c : d[a][b];
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) {
				std::cout << "0 ";
			}
			else {
				std::cout << d[i][j] << " ";
			}
		}
		std::cout << "\n";
	}
}