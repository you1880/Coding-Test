#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int n, sum, left, right, res = 0;
	std::cin >> n;

	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	std::cin >> sum;

	std::sort(arr.begin(), arr.end(), std::less<int>());

	left = 0, right = n - 1;

	while (left < right) {
		if (arr[left] + arr[right] == sum) {
			res++;
			left++;
			right--;
		}
		else if (arr[left] + arr[right] < sum) {
			left++;
		}
		else if (arr[left] + arr[right] > sum) {
			right--;
		}
	}

	std::cout << res;
}