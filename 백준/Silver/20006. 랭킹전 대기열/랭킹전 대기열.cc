#include <iostream>
#include <vector>
#include <map>

struct Room {
	int size;
	int diff;
	std::map<std::string, int> players;
	
	Room(int s, int d)
		: size(s), diff(d), players(std::map<std::string, int>()) {}
};

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::vector<Room> vec;
	int p, m, l;
	std::string n;

	std::cin >> p >> m;
	
	for (int i = 0; i < p; i++) {
		int flag = 0;
		std::cin >> l >> n;

		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].size < m && (l >= vec[i].diff - 10 && l <= vec[i].diff + 10)) {
				vec[i].players.insert({ n, l });
				vec[i].size++;
				flag = 1;
				break;
			}
		}

		if (!flag) {
			vec.push_back(Room(1, l));
			vec[vec.size() - 1].players.insert({ n, l });
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].size == m) {
			std::cout << "Started!\n";
		}
		else {
			std::cout << "Waiting!\n";
		}
		for (const auto& e : vec[i].players) {
			std::cout << e.second << " " << e.first << "\n";
		}
	}
}