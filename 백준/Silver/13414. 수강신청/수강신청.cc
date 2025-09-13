#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

bool comp(std::pair<std::string, int>& p1, std::pair<std::string, int>& p2) {
	return p1.second < p2.second;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<std::pair<std::string, int>> vec;
	std::map<std::string, int> m;
	std::string n;
	int K, L, cnt = 0;
	std::cin >> K >> L;

	for (int i = 0; i < L; i++) {
		std::cin >> n;
		m[n] = i;
	}

	for (auto e : m) {
		vec.push_back(e);
	}

	std::sort(vec.begin(), vec.end(), comp);

	for (int i = 0; i < vec.size(); i++) {
		if (i < K) {
			std::cout << vec[i].first << "\n";
		}
	}
}