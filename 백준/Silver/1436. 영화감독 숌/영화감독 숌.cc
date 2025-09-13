#include <iostream>
#include <string>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int N, n = 666, cnt = 0;
	std::cin >> N;

	while (1) {
		std::string tmp = std::to_string(n);

		if (tmp.find("666") != std::string::npos) {
			cnt++;

			if (cnt == N) {
				std::cout << tmp;
				return 0;
			}
		}
		n++;
	}
}