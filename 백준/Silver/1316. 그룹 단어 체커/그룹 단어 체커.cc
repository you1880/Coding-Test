#include <iostream>
#include <string>
#include <set>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	int count = N;

	for (int i = 0; i < N; i++) {
		std::string str;
		std::cin >> str;

		std::set<char> tmp;
		char prev;
		for (auto s : str) {
			auto itr = tmp.find(s);

			if (itr == tmp.end()) {
				tmp.insert(s);
				prev = s;
				continue;
			}
			else if (itr != tmp.end() && prev != s) {
				count--;
				break;
			}
		}
	}

	std::cout << count;
}