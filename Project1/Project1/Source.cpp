#include <iostream>
#include <ctime>
#include "Maze.h"
using namespace std;

int main() {

	//Maze maze;
	//maze.GenerateRandomArray();

	Maze* maze = new Maze();
	maze->GenerateRandomArray();

	cout <<endl<<"�_�l���d :"<< endl;
	
	maze->PrintMaze();
	cout << endl;

	if (maze->visit(1,1)!= 2) {//�o��N�|����class�������|���G�ƾ�
		cout << "�S���X�f���|" << endl<<endl;
	}
	
	maze->PrintMaze();
	cout << endl;

	delete maze;
	//free(&maze);

	system("pause");
}