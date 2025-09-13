#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool compare(std::string s1, std::string s2) {
	if (s1.length() == s2.length())
		return s1 < s2;
	
	return s1.length() < s2.length();
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<std::string> vec;
	std::string str;
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str;
		vec.push_back(str);
	}
	
	std::sort(vec.begin(), vec.end(), compare);
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

	for (auto e : vec)
		std::cout << e << "\n";
}