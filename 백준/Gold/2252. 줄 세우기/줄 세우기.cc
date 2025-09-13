#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

int table[MAX];
std::vector<int> graph[MAX];
int N, M;

void topology_sort() {
	std::queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (table[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		int cur = q.front();
		q.pop();

		std::cout << cur << " ";
		for (int j = 0; j < graph[cur].size(); j++) {
			int next = graph[cur][j];
			if (--table[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int A, B;

	std::cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		std::cin >> A >> B;

		graph[A].push_back(B);
		table[B]++;
	}
	
	topology_sort();
}