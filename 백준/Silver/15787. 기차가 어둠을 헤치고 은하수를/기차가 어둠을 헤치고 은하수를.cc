#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N, M, op, i, x, ans = 0;

	std::cin >> N >> M;

	std::vector<int> trains(N + 1);
	std::vector<bool> log(1 << 21, false);
	for (int m = 0; m < M; m++) {
		std::cin >> op;

		if (op == 1) {			
			std::cin >> i >> x;
			trains[i] |= (1 << x);
		}
		else if (op == 2) {			
			std::cin >> i >> x;
			trains[i] &= ~(1 << x);
		}
		else if (op == 3) {			
			std::cin >> i;
			trains[i] = trains[i] << 1;
			trains[i] &= ((1 << 21) - 1);
		}
		else if (op == 4) {			
			std::cin >> i;
			trains[i] = trains[i] >> 1;
			trains[i] &= ~1;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!log[trains[i]]) {
			ans++;
			log[trains[i]] = true;
		}
	}

	std::cout << ans;
}