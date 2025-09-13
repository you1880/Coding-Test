#include <iostream>
#include <algorithm>

std::string S, T;
int res = 0;

void func(std::string Tstr) {
	if (res == 1) {
		return;
	}

	if (Tstr == S) {
		res = 1;
		return;
	}

	if (S.length() >= Tstr.length()) {
		return;
	}

	if (Tstr[Tstr.length() - 1] == 'A') {
		std::string tmp = Tstr;

		tmp.pop_back();
		func(tmp);
	}

	if (Tstr[0] == 'B') {
		std::string tmp = Tstr;

		std::reverse(tmp.begin(), tmp.end());
		tmp.pop_back();
		func(tmp);
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> S >> T;
	func(T);

	std::cout << res;
}