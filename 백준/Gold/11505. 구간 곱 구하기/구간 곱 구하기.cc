#include <iostream>
#include <vector>
#define MOD 1'000'000'007

int N, M, K;

class SegmentTree {
	std::vector<long long> tree;
	int size;

	void build_tree(std::vector<long long>& arr, int node, int start, int end) {
		if (start == end) {
			tree[node] = arr[start];
		}
		else {
			int mid = (start + end) / 2;

			build_tree(arr, node * 2, start, mid);
			build_tree(arr, node * 2 + 1, mid + 1, end);

			tree[node] = ((tree[node * 2] % MOD) * (tree[node * 2 + 1] % MOD)) % MOD;
		}
	}

	void update(std::vector<long long>& arr, int node, int start, int end, int idx, int val) {
		if (idx < start || idx > end) {
			return;
		}

		if (start == end) {
			arr[idx] = val;
			tree[node] = val;
		}
		else {
			int mid = (start + end) / 2;

			update(arr, node * 2, start, mid, idx, val);
			update(arr, node * 2 + 1, mid + 1, end, idx, val);

			tree[node] = ((tree[node * 2] % MOD) * (tree[node * 2 + 1] % MOD)) % MOD;
		}
	}

	long long query(int node, int start, int end, int left, int right) {
		if (left > end || right < start) {
			return 1;
		}

		if (left <= start && end <= right) {
			return tree[node];
		}

		int mid = (start + end) / 2;

		long long left_mul = query(node * 2, start, mid, left, right);
		long long right_mul = query(node * 2 + 1, mid + 1, end, left, right);

		return ((left_mul % MOD) * (right_mul % MOD)) % MOD;
	}

public:
	SegmentTree(std::vector<long long>& arr) {
		size = arr.size() - 1;
		tree.resize(size * 4);

		build_tree(arr, 1, 1, size);
	}

	void update_value(std::vector<long long>& arr, int idx, int val) {
		update(arr, 1, 1, size, idx, val);
	}

	long long get_mul(int left, int right) {
		return query(1, 1, size, left, right);
	}
};

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	int a, b, c;
	std::cin >> N >> M >> K;

	std::vector<long long> arr(N + 1);
	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];
	}

	SegmentTree* tree = new SegmentTree(arr);
	
	for (int i = 0; i < M + K; i++) {
		std::cin >> a >> b >> c;

		if (a == 1) {
			tree->update_value(arr, b, c);
		}
		else if (a == 2) {
			std::cout << tree->get_mul(b, c) << "\n";
		}
	}
}