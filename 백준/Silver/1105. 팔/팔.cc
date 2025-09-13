#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int count = 0;
	std::string L, R;
	std::cin >> L >> R;

	int ll = L.length();
	int rl = R.length();

	std::vector<char> ls(11, '0'), rs(11, '0');
	for (int i = ll - 1; i >= 0; i--) {
		ls[11 - ll + i] = L[i];
	}
	for (int i = rl - 1; i >= 0; i--) {
		rs[11 - rl + i] = R[i];
	}

	if (ll == rl) {
		for (int i = 0; i < 11; i++) {
			if (ls[i] == '8' && rs[i] == '8') {
				count++;
			}
			else if (ls[i] != rs[i]) {
				break;
			}
		}
	}
	else {
		count = 0;
	}
	std::cout << count;
}