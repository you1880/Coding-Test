#include <iostream>
#include <vector>
#include <algorithm>

int N;

void pooling(std::vector<std::vector<int>> vec) {
	int size = vec.size();

	if (size == 1) {
		std::cout << vec[0][0];
		return;
	}
	else {
		std::vector<std::vector<int>> tmp(size / 2, std::vector<int>(size / 2, 0));

		for (int i = 0; i < size; i += 2) {
			for (int j = 0; j < size; j += 2) {
				std::vector<int> ns = { vec[i][j], vec[i][j + 1],vec[i + 1][j], vec[i + 1][j + 1] };
				std::sort(ns.begin(), ns.end());
				tmp[i / 2][j / 2] = ns[2];
			}
		}

		pooling(tmp);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N;

	std::vector<std::vector<int>> vec(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> vec[i][j];
		}
	}

	pooling(vec);
}