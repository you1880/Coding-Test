#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::unordered_set<std::string> names;
	std::vector<std::string> tmp;
	std::string name;
	int N, cnt, res = 0;
	char ch;

	std::cin >> N >> ch;

	cnt = ch == 'Y' ? 1 : ch == 'F' ? 2 : 3;

	for (int i = 0; i < N; i++) {
		std::cin >> name;

		if (names.find(name) != names.end()) {
			continue;
		}

		names.insert(name);
		tmp.push_back(name);

		if (tmp.size() == cnt) {
			res++;
			tmp.clear();
		}
	}
	
	std::cout << res;
}