#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int arr[21] = { 0, };

	int M, x;
	std::string op;
	std::cin >> M;

	for (int i = 0; i < M; i++) {
		std::cin >> op;

		if (op == "add") {
			std::cin >> x;
			arr[x] = 1;
		}
		else if (op == "remove") {
			std::cin >> x;
			arr[x] = 0;
		}
		else if (op == "check") {
			std::cin >> x;
			std::cout << arr[x] << "\n";
		}
		else if (op == "toggle") {
			std::cin >> x;
			arr[x] = arr[x] ^ 1;
		}
		else if (op == "all") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 1;
			}
		}
		else if (op == "empty") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 0;
			}
		}
	}
}