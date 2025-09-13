#include <iostream>

int arr[1001] = { 0, 1, 2 };

int dp(int n) {
	if (n == 1)
		return arr[1];
	else if (n == 2)
		return arr[2];
	else if (arr[n] > 0) {
		return arr[n];
	}
	else {
		arr[n] = (dp(n - 1) + dp(n - 2)) % 10007;
		return arr[n];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	std::cout << dp(n);
}