#include "CMap.h"

CMap::CMap()
{
	c_x = 10;
	c_y = 10;
	m_x = 10;
	m_y = 10;
}

CMap::~CMap()
{

}

void CMap::mapping()
{
	system("mode con cols=141 lines=56");
	srand(time(NULL));
	int set_map = 420;	//값이 클수록 벽의 비율 줄어듦

	bool map[50][140];
	for (int y = 0; y < 50; y++) {
		for (int x = 0; x < 140; x++) {
			if (rand() % 1000 < set_map) {
				map[y][x] = true;
			}
			else {
				map[y][x] = false;
			}
		}
	}

	bool temp_map[50][140];

	for (int k = 0; k < 5; k++) {
		for (int y = 0; y < 50; y++) {
			for (int x = 0; x < 140; x++) {
				int count = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						int nx = x + i;
						int ny = y + j;

						if (i == 0 && j == 0) {
							//카운트하지 않음
						}

						else if (nx < 0 || ny < 0 || nx >= 140 || ny >= 50) {
							count = count + 1;
						}

						else if (map[ny][nx] != true) {
							count = count + 1;
						}
					}
				}
				if (count < 5) {
					temp_map[y][x] = true;
				}
				else {
					temp_map[y][x] = false;
				}
			}
		}

		for (int y = 0; y < 50; y++) {
			for (int x = 0; x < 140; x++) {
				map[y][x] = temp_map[y][x];
			}
		}

	}

	for (int y = 0; y < 50; y++) {
		for (int x = 0; x < 140; x++) {
			if (x == 0 || y == 0 || x == 139 || y == 49) {
				newMap[y][x] = '#';
			}
			else if (map[y][x] == true) {
				newMap[y][x] = ' ';
			}
			else {
				newMap[y][x] = '#';
			}
		}
	}

	int num_c = 0, num_m = 0;

	if (num_c == 0) {
		for (int y = 0; y < 50; y++) {
			for (int x = 0; x < 140; x++) {
				if (newMap[y][x] == ' ' && num_c == 0) {
					num_c += 1;
					newMap[y][x] = 'P';
					c_x = x;
					c_y = y;
				}
			}
		}
	}

	if (num_m == 0) {
		for (int y = 25; y < 50; y++) {
			if (newMap[y][70] == ' ' && num_m == 0) {
				num_m += 1;
				newMap[y][70] = 'M';
				m_x = 70;
				m_y = y;
			}
		}
	}

	if (num_m == 0) {
		for (int y = 25; y > 0; y--) {
			if (newMap[y][70] == ' ' && num_m == 0) {
				num_m += 1;
				newMap[y][70] = 'M';
				m_x = 70;
				m_y = y;
			}
		}
	}

}

void CMap::get_map()
{
	for (int y = 0; y < 50; y++) {
		for (int x = 0; x < 140; x++) {
			std::cout << newMap[y][x];
		}
		std::cout << '\n';
	}
}