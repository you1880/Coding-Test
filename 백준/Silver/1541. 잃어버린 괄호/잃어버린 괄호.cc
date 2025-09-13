#include <iostream>
#include <vector>
#include <string>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::vector<int> nums;
	std::string line, tmp = "";
	char op = '+';
	int num, res =0, sum = 0;
	bool flag = false;

	std::cin >> line;

	for (auto& ch : line) {
		if (ch == '+' || ch == '-') {
			num = op == '+' ? std::stoi(tmp) : std::stoi(tmp) * -1;
			nums.push_back(num);
			op = ch;
			tmp = "";
		}
		else {
			tmp += ch;
		}
	}

	num = op == '+' ? std::stoi(tmp) : std::stoi(tmp) * -1;
	nums.push_back(num);

	for (auto e : nums) {
		if (e < 0) {
			flag = true;
			res += e;
		}
		else {
			if (flag) {
				res += (e * -1);
			}
			else {
				res += e;
			}
		}
	}

	std::cout << res;
}