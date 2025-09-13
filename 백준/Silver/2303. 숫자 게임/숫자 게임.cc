#include <iostream>
#include <vector>
#include <algorithm>

int compare(std::pair<int, int>& p1, std::pair<int, int>& p2) {
	if (p1.second == p2.second) {
		return p1.first > p2.first;
	}
	return p1.second > p2.second;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> arr(N, std::vector<int>(5, 0));
	std::vector<std::pair<int, int>> ans(N, { 0, 0 });

	std::vector<int> index(5, 1);
	index[3] = index[4] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> arr[i][j];
		}

		ans[i].first = i + 1;
		std::sort(arr[i].begin(), arr[i].end());
	}

	for (int i = 0; i < N; i++) {
		do {
			int sum = 0;

			for (int j = 0; j < 5; j++) {
				if (index[j] == 1) {
					sum += arr[i][j];
				}
			}

			if (sum % 10 > ans[i].second) {
				ans[i].second = sum % 10;
			}
		} while (std::next_permutation(arr[i].begin(), arr[i].end()));
	}

	std::sort(ans.begin(), ans.end(), compare);
	std::cout << ans[0].first;
}