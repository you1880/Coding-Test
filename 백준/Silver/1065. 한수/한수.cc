#include <iostream>
#include <string>

bool hans(int n) {
	std::string num = std::to_string(n);
	int gap = (num[0] - '0') - (num[1] - '0');

	for (int i = 2; i < num.length(); i++) {
		int gap2 = (num[i - 1] - '0') - (num[i] - '0');
		if (gap != gap2) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, cnt = 0;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i < 100) {
			cnt++;
		}
		else {
			if (hans(i)) {
				cnt++;
			}
		}
	}
	std::cout << cnt;
}