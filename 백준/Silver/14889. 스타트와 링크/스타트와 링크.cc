#include <iostream>
#include <vector>
#include <cmath>

int N;
std::vector<std::vector<int>> vec(21, std::vector<int>(21, 0));
std::vector<int> arr(21, 0);
int res = 987654321;

void func(int cnt, int idx) {
	if (cnt == N / 2) {	
		int st = 0, li = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i] == 1 && arr[j] == 1) {
					st += vec[i][j];
				}
				else if (arr[i] == 0 && arr[j] == 0) {
					li += vec[i][j];
				}
			}
		}
		
		int sum = std::abs(st - li);
		res = res > sum ? sum : res;

		return;
	}

	for (int i = idx; i <= N; i++) {
		if (!arr[i]) {
			arr[i] = 1;
			func(cnt + 1, i);
			arr[i] = 0;
		}
	}
}
int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> vec[i][j];
		}
	}

	func(0, 1);

	std::cout << res;
}