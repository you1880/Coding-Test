#include <iostream>

long long pw(int A, int B, int C) {
	if (B == 0) {
		return 1;
	}
	long long tmp = pw(A, B / 2, C);
	tmp = (tmp * tmp) % C;

	if (B % 2 == 0) {
		return tmp;
	}
	else {
		return (tmp * A) % C;
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int A, B, C;
	std::cin >> A >> B >> C;

	std::cout << pw(A, B, C);
}