#include <iostream>
#include <set>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::set<std::string> s;
	std::string str;

	std::cin >> str;

	for (int i = 0; i < str.length(); i++) {
		s.insert(str.substr(i));
	}

	for (auto e : s) {
		std::cout << e << "\n";
	}
}