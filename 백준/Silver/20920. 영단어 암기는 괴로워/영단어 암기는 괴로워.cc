#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

bool compare(std::pair<std::string, int>& w1, std::pair<std:: string, int>& w2) {
	int len1 = w1.first.length();
	int len2 = w2.first.length();

	if (w1.second == w2.second) {
		if (len1 == len2) {
			return w1 < w2;
		}
		return len1 > len2;
	}
	return w1.second > w2.second;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string word;
	std::map<std::string, int> words;
	int N, M;

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> word;

		if (word.length() >= M) {
			words[word]++;
		}
	}

	std::vector<std::pair<std::string, int>> vec(words.begin(), words.end());
	std::sort(vec.begin(), vec.end(), compare);

	for (auto e : vec) {
		std::cout << e.first << "\n";
	}
}