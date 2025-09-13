#include <iostream>

int arr[101][101];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int x1, y1, x2, y2, cnt = 0;
	for (int i = 0; i < 4; i++) {
		std::cin >> x1 >> y1 >> x2 >> y2;	

		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				arr[x][y] = 1;
			}
		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] == 1) {
				cnt++;
			}
		}
	}
	std::cout << cnt;
}