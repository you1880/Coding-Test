#include <iostream>
#include <algorithm>
#include <vector>

struct Score {
	std::string name;
	int kor;
	int eng;
	int math;

	Score(std::string _name, int _kor, int _eng, int _math)
		: name(_name), kor(_kor), eng(_eng), math(_math) {}

	bool operator<(const Score& s) const {
		if (s.kor == kor && s.eng == eng && s.math == math) {
			return name < s.name;
		}
		else if (s.kor == kor && s.eng == eng) {
			return math > s.math;
		}
		else if (s.kor == kor) {
			return eng < s.eng;
		}
		else {
			return kor > s.kor;
		}
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<Score> vec;
	int N, k, e, m;
	std::string name;
	
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> name >> k >> e >> m;

		vec.push_back(Score(name, k, e, m));
	}

	std::sort(vec.begin(), vec.end());

	for (auto s : vec) {
		std::cout << s.name << "\n";
	}
}