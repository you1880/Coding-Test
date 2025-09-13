#include <iostream>
#define MAX 100002

int arr[MAX];
int diff[MAX] = { 0, };

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N, M, a, b, k;
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];
	}

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b >> k;

		diff[a] += k;
		diff[b + 1] -= k;
	}

	for (int i = 1; i <= N; i++) {
		diff[i] = diff[i] + diff[i - 1];

		arr[i] = arr[i] + diff[i];
		std::cout << arr[i] << " ";
	}
}