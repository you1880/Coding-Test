#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N, M, i = 0, j = 0, sum = 0, cnt = 0;
	std::cin >> N >> M;

	std::vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	sum = arr[0];

	while (j < N) {
		if (sum < M) {
			j++;
			if (j < N) {
				sum += arr[j];
			}
		}
		else if (sum > M) {
			sum -= arr[i++];
		}
		else if (sum == M) {
			cnt++;
			sum -= arr[i++];
			if (++j < N) {
				sum += arr[j];
			}
		}
	}
	std::cout << cnt;
}