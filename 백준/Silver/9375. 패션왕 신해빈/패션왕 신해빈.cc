#include <iostream>
#include <map>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int n, tmp = 1;
		std::string s1, s2;
		std::map<std::string, int> dict;
		std::cin >> n;

		if (n == 0) {
			std::cout << "0\n";
			continue;
		}

		for (int j = 0; j < n; j++) {
			std::cin >> s1 >> s2;

			if (dict.find(s2) != dict.end()) {
				dict[s2]++;
			}
			else {
				dict.insert({ s2, 1 });
			}
		}
		for (auto e : dict) {
			tmp *= (e.second + 1);
		}

		std::cout << tmp - 1 << "\n";
	}
}