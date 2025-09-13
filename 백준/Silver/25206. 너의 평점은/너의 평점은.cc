#include <iostream>
#include <string>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::map<std::string, double> dic = { {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0},{"C+", 2.5},{"C0",2.0},{"D+", 1.5}, {"D0",1.0}, {"F", 0.0} };
	std::string sub, grd;
	double sc;
	double sum = 0.0, cnt = 0.0;

	for (int i = 0; i < 20; i++) {
		std::cin >> sub >> sc >> grd;

		if (grd == "P")
			continue;
		else {
			auto itr = dic.find(grd);
			sum += itr->second * sc;
		}
		cnt += sc;
	}

	std::cout << sum / cnt;
}