#include <iostream>
#include <unordered_set>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	std::unordered_set<std::string> sets = { "ChongChong" };
	int N;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string s1, s2;

		std::cin >> s1 >> s2;

		if (sets.find(s1) != sets.end() || sets.find(s2) != sets.end()) {
			sets.insert(s1);
			sets.insert(s2);
		}
	}

	std::cout << sets.size();
}