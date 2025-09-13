#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int N, A, B, C, p;
	std::cin >> N >> A >> B >> C;

	std::vector<int> vec(N), price;
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end(), std::greater<int>());

	price.push_back(static_cast<int>(C / A));

	for (int i = 0; i < N; i++) {
		C += vec[i];

		price.push_back(static_cast<int>(C / (A + B * (i + 1))));
	}

	std::sort(price.begin(), price.end(), std::greater<int>());

	std::cout << price[0];
}