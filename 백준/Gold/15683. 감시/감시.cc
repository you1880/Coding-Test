#include <iostream>
#include <vector>
#define MAX 9

struct CCTV {
	int r;
	int c;
	int type;

	CCTV(int _r, int _c, int _type)
		: r(_r), c(_c), type(_type) {}
};

std::vector<std::vector<int>> room(MAX, std::vector<int>(MAX, -1));
std::vector<CCTV> cctvs;
int dir[] = { 0, 1, 2, 3 };
int cctv_dir[9];
int N, M, size = 0, res = 0;

void left_view(std::vector<std::vector<int>>& tmp_room, int r, int c, int& area_size) {
	for (int i = c; i >= 1; i--) {
		if (tmp_room[r][i] == 6) {
			break;
		}

		if (tmp_room[r][i] == 0) {
			tmp_room[r][i] = 9;
			area_size--;
		}
	}
}

void right_view(std::vector<std::vector<int>>& tmp_room, int r, int c, int& area_size) {
	for (int i = c; i <= M; i++) {
		if (tmp_room[r][i] == 6) {
			break;
		}

		if (tmp_room[r][i] == 0) {
			tmp_room[r][i] = 9;
			area_size--;
		}
	}
}

void up_view(std::vector<std::vector<int>>& tmp_room, int r, int c, int& area_size) {
	for (int i = r; i >= 1; i--) {
		if (tmp_room[i][c] == 6) {
			break;
		}

		if (tmp_room[i][c] == 0) {
			tmp_room[i][c] = 9;
			area_size--;
		}
	}
}

void down_view(std::vector<std::vector<int>>& tmp_room, int r, int c, int& area_size) {
	for (int i = r; i <= N; i++) {
		if (tmp_room[i][c] == 6) {
			break;
		}

		if (tmp_room[i][c] == 0) {
			tmp_room[i][c] = 9;
			area_size--;
		}
	}
}

void check() {
	std::vector<std::vector<int>> tmp_room = room;
	int tmp_size = size;

	for (int i = 0; i < cctvs.size(); i++) {
		switch (cctvs[i].type) {
		case 1:
			if (cctv_dir[i] == 0) {
				left_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			else if (cctv_dir[i] == 1) {
				right_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			else if (cctv_dir[i] == 2) {
				up_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			else if (cctv_dir[i] == 3) {
				down_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			break;
		case 2:
			if (cctv_dir[i] == 0 || cctv_dir[i] == 2) {
				left_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				right_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			else if (cctv_dir[i] == 1 || cctv_dir[i] == 3) {
				up_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				down_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			break;
		case 3:
			if (cctv_dir[i] == 0) {
				right_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				up_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			else if (cctv_dir[i] == 1) {
				right_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				down_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			else if (cctv_dir[i] == 2) {
				left_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				down_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			else if (cctv_dir[i] == 3) {
				left_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				up_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			break;
		case 4:
			if (cctv_dir[i] == 0) {
				left_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				right_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				up_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			else if (cctv_dir[i] == 1) {
				right_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				up_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				down_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			else if (cctv_dir[i] == 2) {
				left_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				right_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				down_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			else if (cctv_dir[i] == 3) {
				left_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				down_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
				up_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			}
			break;
		case 5:
			left_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			right_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			up_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);
			down_view(tmp_room, cctvs[i].r, cctvs[i].c, tmp_size);

			break;
		}
	}

	res = res > tmp_size ? tmp_size : res;
}

void set_cctv_direction(int idx) {
	if (idx == cctvs.size()) {
		check();
		return;
	}

	for (int i = 0; i < 4; i++) {
		cctv_dir[idx] = dir[i];
		set_cctv_direction(idx + 1);
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			std::cin >> room[i][j];

			if (room[i][j] == 0) {
				size++;
			}
			else if (room[i][j] >= 1 && room[i][j] <= 5) {
				cctvs.push_back(CCTV(i, j, room[i][j]));
			}
		}
	}

	res = size;

	set_cctv_direction(0);

	std::cout << res;
}