#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	std::set<std::string> ans;
	std::vector<std::string> vec(n);
	std::vector<int> index(n, 0);

	for (int i = 0; i < k; i++) {
		index[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end());

	do {
		std::string tmp = "";
		for (int i = 0; i < n; i++) {
			if (index[i]) {
				tmp += vec[i];
			}	
		}
		ans.insert(tmp);
	} while (std::next_permutation(vec.begin(), vec.end()));

	std::cout << ans.size();
}