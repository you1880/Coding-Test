#include <iostream>
#include <map>
#include <stack>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, P, l, p, cnt = 0;
	std::cin >> N >> P;

	std::map<int, std::stack<int>> m;

	for (int i = 0; i < N; i++) {
		std::cin >> l >> p;

		if (m.find(l) == m.end()) {
			m[l] = std::stack<int>();
		}

		if (m[l].empty()) {
			m[l].push(p);
			cnt++;
		}
		else {
			while (!m[l].empty() && m[l].top() > p) {
				m[l].pop();
				cnt++;
			}

			if (m[l].empty()) {
				m[l].push(p);
				cnt++;
			}
			else {
				if (m[l].top() != p) {
					m[l].push(p);
					cnt++;
				}
			}
		}
	}
	std::cout << cnt;
}