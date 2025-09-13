#include <iostream>
#include <vector>

std::vector<std::vector<int>> nums(1001, std::vector<int>(10, 0));

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	int N;
	std::cin >> N;

	if (N == 1) {
		std::cout << 9;
	}
	else {
		nums[1] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		for (int i = 2; i <= N; i++) {
			for (int j = 0; j < 10; j++) {
				if (j == 0) {
					nums[i][j] = nums[i - 1][1] % 1000000000;
				}
				else if (j == 9) {
					nums[i][j] = nums[i - 1][8] % 1000000000;
				}
				else {
					nums[i][j] = (nums[i - 1][j - 1] + nums[i - 1][j + 1]) % 1000000000;
				}
			}
		}

		long long sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += nums[N][i];
		}

		std::cout << sum % 1000000000;
	}
}