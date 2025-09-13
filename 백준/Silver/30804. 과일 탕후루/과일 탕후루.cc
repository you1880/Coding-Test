#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::vector<int> vec, frs(10, 0);
	int N, res = 0;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		std::cin >> x;

		vec.push_back(x);
	}

	int l = 0, r = 0;

	while (r < N) {
		frs[vec[r]]++;
		r++;
	
		while (true) {
			int cnt = 0;
			for (int i = 1; i <= 9; i++) {
				if (frs[i]) cnt++;
			}

			if (cnt > 2) {
				frs[vec[l]]--;
				l++;
			}
			else {
				break;
			}
		}

		res = std::max(res, r - l);
	}

	std::cout << res;
}