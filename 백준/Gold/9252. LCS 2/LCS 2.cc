#include <iostream>
#include <vector>
#include <algorithm>

int lcs[1001][1001] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int x, y;
	std::string str1, str2;
	std::cin >> str1 >> str2;

	std::string result;

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	std::cout << lcs[str1.length()][str2.length()] << "\n";

	x = str1.length(), y = str2.length();

	while (lcs[x][y] != 0) {
		if (lcs[x][y] == lcs[x][y - 1]) {
			y -= 1;
		}
		else if (lcs[x][y] == lcs[x - 1][y]) {
			x -= 1;
		}
		else {
			result.push_back(str1[x - 1]);
			x -= 1;
			y -= 1;
		}
	}
	
	std::reverse(result.begin(), result.end());
	std::cout << result;
}