#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void map();

void map()
{
	system(" mode  con   cols=141 ");
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
	for (int y = 0; y < 50; y++) {
		for (int x = 0; x < 140; x++) {
			//cout << map[y][x];		//숫자로 보기

			if (map[y][x] == true) {	//문자로 보기
				cout << ' ';
			}
			else {
				cout << '#';
			}

		}
		cout << '\n';
	}
	cout << "\n\n\n";

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

		for (int y = 0; y < 50; y++) {
			for (int x = 0; x < 140; x++) {
				//cout << map[y][x];			//숫자로 보기
				if (x == 0 || y == 0 || x == 139 || y == 49) {
					cout << '#';
				}
				else if (map[y][x] == true) {	//문자로 보기
					cout << ' ';
				}
				else {
					cout << '#';
				}
			}
			cout << '\n';
		}
		cout << "\n\n\n";
	}

}