#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

string MapGen();

void map()
{
	system(" mode  con   cols=141 ");
	srand(time(NULL));

	cout << MapGen();
}

string MapGen()
{
	int set_map = 420;	//���� Ŭ���� ���� ���� �پ��

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

	for (int k = 0; k < 10; k++) {
		for (int y = 0; y < 50; y++) {
			for (int x = 0; x < 140; x++) {
				int count = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						int nx = x + i;
						int ny = y + j;

						if (i == 0 && j == 0) {
							//ī��Ʈ���� ����
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

	string temp = "";

	for (int y = 0; y < 50; y++) {
		for (int x = 0; x < 140; x++) {
			//cout << map[y][x];			//���ڷ� ����
			if (x == 0 || y == 0 || x == 139 || y == 49) {
				temp += '#';
			}
			else if (map[y][x] == true) {	//���ڷ� ����
				temp += ' ';
			}
			else {
				temp += '#';
			}
		}
		temp += '\n';
	}

	return temp;
}