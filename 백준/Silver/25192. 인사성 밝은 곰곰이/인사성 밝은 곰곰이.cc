#include <iostream>
#include <set>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::set<std::string> s;
	int N, cnt = 0;
	std::string str;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str;

		if (str == "ENTER") {
			s.clear();
			continue;
		}
		
		if (s.find(str) == s.end()) {
			s.insert(str);
			cnt++;
		}
		else {
			continue;
		}
	}
	std::cout << cnt;
}