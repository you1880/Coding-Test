#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int tc;
	std::cin >> tc;

	for (int t = 0; t < tc; t++) {
		int N, M, res = 0;
		std::cin >> N >> M;

		std::vector<int> A(N), B(M);
		for (int i = 0; i < N; i++) {
			std::cin >> A[i];
		}

		for (int i = 0; i < M; i++) {
			std::cin >> B[i];
		}

		std::sort(A.begin(), A.end(), std::greater<int>());
		std::sort(B.begin(), B.end(), std::greater<int>());

		for (int i = 0; i < N; i++) {
			if (A[i] > B[0]) {
				res += M;
			}
			else if (A[i] <= B[M - 1]) {
				continue;
			}
			else {
				for (int j = 0; j < M; j++) {
					if (A[i] > B[j]) {
						res++;
					}
				}
			}
		}

		std::cout << res << "\n";
	}
}