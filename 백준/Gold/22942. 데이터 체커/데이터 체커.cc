#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

struct Data {
	int xloc;
	int dir;
	int id;

	Data(int x, int d, int i)
		: xloc(x), dir(d), id(i) {}
};

int compare(Data& d1, Data& d2) {
	return d1.xloc < d2.xloc;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	std::stack<int> stk;
	std::vector<Data> vec;
	int N, x, r;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> x >> r;

		vec.push_back(Data(x - r, 1, i));
		vec.push_back(Data(x + r, 0, i));
	}

	std::sort(vec.begin(), vec.end(), compare);

	for (auto& e : vec) {
		if (e.dir == 1) {
			stk.push(e.id);
		}
		else {
			if (stk.top() != e.id) {
				std::cout << "NO";
				return 0;
			}
			else {
				stk.pop();
			}
		}
	}

	std::cout << "YES";
}