#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string S, T;
	std::cin >> S >> T;

	while (1) {
		if (T[T.size() - 1] == 'A') {
			T.pop_back();
		}
		else {			
			T.pop_back();
			std::reverse(T.begin(), T.end());
		}

		if (S.size() == T.size()) {
			if (S == T) {
				std::cout << "1";
			}
			else {
				std::cout << "0";
			}
			break;
		}
	}
}