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
using namespace std;

struct RGB {
  uint8_t red, green, blue, junk;
public:
  virtual void draw() { cout << "abc" << endl; }
  RGB(): red(0), green(0), blue(0) {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};



int main() {
  const int dimx = 800, dimy = 800;
  RGB* image = new RGB[dimx*dimy];
  // RGB image[dimx*dimy]; Segmentation fault
  for (int j = 0; j < dimy; ++j)  {  // row
    for (int i = 0; i < dimx; ++i) { // column
      int ii = (i*256/800);
      int jj = (j*256/800);
      image[dimx*j+i].red = ii % (256);
      image[dimx*j+i].green = jj % (256);
      image[dimx*j+i].blue = ( (ii*ii+jj*jj) % 256);
    }
  }

  ofstream imageFile("image3_virtual.ppm", ios::out | ios::binary);
  imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;

  imageFile.write((char*)(image), 3*dimx*dimy);   // logic error

  // How to fix the logic error without removing virtual:
  // for (int j = 0; j < dimy; ++j)  {  // row
  //   for (int i = 0; i < dimx; ++i) { // column
  //     imageFile.write((char*)(&image[dimx*j+i]), 3);
  //   }
  // }

  imageFile.close();
  return 0;
}
