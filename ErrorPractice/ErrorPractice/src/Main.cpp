#include <iostream>
#include "std_lib_facilities.h"
#include <>
using namespace std;
/*
int area(int length, int width)
{
	return length * width;
}

int framedArea(int x, int y)
{
	return area(x - 2, y - 2);
}

int main()
{
	int x = -1;
	int y = 2;
	int z = 4;

	int area1 = area(x, y);
	int area2 = framedArea(1, z);
	int area3 = framedArea(y, z);
	double ratio = double(area1) / area3;  // area3 will be 0. This will lead to instant crashing "Hardware violation"
}

// The caller deals with errors
int main()
{
	int x = -1;
	int y = 2;
	int z = 4;

	if (x <= 0 || y <= 0)error("non-positive area() argument");
		int area1 = area(x, y);

	if (z <= 2)
		error("non-positive 2nd area() argument called by framed_area()");
	int area2 = framedArea(1, z);

	if(y <= 2 || z <= 2)
		error("non-positive area() argument called by framed_area()");
	int area3 = framedArea(y, z);
	double ratio = double(area1) / area3;  
	//This example is fundamentally wrong being that it only works if we know exactly what the numbers are. We shouldn't have to know these details
} */

//The correct way to handle this error is the below method
/*int area(int length, int width)
{
	if (length <= 0 || width <= 0)error("non-positive area() argument");
	return length * width;
}


int framedArea(int x, int y)
{
	constexpr int frameWidth = 2;
	if (x - frameWidth <= 0 || y - frameWidth <= 0)
		error("non-positive area() argument called by framed_area()");
	return area(x - frameWidth, y - frameWidth);
}

int main()
{
	int x = -1;
	int y = 2;
	int z = 4;

	int area1 = area(x, y);
	int area2 = framedArea(1, z);
	int area3 = framedArea(y, z);
	double ratio = double(area1) / area3; 
}
*/

//TRY CATCH BLOCKS

int main()
	
try 
{
	//program here
	return 0; // 0 indicates success
}

catch (exception& e)
{
	cerr << "error: " << e.what() << "\n";
	keep_window_open();
	return 1; // 1 indicates failure
}
catch (...)
{
	cerr << "Unknows exception";
	keep_window_open();
	return 2; // 2 indicates failure
}
