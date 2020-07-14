#pragma once
#include <iostream>
using namespace std;
#define SIZE 30

class Maze {
public:

	//Maze Map
	//int Map[SIZE][SIZE];
	int Map[SIZE][SIZE] = {		{1, 1, 1, 1, 1, 1, 1},
								{1, 0, 0, 0, 0, 0, 1},
								{1, 0, 1, 0, 1, 0, 1},
								{1, 0, 0, 1, 0, 0, 1},
								{1, 1, 0, 1, 0, 1, 1},
								{1, 0, 0, 0, 0, 0, 1},
								{1, 1, 1, 1, 1, 1, 1} };
	int endX = SIZE - 2;
	int endY = SIZE - 2;
	void GenerateRandomArray();
	void PrintMaze();
	int visit(int , int );
private:

};