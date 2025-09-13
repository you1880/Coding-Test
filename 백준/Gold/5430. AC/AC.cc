#include <iostream>
#include <vector>
#include <sstream>
#include <deque>

std::string AC(std::string p, std::deque<int> dq) {
	std::string result = "[";
	bool r_flag = false;

	for (auto cmd : p) {
		if (cmd == 'D' && dq.size() == 0) {
			return "error\n";
		}
		else {
			if (cmd == 'R') {
				r_flag = r_flag ? false : true;
			}
			else {
				r_flag ? dq.pop_back() : dq.pop_front();
			}
		}
	}

	if (dq.size() == 0) {
		return "[]\n";
	}

	if (r_flag) {
		for (auto itr = dq.rbegin(); itr != dq.rend(); itr++) {
			result += (std::to_string(*itr) + ",");
		}
		result += "]\n";
	}
	else {
		for (auto itr = dq.begin(); itr != dq.end(); itr++) {
			result += (std::to_string(*itr) + ",");
		}
		result += "]\n";
	}

	return result.replace(result.length() - 3, 2, "]");
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T, n;
	std::string p, arr, tmp;

	std::cin >> T;
	for (int i = 0; i < T; i++) {
		bool r_flag = false;
		std::cin >> p >> n >> arr;
		std::deque<int> dq;

		std::istringstream ss(arr.substr(1, arr.length() - 2));

		while (std::getline(ss, tmp, ',')) {
			dq.push_back(std::stoi(tmp));
		}

		std::cout << AC(p, dq);
	}
}