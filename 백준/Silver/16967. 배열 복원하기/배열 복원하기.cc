#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int H, W, X, Y;
	std::cin >> H >> W >> X >> Y;

	int row = H + X, col = W + Y;

	std::vector<std::vector<int>> B(row, std::vector<int>(col, 0));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cin >> B[i][j];
		}
	}

	for (int i = X; i < H; i++) {
		for (int j = Y; j < W; j++) {
			B[i][j] -= B[i - X][j - Y];
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cout << B[i][j] << " ";
		}
		std::cout << "\n";
	}
}