#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);


	int N, L, R, X, ans = 0;
	std::cin >> N >> L >> R >> X;

	std::vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	int s = (1 << N) - 1;
	for (int sub = s; sub; sub = (sub - 1) & s) {
		int max_idx = -1, min_idx = -1;
		int max_dif = -1, min_dif = 10000000;
		int sum = 0;

		for (int i = 0; i < N; i++) {
			if (sub & (1 << i)) {
				sum += arr[i];
				max_idx = std::max(max_idx, i);

				max_dif = std::max(max_dif, arr[i]);
				min_dif = std::min(min_dif, arr[i]);

				if (min_idx == -1) {
					min_idx = i;
				}
			}
		}
		if (min_idx == max_idx) {
			continue;
		}

		int diff = max_dif - min_dif;
		if (sum >= L && sum <= R && diff >= X) {
			ans++;
		}
	}
	
	std::cout << ans;
}