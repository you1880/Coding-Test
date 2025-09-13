#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, sum = 0;
	std::cin >> N;

	std::vector<int> A(N), B(N);

	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}

	std::sort(A.begin(), A.end(), std::greater<int>());
	std::sort(B.begin(), B.end(), std::less<int>());

	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}
	std::cout << sum;
}