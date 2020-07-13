#include <iostream>
#include <ctime>
#include "Maze.h"


using namespace std;

void Maze::GenerateRandomArray() {

	//Random���Ͱg�c���e
	srand((unsigned)time(0));
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {

			Map[row][col] = (rand() % 2);//0���i�� 1����� ����q2�����L���|

			//�p�G�O�g�c��t�A�]�����
			if (row == 0 || col == SIZE - 1 || row == SIZE - 1 || col == 0) {
				Map[row][col] = 1;
			}
		}
	}
}

void Maze::PrintMaze() {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++)
			switch (Map[i][j])
			{
			case 0: cout << "  "; break;
			case 1: cout << "�i"; break;
			case 2: cout << "��";
			}
		printf("\n");
	}
}

int Maze::visit(int startX, int startY) {
	//�ثestart�I�i����
	if (Map[startX][startY] == 0 ) {
		Map[startX][startY] = 2;

		//�~�򩹤U�����A ���n�O�٨S�������B�S��k�~�򱴯��A�h�������u
		if (Map[endX][endY] == 0 &&

			!(visit(startX + 1, startY) ||
				visit(startX - 1, startY) ||
				visit(startX, startY + 1) ||
				visit(startX, startY - 1))) {
			//��������A�o�{�|�P���S�����F�A�������u

			Map[startX][startY] = 0;//�]�������L

			//print�X�^�Y�������|
			//cout << "( " << startY << " , " << startX << " )" << endl;

		}
	}
	else if (Map[endX][endY] == 1) {
		Map[startX][startY] = 0;
	}
	
	return Map[endX][endY];
}