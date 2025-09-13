#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, p, sum = 0;
	std::cin >> n;
	std::vector<int> vec(n);

	if (n == 0) {
		std::cout << "0";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}
	p = static_cast<int>(std::round(n * 0.15));
	std::sort(vec.begin(), vec.end());

	for (int i = p; i < n - p; i++) {
		sum += vec[i];
	}

	std::cout << static_cast<int>(std::round(static_cast<double>(sum) / (n - p * 2.0)));
}