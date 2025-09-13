#include <iostream>
#include <vector>
#define MAX 100'001

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

			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}

	void update(std::vector<long long>& arr, int node, int start, int end, int idx, long long val) {
		if (idx < start || idx > end) {
			return;
		}

		if (start == end) {
			tree[node] = val;
			arr[idx] = val;
		}
		else {
			int mid = (start + end) / 2;

			update(arr, node * 2, start, mid, idx, val);
			update(arr, node * 2 + 1, mid + 1, end, idx, val);

			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}

	long long query(int node, int start, int end, int left, int right) {
		if (left > end || right < start) {
			return 0;
		}

		if (left <= start && end <= right) {
			return tree[node];
		}

		int mid = (start + end) / 2;

		long long left_query = query(node * 2, start, mid, left, right);
		long long right_query = query(node * 2 + 1, mid + 1, end, left, right);

		return left_query + right_query;
	}

public:
	SegmentTree(std::vector<long long>& arr) {
		size = arr.size() - 1;
		tree.resize(size * 4);

		build_tree(arr, 1, 1, size);
	}

	void update_value(std::vector<long long>& arr, int idx, long long val) {
		update(arr, 1, 1, size, idx, val);
	}

	void print_sum(int left, int right) {
		long long res = 0;
		if (left > right) {
			res = query(1, 1, size, right, left);
		}
		else {
			res = query(1, 1, size, left, right);
		}

		std::cout << res << "\n";
	}
};

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N, Q, x, y, a, b;
	std::cin >> N >> Q;

	std::vector<long long> arr(N + 1);
	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];
	}

	SegmentTree* seg = new SegmentTree(arr);

	for (int i = 0; i < Q; i++) {
		std::cin >> x >> y >> a >> b;

		seg->print_sum(x, y);
		seg->update_value(arr, a, b);
	}
}