/**
 * Writes a PPM image file.
 * 
 * Author: Erel Segal-Halevi.
 * Based on C code in RosettaCode: 
 * http://rosettacode.org/wiki/Category:C
 * 
 * Since: 2018-04
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;

int main() {
  const int dimx = 800, dimy = 800;
  for (int offset=0; offset<800; offset+=1) {  
    ofstream imageFile("image.simple.ppm");
    imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
    for (int j = 0; j < dimy; ++j)  {
      for (int i = 0; i < dimx; ++i) {
        char red =   i % 256;
        char green = j % 256;
        char blue = (offset*i+j)%256;//0;//int(64*sin(i)+256*cos(j))%256;  /* blue */
        imageFile << red << green << blue;
      }
    }
    imageFile.close();
    this_thread::sleep_for(chrono::seconds(1));
  }
  return 0;
}
