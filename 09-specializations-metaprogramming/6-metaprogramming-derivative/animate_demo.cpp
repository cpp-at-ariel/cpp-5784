#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;

#include "rgb.hpp"


const int DELAY_IN_MILLISECONDS=200;
const char* PICTURE_FILENAME="func.ppm";

template<typename Function>
void animate(Picture& pic, Function f_x_t, 
	double fromX, double toX, int stepsX, 
	double fromY, double toY, 
	double fromT, double toT, int stepsT, 
	RGB background, RGB foreground) {
	double stepT = (toT - fromT)/stepsT;
	for (double t=fromT; t<=toT; t+=stepT) {
		pic.setBackground(background);
		auto f_x = [f_x_t=f_x_t, t=t]
			(double x){return f_x_t(x,t);};
		pic.plot(f_x, fromX, toX, stepsX, fromY, toY, foreground);
		pic.toFile(PICTURE_FILENAME);
	    this_thread::sleep_for(chrono::milliseconds(DELAY_IN_MILLISECONDS));
	}
}

int main() {
	Picture pic(300,300);
	auto f_x_t = [](double x, double t){
		return std::sin(x*t);
	};
	animate(pic, f_x_t, -4.0,4.0,1200,  -1.1,1.1, 0.5,2.5,100, {255,255,0}, {0,0,255});
	return 0;
}

