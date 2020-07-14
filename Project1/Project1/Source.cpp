#include <iostream>
#include <ctime>
#include "Maze.h"
using namespace std;

int main() {

	//Maze maze;
	//maze.GenerateRandomArray();

	Maze* maze = new Maze();
	maze->GenerateRandomArray();

	cout <<endl<<"起始關卡 :"<< endl;
	
	maze->PrintMaze();
	cout << endl;

	if (maze->visit(1,1)!= 2) {//這邊就會改變class內的路徑結果數據
		cout << "沒有出口路徑" << endl<<endl;
	}
	
	maze->PrintMaze();
	cout << endl;

	delete maze;
	//free(&maze);

	system("pause");
}