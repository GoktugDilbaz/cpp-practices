// BLG252E - HW1 - 23.10.2017
// Faik Göktuð Dilbaz
// 040150603

#include <cstdio>
#include <cstdlib>
#include "graphics.h"
#include <ctime>

const int WIDTH = 640, HEIGHT = 480;

class MovingRectangle{

	int pos_x, pos_y, vel_x, vel_y;
	int const width, height;

public:
	MovingRectangle();
	
	//x,y is needed, width and height have dafault values
	MovingRectangle(int, int, int = 25, int = 35);

	//


};

// Default Constructor
MovingRectangle::MovingRectangle() : width(30), height(20) { 
	pos_x = 100;
	pos_y = 40;
	vel_x = 4;
	vel_y = 5;
}

// Takes the absolute values just in case
MovingRectangle::MovingRectangle(int x, int y, int width, int height) : width(abs(width)), height(abs(height)) {
	pos_x = abs(x);
	pos_y = abs(y);
	srand(time(0));
	vel_x = rand() % 10;
	vel_y = rand() % 10;
}



int main(void)
{
	
	int GraphDriver = 0, GraphMode = 0;
	initgraph(&GraphDriver, &GraphMode, NULL, WIDTH, HEIGHT);
	//Opens the graphics window
	int x = 100, y = 40, width = 70, height = 50;
	printf("Burasi konsol ekrani..\n");
	outtext("Burasi grafik ekrani..\n");
	setcolor(GREEN);
	rectangle(x, y, x + width, y + height); // Draws the rectangle
	system("pause");


	return 0;
}

