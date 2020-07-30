#include "GameOfLife.h"
#include <string>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
	Point(int xC, int yC) {
		this->x = xC;
		this->y = yC;
	}
};
enum Shape {
	Block = 1, 
	Boat = 2, 
	Blinker = 3, 
	Beacon = 4, 
	Pulsar = 5, 
	Pentadecathlon = 6, 
	Glider = 7
};
const int rows = 6;
const int cols = 6;
int grid[rows][cols];
int s;
int xC, yC;

void DrawShape(int Shape, int Xcoord, int Ycoord);
void DrawBlock(int Xcoord, int Ycoord);
void DrawBoat(int Xcoord, int Ycoord);
void DrawBlinker(int Xcoord, int Ycoord);
void DrawBeacon(int Xcoord, int Ycoord);
bool CheckFewerThan2CellsAround(int xC, int yC);
bool CheckAtleast2_3Cells(int xC, int yC);
bool CheckMoreThan3Cells(int xC, int yC);

void init();
void showMenu();
void printGrid();

int main()
{
	cout << "This application implements Conway's Game of Life." << endl;
	// write your implementation here for the user interaction part.
	init();
	showMenu();
	
	DrawShape(s, xC, yC);

	return 0;
}

void init() {
	for(int x=0;x<6;++x)
		for(int y=0;y<6;++y)
			grid[x][y] = 0;
}
void showMenu() {
	cout << "You can choose the form to display from this list: " << endl
		 << "Option 1 is for the Block" << endl
		 << "Option 2 is for the Boat" << endl
		 << "Option 3 is for the Blinker" << endl
		 << "Option 4 is for the Beacon " << endl
		 << "Option 5 is for the Pulsar " << endl
		 << "Option 6 is for the Pentadecathlon " << endl
		 << "Option 7 is for the Glider " << endl
		 << "Enter your option: ";
	cin >> s; //the option from user
	cout << "Now enter the start point of the shape (X, Y)." << endl
		 << "X: ";
	cin >> xC;
	cout << "Y: ";
	cin >> yC;
}
void printGrid() {
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 6; y++)
			cout << grid[x][y] << " ";
		cout << endl;
	}
}
// 0,0 is the reference point which is the top left point
void DrawBlock(int Xcoord, int Ycoord) {

	grid[Xcoord - 1][Ycoord - 1] = 1;
	grid[Xcoord][Ycoord - 1] = 1;
	grid[Xcoord - 1][Ycoord] = 1;
	grid[Xcoord][Ycoord] = 1;
}
void DrawBoat(int Xcoord, int Ycoord) {
	grid[Xcoord - 1][Ycoord - 1] = 1;
	grid[Xcoord][Ycoord - 1] = 1;
	grid[Xcoord - 1][Ycoord] = 1;
	grid[Xcoord][Ycoord+1] = 1;
	grid[Xcoord+1][Ycoord] = 1;
}
void DrawBlinker(int Xcoord, int Ycoord) {
	grid[Xcoord - 1][Ycoord - 1] = 1;
	grid[Xcoord - 1][Ycoord - 2] = 1;
	grid[Xcoord - 1][Ycoord - 0] = 1;

}
void DrawBeacon(int Xcoord, int Ycoord) {
	//top left part
	grid[Xcoord - 1][Ycoord - 1] = 1;
	grid[Xcoord][Ycoord - 1] = 1;
	grid[Xcoord - 1][Ycoord] = 1;
	//bottom right part
	grid[Xcoord + 2][Ycoord + 1] = 2;
	grid[Xcoord + 1][Ycoord + 2] = 2;
	grid[Xcoord + 2][Ycoord + 2] = 2;
}
void Redraw(int Iterations) {
	for(int i =0;i<Iterations;++i){
		vector<Point> vP;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
				if (grid[i][j] == 1)
					if (!CheckFewerThan2CellsAround(i, j)) {
						Point p(i, j);
						vP.push_back(p);
					}
		for (Point p : vP)
			grid[p.x][p.y] = 0;
		cout << endl;
		printGrid();
	}
}
bool CheckFewerThan2CellsAround(int xC,int yC) {
	int contor = 0;
	for (int row = xC-1; row < xC+2; ++row)
	{
		for (int col = yC-1; col < yC+2; ++col)
		{
			if (grid[row][col])
				contor++;
					
		}
	}
	return (contor-1)>=2;
}
void DrawShape(int Shape, int Xcoord, int Ycoord) {
	
	switch (Shape) {
	case Block: {
		DrawBlock(Xcoord, Ycoord);
		printGrid();
		Sleep(2000);
		break;
	}
	case Boat: {
		DrawBoat(Xcoord, Ycoord);
		printGrid();
		Sleep(2000);
		break;
	}
	case Blinker: {
		DrawBlinker(Xcoord, Ycoord);
		printGrid();
		Redraw(5);
		Sleep(10000);
		break;
	}
	case Beacon: {
		DrawBeacon(Xcoord, Ycoord);
		printGrid();
		Sleep(2000);
		
		break;
	}
	case Pulsar: {

	}
	case Pentadecathlon: {

	}
	case Glider: {

	}
	default: {
		cout << "Wrong figure input.";
		Sleep(2000);
		break;
	}
	}


}