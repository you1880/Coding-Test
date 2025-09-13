#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<int> vec(N + 3), loc(N + 3);
	vec[1] = 0, vec[2] = 1, vec[3] = 1;
	loc[1] = 0, loc[2] = 1, loc[3] = 1;

	for (int i = 4; i <= N; i++) {
		vec[i] = vec[i - 1] + 1;
		loc[i] = i - 1;

		if (i % 3 == 0) {
			if (vec[i] >= vec[i / 3] + 1) {
				loc[i] = i / 3;
			}
			vec[i] = std::min(vec[i], vec[i / 3] + 1);
		}
		if (i % 2 == 0) {
			if (vec[i] >= vec[i / 2] + 1) {
				loc[i] = i / 2;
			}
			vec[i] = std::min(vec[i], vec[i / 2] + 1);
		}
	}

	std::cout << vec[N] << "\n";
	for (int n = N; n != 0; n = loc[n]) {
		std::cout << n << " ";
	}
}