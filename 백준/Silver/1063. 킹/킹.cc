#include <iostream>
#include <vector>

int chess[8][8];
//R L B T RT LT RB LB
int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int kx, ky, sx, sy;

bool check(int _x, int _y) {
	if (_x < 0 || _y < 0 || _x >= 8 || _y >= 8) {
		return true;
	}
	return false;
}

void chess_stone(int _kx, int _ky, int _sx, int _sy) {
	if (check(_kx, _ky)) {
		return;
	}

	if (_kx == sx && _ky == sy) {
		if (check(_sx, _sy)) {
			return;
		}
		else {
			sx = _sx, sy = _sy;
			kx = _kx, ky = _ky;
		}
	}
	else {
		kx = _kx, ky = _ky;
	}
}

void move(std::string op) {
	int _kx = 0, _ky = 0, _sx = 0, _sy = 0;

	if (op == "R") {
		_kx = kx + dx[0], _ky = ky + dy[0];
		_sx = sx + dx[0], _sy = sy + dy[0];
	}
	else if (op == "L") {
		_kx = kx + dx[1], _ky = ky + dy[1];
		_sx = sx + dx[1], _sy = sy + dy[1];
	}
	else if (op == "B") {
		_kx = kx + dx[2], _ky = ky + dy[2];
		_sx = sx + dx[2], _sy = sy + dy[2];
	}
	else if (op == "T") {
		_kx = kx + dx[3], _ky = ky + dy[3];
		_sx = sx + dx[3], _sy = sy + dy[3];
	}
	else if (op == "RT") {
		_kx = kx + dx[4], _ky = ky + dy[4];
		_sx = sx + dx[4], _sy = sy + dy[4];
	}
	else if (op == "LT") {
		_kx = kx + dx[5], _ky = ky + dy[5];
		_sx = sx + dx[5], _sy = sy + dy[5];
	}
	else if (op == "RB") {
		_kx = kx + dx[6], _ky = ky + dy[6];
		_sx = sx + dx[6], _sy = sy + dy[6];
	}
	else if (op == "LB") {
		_kx = kx + dx[7], _ky = ky + dy[7];
		_sx = sx + dx[7], _sy = sy + dy[7];
	}
	chess_stone(_kx, _ky, _sx, _sy);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string k, s, op;
	int N;
	std::cin >> k >> s >> N;

	kx = k[1] - '0' - 1, ky = k[0] - 'A';
	sx = s[1] - '0' - 1, sy = s[0] - 'A';

	chess[kx][ky] = 1, chess[sx][sy] = 2;

	for (int i = 0; i < N; i++) {
		std::cin >> op;

		move(op);
	}
	
	std::cout << static_cast<char>(ky + 'A') << kx + 1 << "\n";
	std::cout << static_cast<char>(sy + 'A') << sx + 1;
}