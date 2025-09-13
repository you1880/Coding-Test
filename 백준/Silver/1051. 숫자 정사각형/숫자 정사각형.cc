#include <iostream>

int arr[50][50];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, area = 1, len;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::string n;
		std::cin >> n;
		for (int j = 0; j < M; j++) {
			arr[i][j] = n[j] - '0';
		}
	}
	
	len = N > M ? M : N;

	for (int l = 2; l <= len; l++) {
		for (int i = 0; i <= N - l; i++) {
			for (int j = 0; j <= M - l; j++) {
				if (arr[i][j] == arr[i + l - 1][j] && arr[i][j] == arr[i][j + l - 1] && arr[i][j] == arr[i + l - 1][j + l - 1]) {
					area = l * l;
				}
			}
		}
	}
	std::cout << area;
}