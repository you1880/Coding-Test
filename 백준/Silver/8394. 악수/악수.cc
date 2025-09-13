#include <iostream>
#include <vector>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::vector<int> vec = { 0, 0, 2, 3 };
	int n;
	std::cin >> n;

	if (n > 3) {
		for (int i = 4; i <= n; i++) {
			int tmp = (vec[i - 2] + vec[i - 1]) % 10;
			vec.push_back(tmp);
		}
	}		
	std::cout << vec[n];
}