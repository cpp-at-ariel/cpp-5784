#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct RGB {
  uint8_t red, green, blue;
};

struct Picture {
	int dimx, dimy;
	RGB* pixels;

	Picture(int dimx, int dimy): dimx(dimx), dimy(dimy), 
		pixels(new RGB[dimx*dimy]) {}

	RGB& at(int row, int col) {
		return pixels[(dimy-1-row)*dimx + col];
	}

	void setBackground(RGB color) {
		for (int i=0; i<dimx*dimy; ++i)
			pixels[i]=color;
	}

	void plotYAxis() {/* class exercise */}

	void toFile(string filename) const {
		ofstream imageFile(filename, ios::out | ios::binary);
		imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
  		imageFile.write(reinterpret_cast<char*>(pixels), 3*dimx*dimy);
		imageFile.close();
	}
	
	template<typename T> 
	void plot(
		T func, // Must have operator() (double)
		double fromX, double toX, int stepsX,
		double fromY, double toY,
		RGB color) {

		double stepX = (toX - fromX)/stepsX;
		for (double x=fromX; x<=toX; x+=stepX) {
			double y = func(x);  ///
			int col = (x-fromX)/(toX-fromX)*dimx;
			int row = (y-fromY)/(toY-fromY)*dimy;
			if (col>=0 && col<dimx && row>=0 && row<dimy)
				at(row,col) = color;
		}
	}

	// template<typename T> 
	// void plot_derivative(
	// 	T f, // Must have operator() (double)
	// 	double fromX, double toX, int stepsX,
	// 	double fromY, double toY,
	// 	RGB color, double h) {

	// 	double stepX = (toX - fromX)/stepsX;
	// 	for (double x=fromX; x<=toX; x+=stepX) {
	// 		double y = derivative_at_point(f,x,h);  ///
	// 		int col = (x-fromX)/(toX-fromX)*dimx;
	// 		int row = (y-fromY)/(toY-fromY)*dimy;
	// 		if (col>=0 && col<dimx && row>=0 && row<dimy)
	// 			at(row,col) = color;
	// 	}
	// }

};
