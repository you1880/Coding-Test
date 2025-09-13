#include <iostream>

int arr[101][101];
int N, M;

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int res = 0;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++) {
				arr[x][y]++;
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j] > M) {
				res++;
			}
		}
	}
	
	std::cout << res;
}