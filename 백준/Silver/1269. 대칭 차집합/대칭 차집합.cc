#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::unordered_set<int> s1, s2;
	std::vector<int> v1, v2;
	int A, B, a, b;
	std::cin >> A >> B;

	for (int i = 0; i < A; i++) {
		std::cin >> a;
		s1.insert(a);
		v1.push_back(a);
	}

	for (int i = 0; i < B; i++) {
		std::cin >> b;
		s2.insert(b);
		v2.push_back(b);
	}
	
	if (A < B) {
		for (auto e : v1) {
			if (s1.find(e) != s1.end() && s2.find(e) != s2.end()) {
				s1.erase(e);
				s2.erase(e);
			}
		}
	}
	else {
		for (auto e : v2) {
			if (s1.find(e) != s1.end() && s2.find(e) != s2.end()) {
				s1.erase(e);
				s2.erase(e);
			}
		}
	}
	std::cout << s1.size() + s2.size();
}