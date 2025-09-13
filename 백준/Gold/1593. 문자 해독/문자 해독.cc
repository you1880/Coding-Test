#include <iostream>

std::string w, s;
int N, M, wcnt[100], scnt[100], idx = 0, ans;

int main() {
	std::cin >> N >> M;
	std::cin >> w >> s;

	for (auto c : w) {
		wcnt[c - 'A']++;
	}

	for (int i = 0; i < M; i++) {
		char c = s[i];
		if (scnt[c - 'A'] < wcnt[c - 'A']) {
			scnt[c - 'A']++;
		} else {
			for (int j = idx; j <= i; j++) {
				if (s[i] == s[j]) {
					idx = j + 1;
					break;
				}
				scnt[s[j] - 'A']--;
			}
		}
		if (i - idx + 1 == N) {
			ans++;
		}
	}
	
	std::cout << ans;
}