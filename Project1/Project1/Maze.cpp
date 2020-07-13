#include <iostream>
#include <ctime>
#include "Maze.h"


using namespace std;

void Maze::GenerateRandomArray() {

	//Random產生迷宮內容
	srand((unsigned)time(0));
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {

			Map[row][col] = (rand() % 2);//0為可走 1為牆壁 之後訂2為走過路徑

			//如果是迷宮邊緣，設為牆壁
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
			case 1: cout << "█"; break;
			case 2: cout << "◇";
			}
		printf("\n");
	}
}

int Maze::visit(int startX, int startY) {
	//目前start點可探索
	if (Map[startX][startY] == 0 ) {
		Map[startX][startY] = 2;

		//繼續往下探索， 但要是還沒探索完且沒辦法繼續探索，則取消路線
		if (Map[endX][endY] == 0 &&

			!(visit(startX + 1, startY) ||
				visit(startX - 1, startY) ||
				visit(startX, startY + 1) ||
				visit(startX, startY - 1))) {
			//滿足條件，發現四周都沒有路了，取消路線

			Map[startX][startY] = 0;//設為未走過

			//print出回頭取消路徑
			//cout << "( " << startY << " , " << startX << " )" << endl;

		}
	}
	else if (Map[endX][endY] == 1) {
		Map[startX][startY] = 0;
	}
	
	return Map[endX][endY];
}