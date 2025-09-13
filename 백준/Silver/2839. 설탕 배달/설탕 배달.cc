#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, cnt = 0;
	std::cin >> N;

	while (N >= 0) {
		if (N % 5 == 0) {
			cnt += N / 5;
			break;
		}
		
		N -= 3;
		cnt++;
	}

	cnt = N < 0 ? -1 : cnt;
	std::cout << cnt;
}